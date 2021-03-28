#pragma once

// https://www.youtube.com/watch?v=Grvjtgo-h-M&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=10

#include"Tree9_SortedArrayToBST.h"

TreeNode* GetLCA(TreeNode* head,int value1, int value2);

using std::cout;
using std::endl;

// BST
//				5
//			3		8
//		  2  4     7  9	
//       1        6

void Tree9_LCAofBST()
{
	std::vector<int> vector{ 1,2,3,4,5,6,7,8,9 };
	auto _result = MakeBST(vector);

	auto _lca = GetLCA(_result, 6, 9);	// 8
	cout << endl;
	cout << "LCA value : " << _lca->mData << endl;

	_lca = GetLCA(_result, 5, 9);	// 5
	cout << endl;
	cout << "LCA value : " << _lca->mData << endl;
	_lca = GetLCA(_result, 1, 4);	// 3
	cout << endl;
	cout << "LCA value : " << _lca->mData << endl;
	
}

static TreeNode* GetLCA(TreeNode* _node, int value1, int value2)
{
	if (_node == nullptr)
		return nullptr;
	
	int myValue = _node->mData;
	// 찾는 노드 모두 현재노드의 왼쪽 노드 자식임
	if (myValue > value1 && myValue > value2)
	{
		return GetLCA(_node->mLeft, value1, value2);
	}
	// 찾는 노드 모두 현재노드의 오른쪽 노드 자식임
	if (myValue < value1 && myValue < value2)
	{
		return GetLCA(_node->mRight, value1, value2);
	}
	return _node;
}
