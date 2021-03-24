#pragma once

#include"LinkedList1_base.h"

// 리스트의 중간지점 찾기
//	1	3	5	7	9	=>  5
//	1	2	3	4		=>	3

ListNode<int>* Find_MiddleNode(const LinkedList<int>& _list);
ListNode<int>* Find_MidlleNode_v2(const LinkedList<int>& _list);

void LinkedList4_Middle()
{
	LinkedList<int> list1;
	list1.AddBack(new ListNode<int>(1));
	list1.AddBack(new ListNode<int>(3));
	list1.AddBack(new ListNode<int>(5));
	list1.AddBack(new ListNode<int>(7));
	list1.AddBack(new ListNode<int>(9));

	LinkedList<int> list2;
	list2.AddBack(new ListNode<int>(1));
	list2.AddBack(new ListNode<int>(2));
	list2.AddBack(new ListNode<int>(3));
	list2.AddBack(new ListNode<int>(4));

	// 5
	ListNode<int>* result1 = Find_MidlleNode_v2(list1);
	cout << "Result1 : " << *result1 << endl;

	// 3
	ListNode<int>* result2 = Find_MidlleNode_v2(list2);
	cout << "Result2 : " << *result2 << endl;

	// test
	LinkedList<int> list3;
	list3.AddBack(new ListNode<int>(1));
	ListNode<int>* result3 = Find_MidlleNode_v2(list3);
	cout << "Result3 : " << *result3 << endl;
}

// 기본적인 간단한 방법
ListNode<int>* Find_MiddleNode(const LinkedList<int>& _list)
{
	if (_list.size == 0)
		return nullptr;
	if (_list.size == 1)
		return _list.head;

	int middle_index = static_cast<int>(_list.size / 2);
	ListNode<int>* curr = _list.head;
	for (size_t i = 0; i < middle_index; i++)
	{
		curr = curr->next;
	}
	return curr;
}

// slow 와 fast 두개의 currentNode를 사용하여 구현하는 방법
// fast가 마지막 노드까지 이동했을 때 
// slow 노드의 위치가 middle 노드의 위치임
ListNode<int>* Find_MidlleNode_v2(const LinkedList<int>& _list)
{
	if (_list.size == 0)
		return nullptr;
	if (_list.size == 1)
		return _list.head;

	ListNode<int>* slow;	// 1칸(next)		  이동
	ListNode<int>* fast;	// 2칸(next next) 이동

	slow = _list.head;
	fast = _list.head;
	
	while (true)
	{			
		// slow 이동
		slow = slow->next;

		// fast 이동
		fast = fast->next->next;	
		if (fast == nullptr || fast->next == nullptr)
			return slow;
	}	
}