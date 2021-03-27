#pragma once

// https://www.youtube.com/watch?v=Iey7z4Xv5m4&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=12

// https://www.youtube.com/watch?v=Iey7z4Xv5m4&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=12
// 맵핑 필요
// 방법 2는 좀 복잡

// 1 3 5 7 9
// random ptr
// 1 5, 3 1 , 5 7 , 7 null, 9 5

// deep copy 할 것

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
// 복사시 랜덤 포인터를
// 맵핑하여 복사 수행
static RNode<int>* Copy(RNode<int>* node)
{
	if (IS_NULL(node))
		return nullptr;

	// 새로이 copy 할 리스트의 더미 노드
	auto dummy = new RNode<int>(-1000);

	//			original , copy
	std::map<RNode<int>*, RNode<int>*> _map;

	auto curr = node;
	auto cuur_copy = dummy;
	while (!IS_NULL(curr))
	{
		// deepcopy 노드 생성하고
		auto deepcopy = new RNode<int>(curr->value);
		cuur_copy->n = deepcopy;
		cuur_copy = cuur_copy->n;
		// 랜덤 포인터는 매핑하고
		_map[curr] = deepcopy;

		curr = curr->n;
	}

	// 재 순환하면서 copy 리스트의 randomptr링크 설정해주기
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


	// 노드 생성 및 링크
	auto curr = node;
	while (!IS_NULL(curr))
	{
		auto next = curr->n;
		curr->n = new RNode<int>(curr->value);
		curr->n->n = next;
		curr = next;
	}

	// 순회하면서 random 포인터 링크
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

	// 링크 끊기
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