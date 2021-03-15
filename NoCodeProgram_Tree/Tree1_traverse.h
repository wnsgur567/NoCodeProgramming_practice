#pragma once

//// https://www.youtube.com/watch?v=bOZhvOc5xlQ&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4


#include<iostream>

struct TreeNode
{
public:
	int mData;
	TreeNode* mLeft = nullptr;
	TreeNode* mRight = nullptr;

public:
	TreeNode(int _data) :mData(_data)
	{}
	

	void Set(TreeNode* left, TreeNode* right)
	{
		mLeft = left;
		mRight = right;
	}
	friend std::ostream& operator<<(std::ostream& os, const TreeNode& node);
};



//    1
//  2   3
// 4 5 6 7
struct TreeSample
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
	TreeSample()
	{
		node1.Set(&node2, &node3);
		node2.Set(&node4, &node5);
		node3.Set(&node6, &node7);
	}
};

void Tree1_traverse();