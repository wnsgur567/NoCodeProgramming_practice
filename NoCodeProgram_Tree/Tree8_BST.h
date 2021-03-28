#pragma once

#include"Tree1_traverse.h"


//				8
//			3		10
//		  1   6		  14
//			 4 7		15

bool IsBST(TreeNode* _node, int _min, int _max);

void Tree8_BST()
{
	TreeNode node8(2);	// root
	TreeNode node3(3);
	TreeNode node10(10);
	TreeNode node1(1);
	TreeNode node6(6);
	TreeNode node14(14);
	TreeNode node4(4);
	TreeNode node7(7);
	TreeNode node15(15);

	node8.mLeft = &node3;
	node8.mRight = &node10;

	node3.mLeft = &node1;
	node3.mRight = &node6;

	node10.mRight = &node14;

	node6.mLeft = &node4;
	node6.mRight = &node7;

	node14.mRight = &node15;

	bool _result = IsBST(&node8,INT_MIN,INT_MAX);
	std::cout << (_result ? "true" : "false") << std::endl;

}

static bool IsBST(TreeNode* _node,int _min,int _max)
{
	bool my_flag = false;
	bool left_flag = true;
	bool right_flag = true;
	
	if (_node->mData > _min && _node->mData < _max)
		my_flag = true;
	else // 하나라도 아니면 뒤에 더 검사할 필요 없음
		return false;

	if (_node->mLeft != nullptr)
	{	// max 값이 자신의 value 값보다 작아야 함
		left_flag = IsBST(_node->mLeft,_min,_node->mData);
	}

	
	if (_node->mRight != nullptr)
	{
		// min 값이 자신의 value 값보다 커야 함
		right_flag = IsBST(_node->mRight,_node->mData,_max);
	}		

	if (my_flag && left_flag && right_flag)
		return true;
	return false;	
}