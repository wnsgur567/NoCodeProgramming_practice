#pragma once

// https://www.youtube.com/watch?v=gqD1UqU7dts&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=10

// Remove nth from back

// 1 3 5 7 9 의 리스트에서 뒤에서 두번째 (n = 2) 인 노드를 삭제
// 7을 삭제하면 된다

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
	//auto _result = TwoPass_Counter(node1, 10);	// 3 5 7 9	/ size 보다 큰 값은 head를 삭제

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

// list의 크기를 먼저 구하고
// 해당 위치의 노드를 다시 순회해서 삭제
// = 2번 순회
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

	// while 종료시 count 는 리스트의 노드 개수
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

// 위와 동일하되
// 한번 더 순회하는 대신 노드를 array에 저장함
static ListNode<int>* Array(ListNode<int>* head, int target_from_back)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = head;
	ListNode<int>* curr = dummy;
	int count = 0;	// dummy를 포함한 카운트
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

// 두개의 node 를 사용하여 삭제 수행
static ListNode<int>* TwoNodes_OnePass(ListNode<int>* head, int target_from_back)
{
	ListNode<int>* dummy = new ListNode<int>(-1000);
	dummy->next = head;

	ListNode<int>* first = dummy;
	for (size_t i = 0; i < target_from_back; i++)
	{
		// target 이 size 보다 큰 경우
		if (IS_NULL(first->next)) {
			target_from_back = i;
			break;
		}
		first = first->next;
	}
	ListNode<int>* second = dummy;

	// 한칸씩 이동, first 가 마지막 노드에 도달하면 종료
	// 반복문 종료 후 second는 삭제할 노드의 전 노드의 위치임
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