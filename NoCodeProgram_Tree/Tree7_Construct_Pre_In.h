#pragma once

#include<iostream>
#include<vector>
using std::vector;

#include "Tree1_traverse.h"

// sample
// pre	:	1	3	7	5	2	4
// In	:	7	3	1	2	5	4

//				1
//			3		5		
//		  7		  2	   4	
void Construct(const vector<TreeNode*>& preorder, const vector<TreeNode*>& postorder, TreeNode* parent);

void Tree7_Construct()
{
	//sample
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node7(7);
	node1.Set(&node3, &node5);
	node3.Set(&node7, nullptr);
	node5.Set(&node2, &node4);
	//sample end

	// pre	:	1	3	7	5	2	4
	vector<TreeNode*> pre;
	pre.push_back(&node1);
	pre.push_back(&node3);
	pre.push_back(&node7);
	pre.push_back(&node5);
	pre.push_back(&node2);
	pre.push_back(&node4);

	// In	:	7	3	1	2	5	4
	vector<TreeNode*> in;
	pre.push_back(&node7);
	pre.push_back(&node3);
	pre.push_back(&node1);
	pre.push_back(&node2);
	pre.push_back(&node5);
	pre.push_back(&node4);



	Construct(pre, in, &node1);

	Recursive_PreOrder(&node1);
	cout << endl;
	Recursive_InOrder(&node1);
	cout << endl;
	Recursive_PostOrder(&node1);
	cout << endl;
}

/// <summary>
/// 
/// 변수로 pre 와 in
/// pre NLR 이므로 맨 앞자리 숫자는 ROOT 임
/// In 에서 ROOT 를 기준으로 양분 가능함  >>	7 3		1 	  2 5 4 
/// pre 도 In을 통해 양분					>>  1		3 7	  5 2 4
/// </summary>
void Construct(const vector<TreeNode*>& preorder, const vector<TreeNode*>& postorder, TreeNode* parent)
{
	TreeNode* root = preorder[0];	// pre의 첫번째가 root

	// post 에서 root인 노드의 index 검색
	int index = 0;
	for (size_t i = 0; i < postorder.size(); i++)
	{
		if (postorder[i] == root)
		{
			index = i;
			break;
		}
	}

	// 더이상 자식이 없으면...
	if (index == 0)
	{	
		return;
	}

	// 좌 우 양분
	vector<TreeNode*> _left_post;
	vector<TreeNode*> _left_pre;
	for (size_t i = 0; i < index; i++)
	{
		_left_post.push_back(postorder[i]);
	}
	for (size_t i = 0; i < _left_post.size(); i++)	// 0번방(head) 제외하고 _left_post.size() 만큼 순회
	{
		_left_pre.push_back(preorder[i + 1]);
	}

	// left pre 의 첫번째는 현재 Root 의 좌측 자식임
	root->mLeft = _left_pre[0];
	// 재귀 호출
	Construct(_left_pre, _left_post, root);

	vector<TreeNode*> _right_post;
	vector<TreeNode*> _right_pre;
	for (size_t i = index + 1; i < postorder.size(); i++)
	{
		_right_post.push_back(postorder[i]);
	}
	for (size_t i = _left_post.size(); i < _left_post.size(); i++)	// 0번방(head) + left_pre 제외하고 _right_post.size() 만큼 순회
	{
		_right_pre.push_back(preorder[i + 1]);
	}

	// right pre 의 첫번째는 현재 Root 의 우측 자식임
	root->mRight = _right_pre[0];
	// 재귀 호출
	Construct(_right_pre, _right_post, root);
}
	