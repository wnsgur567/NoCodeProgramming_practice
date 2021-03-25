#pragma once

// https://www.youtube.com/watch?v=KX4QZZhf70k&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=9

// add two numbers (reverse)
// reverse 인 이유는 1의 자리부터 올림 계산을 해야 편하기 때문에
// 7 -> 5 -> 3
// 4 -> 8 -> 2
// 357 + 284 = 641
// result : 1 -> 4 -> 6


// Non Reverse
// 7 -> 5 -> 3
// 4 -> 8 -> 2
// 753 + 482 = 1235
// result : 1 2 3 5

#include"LinkedList1_base.h"
ListNode<int>* GetSum(const ListNode<int>* _head1, const ListNode<int>* _head2);
ListNode<int>* GetSum_NR(const ListNode<int>* _head1, const ListNode<int>* _head2);

void LinkedList8_AddTwoNums()
{
	auto node1 = new ListNode<int>(7);
	auto node2 = new ListNode<int>(5);
	auto node3 = new ListNode<int>(3);

	auto node10 = new ListNode<int>(4);
	auto node11 = new ListNode<int>(8);
	auto node12 = new ListNode<int>(2);

	node1->next = node2;
	node2->next = node3;

	node10->next = node11;
	node11->next = node12;


	auto result = GetSum(node1, node10);
	PrintAll(result->next);

	auto result_NR = GetSum_NR(node1, node10);
	PrintAll(result_NR->next);

	delete node1;
	delete node2;
	delete node3;
	delete node10;
	delete node11;
	delete node12;

	ListNode<int>* curr = result;
	while (curr)
	{
		auto deleteNode = curr;
		curr = curr->next;
		delete deleteNode;
	}
}

// reverse 버젼
static ListNode<int>* GetSum(const ListNode<int>* _head1, const ListNode<int>* _head2)
{
	auto curr1 = _head1;
	auto curr2 = _head2;

	ListNode<int>* _result = new ListNode<int>(-1000);	// dummy head
	ListNode<int>* curr = _result;

	int carry = 0;	// 올림
	int value = 0;	// 올림을 제외한 값
	int flag = 0;	// 두 리스트 모두  nullptr이 되면 종료하도록
	while (true)
	{
		if (curr1 != nullptr)
		{
			value += curr1->value;
			curr1 = curr1->next;
		}
		else
			++flag;

		if (curr2 != nullptr)
		{
			value += curr2->value;
			curr2 = curr2->next;
		}
		else
			++flag;

		// return 조건
		if (flag == 2)
		{
			// 올림한 값이 있을 경우 리스트 추가 후 리턴
			if (value == 1)
			{
				curr->next = new ListNode<int>(value);
			}
			return _result;
		}



		if (value > 9)
		{
			carry = 1;
			value -= 10;
		}

		curr->next = new ListNode<int>(value);
		curr = curr->next;

		value = carry;
		carry = 0;
		flag = 0;
	}
}


#include<stack>

// non reverse 버젼
static ListNode<int>* GetSum_NR(const ListNode<int>* _head1, const ListNode<int>* _head2)
{
	std::stack<const ListNode<int>*> _stack1;
	std::stack<const ListNode<int>*> _stack2;

	std::stack<int> _result_stack;
	

	// 1번 리스트 스택에 담기
	auto curr1 = _head1;
	while (curr1)
	{
		_stack1.push(curr1);
		curr1 = curr1->next;
	}

	// 2번 리스트 스택에 담기
	auto curr2 = _head2;
	while (curr2)
	{
		_stack2.push(curr2);
		curr2 = curr2->next;
	}

	// 두 스택에서 pop 하며 역으로 계산
	
	int carry = 0;
	int value = 0;
	int flag = 0;
	while (true)
	{
		if (_stack1.size() != 0)
		{
			auto _tmp = _stack1.top();
			_stack1.pop();
			value += _tmp->value;
		}
		else
			++flag;

		if (_stack2.size() != 0)
		{
			auto _tmp = _stack2.top();
			_stack2.pop();
			value += _tmp->value;
		}
		else
			++flag;

		// loop 탈출 조건
		if (flag == 2)
		{
			if (value == 1)			
				_result_stack.push(value);				
			break;
		}

		// 올림 발생
		if (value > 9)
		{
			carry = 1;
			value -= 10;
		}
		
		_result_stack.push(value);		

		value = carry;
		carry = 0;
		flag = 0;
	}

	ListNode<int>* dummy = new ListNode<int>(-1000);
	auto curr = dummy;	
	while (_result_stack.size())
	{		
		curr->next = new ListNode<int>(_result_stack.top());
		_result_stack.pop();		
		curr = curr->next;
	}

	return dummy;
}

