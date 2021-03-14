
// https://www.youtube.com/watch?v=bOZhvOc5xlQ&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4

#include<iostream>
#include"Tree1_traverse.h"

using std::cout;
using std::endl;


std::ostream& operator<<(std::ostream& os, const TreeNode& node)
{
	os << node.mData;
	return os;
}



/// <summary>
/// N L R
/// </summary>
void Recursive_PreOrder(const TreeNode* inNode)
{
	cout << *inNode << ',';
	if (inNode->mLeft != nullptr)
		Recursive_PreOrder(inNode->mLeft);
	if (inNode->mRight != nullptr)
		Recursive_PreOrder(inNode->mRight);
}

/// <summary>
/// L N R
/// </summary>
void Recursive_InOrder(const TreeNode* inNode)
{
	if (inNode->mLeft != nullptr)
		Recursive_InOrder(inNode->mLeft);
	cout << *inNode << ',';
	if (inNode->mRight != nullptr)
		Recursive_InOrder(inNode->mRight);
}
/// <summary>
/// L R N
/// </summary>
void Recursive_PostOrder(const TreeNode* inNode)
{
	if (inNode->mLeft != nullptr)
		Recursive_PostOrder(inNode->mLeft);
	if (inNode->mRight != nullptr)
		Recursive_PostOrder(inNode->mRight);
	cout << *inNode << ',';
}


/// <summary>
/// 트리의 순회 방법 세가지
/// Pre / In / Post
/// </summary>
void Tree1_traverse()
{
	TreeSample sample;

	Recursive_PreOrder(&sample.node1);
	cout << endl;
	Recursive_InOrder(&sample.node1);
	cout << endl;
	Recursive_PostOrder(&sample.node1);
	cout << endl;
}

