#pragma once

#include<iostream>

using std::cout;
using std::endl;

struct TreeNode_diameter
{
public:
	int mData;
	TreeNode_diameter* mLeft = nullptr;
	TreeNode_diameter* mRight = nullptr;

	int diameter;
	int leftDiameter;
	int rightDiameter;

public:
	TreeNode_diameter(int _data) :mData(_data),
		diameter(1), leftDiameter(0), rightDiameter(0)
	{}


	void Set(TreeNode_diameter* left, TreeNode_diameter* right)
	{
		mLeft = left;
		mRight = right;
	}
	friend std::ostream& operator<<(std::ostream& os, const TreeNode_diameter& node);
};


std::ostream& operator<<(std::ostream& os, const TreeNode_diameter& node)
{
	os << node.mData;
	return os;
}


//			 1
//		2		  3
//   4     5 
//     6      7
//   8          9
struct TreeSample_diameter
{
public:
	union
	{
		TreeNode_diameter arr[9]{ 1,2,3,4,5,6,7,8,9 };
		struct
		{
			TreeNode_diameter node1;
			TreeNode_diameter node2;
			TreeNode_diameter node3;
			TreeNode_diameter node4;
			TreeNode_diameter node5;
			TreeNode_diameter node6;
			TreeNode_diameter node7;
			TreeNode_diameter node8;
			TreeNode_diameter node9;
		};
	};
public:
	TreeSample_diameter()
	{
		node1.Set(&node2, &node3);
		node2.Set(&node4, &node5);
		node4.Set(nullptr, &node6);
		node6.Set(&node8, nullptr);

		node5.Set(nullptr, &node7);
		node7.Set(nullptr, &node9);
	}
};

int GetTreeDiameter(TreeNode_diameter* node);

void Tree5_Diameter()
{
	TreeSample_diameter sample;
	GetTreeDiameter(&sample.node1);

	int _diameter = 0;
	for (const auto& n : sample.arr)
	{
		if (n.diameter > _diameter)
			_diameter = n.diameter;
	}

	cout << "Diameter : " << _diameter << endl;
}

int GetTreeDiameter(TreeNode_diameter* node)
{
	if (node->mLeft != nullptr)
	{
		node->leftDiameter = GetTreeDiameter(node->mLeft);
	}
	else
	{
		node->leftDiameter = 0;
	}

	if (node->mRight != nullptr)
	{
		node->rightDiameter = GetTreeDiameter(node->mRight);
	}
	else
	{
		node->rightDiameter = 0;
	}

	node->diameter = node->leftDiameter + node->rightDiameter;

	return node->leftDiameter > node->rightDiameter ? node->leftDiameter + 1 : node->rightDiameter + 1;
}