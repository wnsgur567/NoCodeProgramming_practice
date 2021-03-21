#pragma once

#include"LinkedList1_base.h"

ListNode<int>* RemoveRecursive(ListNode<int>* head, int findValue);
void RemoveIterative(ListNode<int>* head, int findValue);
void LinkedList2_RemoveElemets()
{
	// 1 5 6 8 2 3 5 6 8 4 3 3 2 5 3
	LinkedList<int> list1;
	list1.AddBack(new ListNode<int>(1));
	list1.AddBack(new ListNode<int>(5));
	list1.AddBack(new ListNode<int>(6));
	list1.AddBack(new ListNode<int>(8));
	list1.AddBack(new ListNode<int>(2));
	list1.AddBack(new ListNode<int>(3));
	list1.AddBack(new ListNode<int>(5));
	list1.AddBack(new ListNode<int>(6));
	list1.AddBack(new ListNode<int>(8));
	list1.AddBack(new ListNode<int>(4));
	list1.AddBack(new ListNode<int>(3));
	list1.AddBack(new ListNode<int>(3));
	list1.AddBack(new ListNode<int>(2));
	list1.AddBack(new ListNode<int>(5));
	list1.AddBack(new ListNode<int>(3));


	//ListNode<int>* resultHead = RemoveRecursive(list1.head, 3);
	RemoveIterative(list1.head, 3);
	list1.Print();
}




/// <summary>
/// ��ͷ� ����
/// </summary>
/// <returns> next ��带 ���� </returns>
static ListNode<int>* RemoveRecursive(ListNode<int>* head, int findValue)
{
	ListNode<int>* afterNode = nullptr;
	if(head->next != nullptr)
		afterNode = RemoveRecursive(head->next, findValue);
	
	// ã�� ���� ��ġ�ϸ�
	if (head->value == findValue)
	{
		// �ڱ� �ڽ��� �����
		delete head;
		return afterNode;
	}
	head->next = afterNode;
	return head;
}

static void RemoveIterative(ListNode<int>* head, int findValue)
{
	ListNode<int>* dummy = new ListNode<int>(-10000);
	dummy->next = head;

	ListNode<int>* before = dummy;
	ListNode<int>* curr = head;
	while (curr != nullptr)
	{
		if (curr->value == findValue)
		{
			before->next = curr->next;
			delete curr;			
			curr = before->next;
			continue;
		}
		before = curr;
		curr = curr->next;
	}

	delete dummy;
}