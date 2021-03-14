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

// root �κ��� leaf ������ ���� (Target sum)
// Target Sum �� 20�� �ǵ���
void Tree4_pathsum()
{
	TreeSample_PathSum sample;
	PathSum(&sample.node1, 20);
}

void PathSum(TreeNode* node, int target_num)
{
	int new_target_num = target_num - (node->mData);

	// leaf ��� üũ
	if (node->mLeft == nullptr && node->mRight == nullptr)
	{
		if (new_target_num == 0)
		{
			// Ž�� ����
			cout << "���� ��� : " << node->mData << endl;
			return;
		}
		else
		{
			// Ž�� ����
			cout << "���� ��� : " << node->mData << endl;
			return;
		}
	}

	// �߰� �˻� �ʿ�

	if (node->mLeft != nullptr)
		PathSum(node->mLeft, new_target_num);
	if (node->mRight != nullptr)
		PathSum(node->mRight, new_target_num);
}