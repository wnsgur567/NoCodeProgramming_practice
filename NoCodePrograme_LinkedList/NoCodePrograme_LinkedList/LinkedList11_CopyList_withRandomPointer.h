#pragma once

// https://www.youtube.com/watch?v=Iey7z4Xv5m4&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=12

// https://www.youtube.com/watch?v=Iey7z4Xv5m4&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=12
// ���� �ʿ�
// ��� 2�� �� ����

// 1 3 5 7 9
// random ptr
// 1 5, 3 1 , 5 7 , 7 null, 9 5

// deep copy �� ��

template<typename T>
class RNode
{
public:
	RNode* n;	// next
	RNode* r;	// random
	T value;
public:
	RNode() :n(nullptr), r(nullptr), value(T()) {}
	RNode(T _value) :n(nullptr), r(nullptr), value(_value) {}
};


RNode<int>* Copy(RNode<int>* node);
RNode<int>* Copy2(RNode<int>* node);

void LinkedList11_Copy()
{
	RNode<int>* node1 = new RNode<int>(1);
	RNode<int>* node2 = new RNode<int>(3);
	RNode<int>* node3 = new RNode<int>(5);
	RNode<int>* node4 = new RNode<int>(7);
	RNode<int>* node5 = new RNode<int>(9);

	// next
	// 1 3 5 7 9
	node1->n = node2;
	node2->n = node3;
	node3->n = node4;
	node4->n = node5;
	// random
	// 1 5, 3 1 , 5 7 , 7 null, 9 5
	node1->r = node3;	// 1 5
	node2->r = node1;	// 3 1
	node3->r = node4;	// 5 7
	node5->r = node3;	// 9 5

	//auto _result = Copy(node1);
	auto _result = Copy2(node1);
	auto curr = node1;
	while (!IS_NULL(curr))
	{
		int value1 = curr->value;
		int value2 = (curr->n == nullptr) ? 0 : curr->n->value;
		int value3 = (curr->r == nullptr) ? 0 : curr->r->value;
		printf("value : %d, next : %d , random next : %d\n",
			value1, value2, value3);
		curr = curr->n;
	}cout << endl;

	curr = _result;
	while (!IS_NULL(curr))
	{
		int value1 = curr->value;
		int value2 = (curr->n == nullptr) ? 0 : curr->n->value;
		int value3 = (curr->r == nullptr) ? 0 : curr->r->value;
		printf("value : %d, next : %d , random next : %d\n",
			value1, value2, value3);
		curr = curr->n;
	}cout << endl;



	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
}

#include<map>
// ����� ���� �����͸�
// �����Ͽ� ���� ����
static RNode<int>* Copy(RNode<int>* node)
{
	if (IS_NULL(node))
		return nullptr;

	// ������ copy �� ����Ʈ�� ���� ���
	auto dummy = new RNode<int>(-1000);

	//			original , copy
	std::map<RNode<int>*, RNode<int>*> _map;

	auto curr = node;
	auto cuur_copy = dummy;
	while (!IS_NULL(curr))
	{
		// deepcopy ��� �����ϰ�
		auto deepcopy = new RNode<int>(curr->value);
		cuur_copy->n = deepcopy;
		cuur_copy = cuur_copy->n;
		// ���� �����ʹ� �����ϰ�
		_map[curr] = deepcopy;

		curr = curr->n;
	}

	// �� ��ȯ�ϸ鼭 copy ����Ʈ�� randomptr��ũ �������ֱ�
	curr = node;
	cuur_copy = dummy->n;
	while (!IS_NULL(curr))
	{
		cuur_copy->r = _map[curr->r];
		cuur_copy = cuur_copy->n;
		curr = curr->n;
	}
	auto ret = dummy->n;
	delete dummy;
	return ret;
}

static RNode<int>* Copy2(RNode<int>* node)
{
	if (IS_NULL(node))
		return nullptr;


	// ��� ���� �� ��ũ
	auto curr = node;
	while (!IS_NULL(curr))
	{
		auto next = curr->n;
		curr->n = new RNode<int>(curr->value);
		curr->n->n = next;
		curr = next;
	}

	// ��ȸ�ϸ鼭 random ������ ��ũ
	curr = node;
	while (!IS_NULL(curr))
	{
		auto copied = curr->n;
		if (!IS_NULL(curr->r))
		{
			auto copied_next = curr->r->n;
			copied->r = copied_next;
		}			
		curr = curr->n->n;
	}

	// ��ũ ����
	auto dummy = new RNode<int>(-1000);

	curr = node;
	auto copied_curr = dummy;
	while (!IS_NULL(curr))
	{
		auto next = curr->n->n;
		copied_curr->n = curr->n;
		curr->n = next;
		curr = next;
		copied_curr = copied_curr->n;
	}

	auto ret = dummy->n;
	delete dummy;
	return ret;
}