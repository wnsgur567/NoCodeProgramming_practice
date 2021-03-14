#pragma once

// https://www.youtube.com/watch?v=Zayvpoz6oqQ&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=4

#include"Tree1_traverse.h"
#include<queue>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

void PathSum(TreeNode* node, int target_num);

//	       7
//	 -2 	   5
//	3	15	 8	-5
struct TreeSample_PathSum
{
public:
	union
	{
		TreeNode arr[7]{ 7 , -2, 5 ,3,15,8,-5 };
		struct
		{
			TreeNode node1;
			TreeNode node2;
			TreeNode node3;
			TreeNode node4;
			TreeNode node5;
			TreeNode node6;
			TreeNode node7;
		};
	};
public:
	TreeSample_PathSum()
	{
		node1.Set(&node2, &node3);
		node2.Set(&node4, &node5);
		node3.Set(&node6, &node7);
	}
};

// root 로부터 leaf 까지의 합이 (Target sum)
// Target Sum 이 20이 되도록
void Tree4_pathsum()
{
	TreeSample_PathSum sample;
	PathSum(&sample.node1, 20);
}

void PathSum(TreeNode* node, int target_num)
{
	int new_target_num = target_num - (node->mData);

	// leaf 노드 체크
	if (node->mLeft == nullptr && node->mRight == nullptr)
	{
		if (new_target_num == 0)
		{
			// 탐색 성공
			cout << "성공 노드 : " << node->mData << endl;
			return;
		}
		else
		{
			// 탐색 실패
			cout << "실패 노드 : " << node->mData << endl;
			return;
		}
	}

	// 추가 검색 필요

	if (node->mLeft != nullptr)
		PathSum(node->mLeft, new_target_num);
	if (node->mRight != nullptr)
		PathSum(node->mRight, new_target_num);
}