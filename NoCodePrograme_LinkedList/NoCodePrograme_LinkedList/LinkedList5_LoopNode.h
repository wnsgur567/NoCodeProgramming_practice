#pragma once

#include"LinkedList1_base.h"
#include<unordered_set>

const ListNode<int>* Find_LoopNode(const ListNode<int>* _node);
bool Find_LoopNode_v2(const ListNode<int>* _node);

// ���⼭�� ����Ʈ Ŭ������ ������� �ʰ�...
void LinkedList5_Loop()
{
	auto node1 = new ListNode<int>(1);
	auto node2 = new ListNode<int>(2);
	auto node3 = new ListNode<int>(3);
	auto node4 = new ListNode<int>(4);
	auto node5 = new ListNode<int>(5);
	auto node6 = new ListNode<int>(6);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	// loop
	node6->next = node3;

	auto loop = Find_LoopNode(node1);
	cout << "loop node : " << *loop << endl;

	bool isLoop = Find_LoopNode_v2(node1);
	cout << (isLoop ? "loop" : "none") << endl;

	auto node10 = new ListNode<int>(10);

	bool isLoop2 = Find_LoopNode_v2(node10);
	cout << (isLoop2 ? "loop" : "is not loop") << endl;

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
}

// �⺻���� ���
static const ListNode<int>* Find_LoopNode(const ListNode<int>* _node)
{
	if (_node == nullptr)
		return nullptr;

	const ListNode<int>* curr = _node;
	std::unordered_set<const ListNode<int>*> _set;
	while (curr != nullptr)
	{
		if (_set.find(curr) != _set.end())
			return curr;
		_set.insert(curr);
		curr = curr->next;			
	}
	return nullptr;
}

// fast �� slow �̿�
// ��� �ݺ����� ������ ����
// fast �� slow ��尡 ��ġ�Ǵ� ������ �����µ� ���� �Ǻ�����
// � ������� �Ǻ� �Ұ���
static bool Find_LoopNode_v2(const ListNode<int>* _node)
{
	if (_node == nullptr)
		return false;

	auto slow = _node;
	auto fast = _node;

	while (slow == fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast == nullptr)
			return false;
		fast = fast->next;
		if (fast == nullptr)
			return false;
	}

	return true;
}