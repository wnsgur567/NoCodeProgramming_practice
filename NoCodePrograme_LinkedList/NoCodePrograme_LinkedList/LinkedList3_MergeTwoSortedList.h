#pragma once

#include"LinkedList1_base.h"

// �Ʒ� �� ����Ʈ�� �ϳ��� ��ġ��
// 1 - 3 - 5
// 1 - 2 - 3 - 4

ListNode<int>* MergeList_Recursive(ListNode<int>* node1, ListNode<int>* node2);
void MergeList_Iterative(const LinkedList<int>& list1, const LinkedList<int>& list2, LinkedList<int>& outputList);

// �ݵ�� ������������ �����ؾ� ��
void LinkedList2_Merge()
{
	LinkedList<int> list1;
	list1.AddBack(new ListNode<int>(1));
	list1.AddBack(new ListNode<int>(3));
	list1.AddBack(new ListNode<int>(5));
	LinkedList<int> list2;
	list2.AddBack(new ListNode<int>(1));
	list2.AddBack(new ListNode<int>(2));
	list2.AddBack(new ListNode<int>(3));
	list2.AddBack(new ListNode<int>(4));


	//LinkedList<int> output;
	//MergeList_Iterative(list1, list2, output);
	//output.Print();

	ListNode<int>* output_head;
	output_head = MergeList_Recursive(list1.head, list2.head);
	while (output_head != nullptr)
	{
		cout << *output_head << ' ';
		output_head = output_head->next;
	}
	// ���� outpu_head�� �����ϴ� ����Ʈ ������ �ڵ�
	cout << endl;
}

static ListNode<int>* MergeList_Recursive(ListNode<int>* node1, ListNode<int>* node2)
{
	if (node1 == nullptr && node2 == nullptr)
		return nullptr;

	ListNode<int>* next;
	ListNode<int>* newNode;

	if (node1 == nullptr)
	{
		next = MergeList_Recursive(node1, node2->next);
		newNode = new ListNode<int>(node2->value);
		newNode->next = next;
		return newNode;
	}
	else if (node2 == nullptr)
	{
		next = MergeList_Recursive(node1->next, node2);
		newNode = new ListNode<int>(node1->value);
		newNode->next = next;
		return newNode;
	}
	else if (node1->value < node2->value)
	{
		next = MergeList_Recursive(node1->next, node2);
		newNode = new ListNode<int>(node1->value);
		newNode->next = next;
		return newNode;
	}
	else
	{
		next = MergeList_Recursive(node1, node2->next);
		newNode = new ListNode<int>(node2->value);
		newNode->next = next;
		return newNode;
	}
}


// ���� �� �����ϵ��� ��
// ����Ʈ�� ���� ���� �����ڸ� �ȸ���� �J�ŵ�
static void MergeList_Iterative(const LinkedList<int>& list1, const LinkedList<int>& list2, LinkedList<int>& outputList)
{
	ListNode<int>* curr1 = list1.head;
	ListNode<int>* curr2 = list2.head;

	// size üũ
	if (list2.size == 0)
	{
		for (size_t i = 0; i < list1.size; i++)
		{
			outputList.AddBack(new ListNode<int>(curr1->value));
			curr1 = curr1->next;
		}
		return;
	}
	if (list1.size == 0)
	{
		for (size_t i = 0; i < list2.size; i++)
		{
			outputList.AddBack(new ListNode<int>(curr2->value));
			curr2 = curr2->next;
		}
		return;
	}

	// ��ü
	while (true)
	{
		if (curr1 == nullptr && curr2 == nullptr)
		{
			// ����
			return;
		}
		if (curr1 == nullptr)
		{
			outputList.AddBack(new ListNode<int>(curr2->value));
			curr2 = curr2->next;
			continue;
		}
		if (curr2 == nullptr)
		{
			outputList.AddBack(new ListNode<int>(curr1->value));
			curr1 = curr1->next;
			continue;
		}

		if (curr1->value < curr2->value)
		{
			outputList.AddBack(new ListNode<int>(curr1->value));
			curr1 = curr1->next;
		}
		else
		{
			outputList.AddBack(new ListNode<int>(curr2->value));
			curr2 = curr2->next;
		}
	}
}