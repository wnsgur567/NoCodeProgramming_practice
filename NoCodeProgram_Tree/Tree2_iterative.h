#pragma once

// https://www.youtube.com/watch?v=JezbkFWhrPA&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=2

// 스택을 이용
#include<stack>

#include<iostream>

#include"Tree1_traverse.h"

using std::cout;
using std::endl;
using std::stack;

struct TreeNode_flag;

void Iterative_PreOrder(TreeNode* node);
void Iterative_InOrder(TreeNode* node);
void Iterative_PostOrder(TreeNode_flag* node);


// stack 을 이용한 post 오더시 사용 할 놈
#pragma region ForPostOrder
struct TreeNode_flag
{
public:
	TreeNode_flag(int _data) :
		mData(_data), flag(false) {}

	bool flag;
	int mData;
	TreeNode_flag* mLeft = nullptr;
	TreeNode_flag* mRight = nullptr;

	void Set(TreeNode_flag* left, TreeNode_flag* right)
	{
		mLeft = left;
		mRight = right;
	}
	friend std::ostream& operator<<(std::ostream& os, const TreeNode_flag& node);
};
std::ostream& operator<<(std::ostream& os, const TreeNode_flag& node)
{
	os << node.mData;
	return os;
}



struct TreeSample_flag
{
public:
	union
	{
		TreeNode_flag arr[7]{ 1,2,3,4,5,6,7 };
		struct
		{
			TreeNode_flag node1;
			TreeNode_flag node2;
			TreeNode_flag node3;
			TreeNode_flag node4;
			TreeNode_flag node5;
			TreeNode_flag node6;
			TreeNode_flag node7;
		};
	};
public:
	TreeSample_flag()
	{
		node1.Set(&node2, &node3);
		node2.Set(&node4, &node5);
		node3.Set(&node6, &node7);
	}
};

#pragma endregion

void Tree2_iterative()
{
	TreeSample sample;
	TreeSample_flag smaple_flag;

	Iterative_PreOrder(&sample.node1);
	cout << endl;
	Iterative_InOrder(&sample.node1);
	cout << endl;
	Iterative_PostOrder(&smaple_flag.node1);
	cout << endl;
}


/// <summary>
/// N L R
/// 
/// 1. N(current)을 출력
/// 2. 스택에 R , L 을 push
/// 3. pop() => L 이 current
/// </summary>
void Iterative_PreOrder(TreeNode* node)
{
	stack<TreeNode*> _stack;
	_stack.push(node);

	TreeNode* current = nullptr;

	while (true)
	{
		if (_stack.empty())
			break;

		current = _stack.top();
		_stack.pop();
		cout << *current << ',';

		if (current->mRight != nullptr)
			_stack.push(current->mRight);
		if (current->mLeft != nullptr)
			_stack.push(current->mLeft);
	}


}

/// <summary>
/// L N R
/// 
/// 1. L 방향으로 모두 Push
/// 2. pop 하고 출력
/// 3. right push
/// </summary>
/// <param name="node"></param>
void Iterative_InOrder(TreeNode* node)
{
	stack<TreeNode*> _stack;

	TreeNode* current = node;
	_stack.push(current);

	while (true)
	{
		if (current->mLeft != nullptr)
		{
			current = current->mLeft;
			_stack.push(current);
			continue;
		}

		if (_stack.empty())
			break;
		current = _stack.top();
		_stack.pop();
		cout << *current << ',';

		if (current->mRight != nullptr)
		{
			current = current->mRight;
			_stack.push(current);
			continue;
		}
	}
}

/// <summary>
/// L R N
/// 
/// 무한 루프에 빠질 수 있음
/// Right가 이미 순회한 노드인지 체크 필요
/// FLAG 로 검사
/// 
/// </summary>
/// <param name="node"></param>


void Iterative_PostOrder(TreeNode_flag* node)
{
	stack<TreeNode_flag*> _stack;

	TreeNode_flag* current = node;
	
	_stack.push(current);

	while (true)
	{
		auto _node = current->mLeft;
		if (_node != nullptr && _node->flag == false)
		{
			current = current->mLeft;
			_stack.push(current);
			continue;
		}


		_node = current->mRight;
		if (_node != nullptr && _node->flag == false)
		{
			current = current->mRight;
			_stack.push(current);
			continue;
		}		
		
		current->flag = true;
		cout << *current << ',';
		_stack.pop();
		if (_stack.empty())
			break;
		current = _stack.top();
	}
}
