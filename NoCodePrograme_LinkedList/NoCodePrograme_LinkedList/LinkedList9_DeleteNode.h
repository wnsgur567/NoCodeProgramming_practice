#pragma once

// https://www.youtube.com/watch?v=gqD1UqU7dts&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=10

// Remove nth from back

// 1 3 5 7 9 �� ����Ʈ���� �ڿ��� �ι�° (n = 2) �� ��带 ����
// 7�� �����ϸ� �ȴ�

#include"LinkedList1_base.h"

ListNode<int>* Recursive(ListNode<int>*, int&, int);
ListNode<int>* TwoPass_Counter(ListNode<int>*, int);
ListNode<int>* Array(ListNode<int>*, int);
ListNode<int>* TwoNodes_OnePass(ListNode<int>*, int);

void LinkedList9_Delete()
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

	//auto _result = TwoPass_Counter(node1, 2);		// 1 3 5 9
	//auto _result = TwoPass_Counter(node1, 10);	// 3 5 7 9	/ size ���� ū ���� head�� ����

	//auto _result = Array(node1, 2);					// 1 3 5 9
	//auto _result = Array(node1, 10);					// 3 5 7 9

	//auto _result = TwoNodes_OnePass(node1, 2);
	auto _result = TwoNodes_OnePass(node1, 10);
	PrintAll(_result);

	auto curr = _result;
	while (!IS_NULL(curr))
	{
		auto deletenode = curr;
		curr = curr->next;
		delete deletenode;
	}
}



static ListNode<int>* Recursive(ListNode<int>* head, int& count, int target_from_back)
{

}

// list�� ũ�⸦ ���� ���ϰ�
// �ش� ��ġ�� ��带 �ٽ� ��ȸ�ؼ� ����
// = 2�� ��ȸ
static ListNode<int>* TwoPass_Counter(ListNode<int>* head, int target_from_back)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = head;
	ListNode<int>* curr = dummy->next;
	int count = 0;
	while (!IS_NULL(curr))
	{
		++count;
		curr = curr->next;
	}

	// while ����� count �� ����Ʈ�� ��� ����
	// count - target = delete index
	int index = count - target_from_back;
	ListNode<int>* before = dummy;
	curr = dummy->next;	//head
	for (int i = 0; i < index; i++)
	{
		before = curr;
		curr = curr->next;
	}
	before->next = curr->next;
	delete curr;

	ListNode<int>* ret = dummy->next;
	delete dummy;
	return ret;
}

// ���� �����ϵ�
// �ѹ� �� ��ȸ�ϴ� ��� ��带 array�� ������
static ListNode<int>* Array(ListNode<int>* head, int target_from_back)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = head;
	ListNode<int>* curr = dummy;
	int count = 0;	// dummy�� ������ ī��Ʈ
	while (!IS_NULL(curr))
	{
		++count;
		curr = curr->next;
	}

	ListNode<int>** arr = new ListNode<int>*[count];
	curr = dummy;
	for (size_t i = 0; i < count; i++)
	{
		arr[i] = curr;
		curr = curr->next;
	}

	int index = count - target_from_back;

	if (index < 1)
		index = 1;

	arr[index - 1]->next = arr[index]->next;
	delete arr[index];

	auto ret = dummy->next;
	delete dummy;
	delete[] arr;

	return ret;
}

// �ΰ��� node �� ����Ͽ� ���� ����
static ListNode<int>* TwoNodes_OnePass(ListNode<int>* head, int target_from_back)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = head;

	ListNode<int>* first = dummy;
	for (size_t i = 0; i < target_from_back; i++)
	{
		// target �� size ���� ū ���
		if (IS_NULL(first->next)) {
			target_from_back = i;
			break;
		}
		first = first->next;
	}
	ListNode<int>* second = dummy;

	// ��ĭ�� �̵�, first �� ������ ��忡 �����ϸ� ����
	// �ݺ��� ���� �� second�� ������ ����� �� ����� ��ġ��
	while (!IS_NULL(first->next))
	{
		first = first->next;
		second = second->next;
	}

	auto deleteNode = second->next;
	second->next = deleteNode->next;

	auto ret = dummy->next;
	delete dummy;
	return ret;
}