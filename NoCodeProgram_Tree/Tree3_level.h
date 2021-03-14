#pragma once

//https://www.youtube.com/watch?v=Zayvpoz6oqQ&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=4

#include"Tree1_traverse.h"

#include<queue>

using std::cout;
using std::endl;
using std::queue;

void LevelOrder(TreeNode* node);

void Tree3_level()
{
	TreeSample sample;
	LevelOrder(&sample.node1);
	cout << endl;
}

void LevelOrder(TreeNode* node)
{
	queue<TreeNode*> _queue;
	TreeNode* current;

	_queue.push(node);

	while (true)
	{
		if (_queue.empty())
			break;

		current = _queue.front();
		_queue.pop();
		cout << *current << ',';

		if (current->mLeft != nullptr)
		{
			_queue.push(current->mLeft);
		}
		if (current->mRight != nullptr)
		{
			_queue.push(current->mRight);
		}
	}
}