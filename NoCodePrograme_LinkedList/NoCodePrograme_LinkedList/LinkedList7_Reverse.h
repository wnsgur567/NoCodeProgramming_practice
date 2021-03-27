#pragma once

#include"LinkedList1_base.h"
#include<stack>
//  https://www.youtube.com/watch?v=f9MeOHgU0ks&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=8&ab_channel=%EC%BD%94%EB%93%9C%EC%97%86%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D

ListNode<int>* Iterative(ListNode<int>* node);
ListNode<int>* Recursive(ListNode<int>* node);
ListNode<int>* Recursive2(ListNode<int>* node);
void LinkedList7_Reverse()
{
	ListNode<int>* node1 = new ListNode<int>(1);
	ListNode<int>* node2 = new ListNode<int>(3);
	ListNode<int>* node3 = new ListNode<int>(5);
	ListNode<int>* node4 = new ListNode<int>(7);
	ListNode<int>* node5 = new ListNode<int>(9);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	auto ret_iter = Iterative(node1);
	PrintAll(ret_iter);

	//auto ret_recur = Recursive(ret_iter);
	//PrintAll(node1);

	auto ret_recur = Recursive2(ret_iter);
	PrintAll(ret_recur);

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
}

static ListNode<int>* Iterative(ListNode<int>* node)
{
	if (IS_NULL(node))
		return nullptr;

	std::stack<ListNode<int>*> _stack;
	auto curr = node;
	while (true)
	{
		_stack.push(curr);
		curr = curr->next;
		if (curr->next == nullptr)
			break;
	}

	auto retNode = curr;

	while (true)
	{
		if (_stack.empty())
		{
			curr->next = nullptr;
			return retNode;	// 새로운 헤드
		}
		auto _tmp = _stack.top();
		_stack.pop();

		curr->next = _tmp;
		curr = _tmp;
	}

	return nullptr;
}

// 이렇게 하면 ret값으로 head가 안나오자너
// parameter 값으로 , output 전용 노드 하나 파야됨
static ListNode<int>* Recursive(ListNode<int>* node)
{
	if (IS_NULL(node->next))
		return node;

	auto _ret = Recursive(node->next);
	_ret->next = node;
	node->next = nullptr;
	return node;
}

static ListNode<int>* Recursive2(ListNode<int>* node)
{
	if (IS_NULL(node->next))
		return node;

	auto _ret = Recursive2(node->next);
	node->next->next = node;
	node->next = nullptr;

	return _ret;
}