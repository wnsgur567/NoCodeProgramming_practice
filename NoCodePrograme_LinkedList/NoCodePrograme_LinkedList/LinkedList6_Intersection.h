#pragma once

//https://www.youtube.com/watch?v=ubc9wPvwW-4&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=7

#include"LinkedList1_base.h"
#include<unordered_set>

// 아래 7 9 공유 노드
// 1 3 5 7 9
//	   2 7 9	

const ListNode<int>* GetIntersection(const ListNode<int>* _node1, const ListNode<int>* _node2);
const ListNode<int>* GetIntersection_v2(const ListNode<int>* _node1, const ListNode<int>* _node2);

void LinkedList6_Intersection()
{
	auto node1 = new ListNode<int>(1);
	auto node2 = new ListNode<int>(3);
	auto node3 = new ListNode<int>(5);
	auto node4 = new ListNode<int>(7);
	auto node5 = new ListNode<int>(9);
	auto node6 = new ListNode<int>(2);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node6->next = node4;

	// node1 이 head 1
	// node6 이 head 2
	auto _intersection = GetIntersection(node1, node6);
	cout << *_intersection << endl;

	auto _intersection_v2 = GetIntersection_v2(node1, node6);
	cout << *_intersection_v2 << endl;

	
	auto node10 = new ListNode<int>(1);
	auto node20 = new ListNode<int>(3);
	auto node30 = new ListNode<int>(5);
	auto node40 = new ListNode<int>(7);
	node10->next = node20;
	node20->next = node30;
	node30->next = node40;

	auto node50 = new ListNode<int>(2);
	auto node60 = new ListNode<int>(4);
	node50->next = node60;

	auto _test = GetIntersection_v2(node10, node50);
	if (_test == nullptr)
		cout << "nullptr" << endl;	

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node10;
	delete node20;
	delete node30;
	delete node40;
	delete node50;
	delete node60;
}

static const ListNode<int>* GetIntersection(const ListNode<int>* _node1, const ListNode<int>* _node2)
{
	auto curr1 = _node1;
	auto curr2 = _node2;
	
	std::unordered_set<const ListNode<int>*> _set;

	while (curr1 != nullptr)
	{
		_set.insert(curr1);
		curr1 = curr1->next;
	}

	while (curr2 != nullptr)
	{
		// 동일한 노드를 찾으면
		if (_set.find(curr2) != _set.end())
			return curr2;
		curr2 = curr2->next;
	}
	return nullptr;
}


// 이건 좀 신기햇네
static const ListNode<int>* GetIntersection_v2(const ListNode<int>* _node1, const ListNode<int>* _node2)
{
	auto curr1 = _node1;
	auto curr2 = _node2;

	int cnt = 0;	// 교차되지 않는 리스트면 out

	while (true)
	{
		curr1 = curr1->next;
		if (curr1 == nullptr)
		{
			curr1 = _node2;
			if (++cnt > 1)
				return nullptr;
		}
		curr2 = curr2->next;
		if (curr2 == nullptr)
		{
			curr2 = _node1;			
		}			

		if (curr1 == curr2)
			return curr1;
	}
}