#pragma once

// https://www.youtube.com/watch?v=tQ1mbKOn6H0&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=6

// LCA(Lowest Common Ancestor)
// ���� ���� ���� ���� ���ã��

//				1
//			2		3
//		  4   5
//			 6 7	
//
//	4���� 7���� ���� ������ ���� ����(2��) ��带 ���ϴ� �˰���
//

#include"Tree1_traverse.h"

bool LCA(TreeNode* node, TreeNode* target1, TreeNode* target2);

struct TreeSample_LCA
{
public:
	union
	{
		TreeNode arr[7]{ 1,2,3,4,5,6,7 };
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
	TreeSample_LCA()
	{
		node1.Set(&node2, &node3);
		node2.Set(&node4, &node5);
		node5.Set(&node6, &node7);
	}
};

void Tree6_LCA()
{
	TreeSample_LCA sample;

	LCA(&sample.node1, &sample.node4, &sample.node7);
	LCA(&sample.node1, &sample.node2, &sample.node7);
}



/// <summary>
///	���� ��忡 �ڽ��� �����ϴ��� üũ
/// ������ ��忡 �ڽ��� �����ϴ��� üũ
/// �� �� ��θ� �����ϴ� ���� LCA��
/// ����) 2���� 7���� ���� ������ ã�� ���� 2�� LCA ��
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
bool LCA(TreeNode* node, TreeNode* target1, TreeNode* target2)
{
	bool leftFlag = false;
	bool rightFlag = false;



	if (node->mLeft != nullptr)
	{
		leftFlag = LCA(node->mLeft, target1, target2);
	}
	if (node->mRight != nullptr)
	{
		rightFlag = LCA(node->mRight, target1, target2);
	}

	if (leftFlag && rightFlag)
	{	// Ž�� ����
		std::cout << "LCA : " << *node << std::endl;
		return true;
	}

	if (node == target1 || node == target2)	// �ϳ��� ��ġ�ϰ�
	{
		if (leftFlag || rightFlag)	// ������ �ϳ��� ���� Ȥ�� ������ �ڽ����� �����Ѵٸ�
		{	// Ž�� ����
			std::cout << "LCA : " << *node << std::endl;
			return true;
		}
		return true;
	}


	if (leftFlag || rightFlag)
		return true;
	return false;

}


