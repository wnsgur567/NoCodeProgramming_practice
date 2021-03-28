#pragma once

// https://www.youtube.com/watch?v=Grvjtgo-h-M&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=10

#include"Tree1_traverse.h"
#include<vector>

TreeNode* MakeBST(std::vector<int>& _vector);

void Tree9_SortedArrayToBST()
{
	std::vector<int> vector{ 1,2,3,4,5,6,7,8,9 };

	auto _result = MakeBST(vector);
	Recursive_PreOrder(_result);
	cout << endl;
	Recursive_InOrder(_result);
	cout << endl;

	// 대충 딜리트 했다는 내용
}

static TreeNode* MakeBST(std::vector<int>& _vector)
{
	if (_vector.size() == 0)
		return nullptr;

	int middle_index = _vector.size() / 2;
	std::vector<int> _left_vec;
	std::vector<int> _right_vec;

	TreeNode* me = new TreeNode(_vector[middle_index]);

	for (size_t i = 0; i < middle_index; i++)
	{
		_left_vec.push_back(_vector[i]);
	}
	auto lresult_node = MakeBST(_left_vec);
	me->mLeft = lresult_node;
	for (size_t i = middle_index+1; i < _vector.size(); i++)
	{
		_right_vec.push_back(_vector[i]);
	}
	auto rresult_node = MakeBST(_right_vec);
	me->mRight = rresult_node;

	return me;
}

