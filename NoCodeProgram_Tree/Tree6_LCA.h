#pragma once

// https://www.youtube.com/watch?v=tQ1mbKOn6H0&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=6

// LCA(Lowest Common Ancestor)
// 가장 낮은 공통 조상 노드찾기

//				1
//			2		3
//		  4   5
//			 6 7	
//
//	4번과 7번의 공통 조상중 가장 낮은(2번) 노드를 구하는 알고리즘
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
///	왼쪽 노드에 자식이 존재하는지 체크
/// 오른쪽 노드에 자식이 존재하는지 체크
/// 위 둘 모두를 만족하는 곳이 LCA임
/// 예외) 2번과 7번의 공통 조상을 찾는 경우는 2가 LCA 임
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
	{	// 탐색 성공
		std::cout << "LCA : " << *node << std::endl;
		return true;
	}

	if (node == target1 || node == target2)	// 하나가 일치하고
	{
		if (leftFlag || rightFlag)	// 나머지 하나가 좌측 혹은 우측에 자식으로 존재한다면
		{	// 탐색 성공
			std::cout << "LCA : " << *node << std::endl;
			return true;
		}
		return true;
	}


	if (leftFlag || rightFlag)
		return true;
	return false;

}


