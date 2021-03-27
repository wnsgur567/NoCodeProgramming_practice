#pragma once

// https://www.youtube.com/watch?v=BcSW08VWYVE&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=11

#include"LinkedList1_base.h"
#define DELETED 0xdddddddd

// 1. partition
// �Ʒ� ����Ʈ�� x = 5�� �������� �ΰ��� ����Ʈ�� ������
//			1: x < 5 �� ����Ʈ
//			2: x >= 5 �� ����Ʈ
//			3: 1������Ʈ�� tail�� x>=5 ����Ʈ�� head�� ���� 

// 1 7 5 3 6 3
ListNode<int>* Partition(ListNode<int>* head, int seperator);
void LinkedList10_Partition()
{
	ListNode<int>* node1 = new ListNode<int>(1);
	ListNode<int>* node2 = new ListNode<int>(7);
	ListNode<int>* node3 = new ListNode<int>(5);
	ListNode<int>* node4 = new ListNode<int>(3);
	ListNode<int>* node5 = new ListNode<int>(6);
	ListNode<int>* node6 = new ListNode<int>(3);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	auto _result = Partition(node1, 5);
	PrintAll(_result);

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
}

static ListNode<int>* Partition(ListNode<int>* head, int seperator)
{
	if (IS_NULL(head))
		return nullptr;
	ListNode<int>* dummy_little = new ListNode<int>(-1100);	// seperator �̸�
	ListNode<int>* dummy_big = new ListNode<int>(-1000);	// seperator �̻�

	auto curr = head;
	auto curr_little = dummy_little;
	auto curr_big = dummy_big;
	while (!IS_NULL(curr))
	{
		if (curr->value < seperator)
		{
			curr_little->next = curr;
			curr_little = curr_little->next;
		}
		else
		{
			curr_big->next = curr;
			curr_big = curr_big->next;
		}
		curr = curr->next;
	}

	// �� ����Ʈ �����ϱ�
	curr_little->next = dummy_big->next;
	curr_big->next = nullptr;

	auto ret = dummy_little->next;
	delete dummy_little;
	delete dummy_big;
	return ret;
}


// 2. reorder

// 1 3 5 7 9 �� 1 9 3 7 5 �� ���� �������� �� ����
// 
// middle �� ã�Ƽ� ������
// �Ĺ� ����Ʈ�� reverse ���Ѽ�
// re order ��Ŵ



static ListNode<int>* GetMiddle(ListNode<int>* _head)
{
	ListNode<int>* fast = _head;	//2ĭ�ε�
	ListNode<int>* slow = _head;	//1ĭ�̵�

	while ((!IS_NULL(fast)) && (!IS_NULL(fast->next)))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


static ListNode<int>* ReverseRecurr(ListNode<int>* _node)
{
	if (IS_NULL(_node->next))
		return _node;

	auto retnode = ReverseRecurr(_node->next);		// ���ο� head�� ���ϵ�
	_node->next->next = _node;
	_node->next = nullptr;
	return retnode;
}

static ListNode<int>* Reverse(ListNode<int>* _node)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = _node;
	auto ret = ReverseRecurr(dummy);
	delete dummy;
	return ret;
}

static ListNode<int>* ReOrder(ListNode<int>* _head)
{
	auto middle_node = GetMiddle(_head);		// 5

	// �� ����Ʈ�� ���
	auto preList_head = _head;
	auto postList_head = middle_node->next;
	middle_node->next = nullptr;

	auto  postList_Reversed = Reverse(postList_head);
	//PrintAll(postList_Reversed); // test print

	ListNode<int>* dummy = new ListNode<int>(-1000);
	auto iter = dummy;
	auto curr1 = _head;
	auto curr2 = postList_Reversed;
	int flag = 0;
	while (true)
	{
		if (!IS_NULL(curr1))
		{
			iter->next = curr1;
			iter = iter->next;
			curr1 = curr1->next;
		}
		else
			++flag;
		if (!IS_NULL(curr2))
		{
			iter->next = curr2;
			iter = iter->next;
			curr2 = curr2->next;
		}
		else
			++flag;
		if (flag == 2)
			break;
		flag = 0;
	}
	auto ret = dummy->next;
	delete dummy;
	return ret;
}

void LinkedList10_ReOrder()
{
	auto node1 = new ListNode<int>(1);
	auto node2 = new ListNode<int>(3);
	auto node3 = new ListNode<int>(5);
	auto node4 = new ListNode<int>(7);
	auto node5 = new ListNode<int>(9);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	auto _result = ReOrder(node1);
	PrintAll(_result);

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
}