#pragma once

#define NodeSize 7

static void MakeGraph(int*** arr)
{

	*arr = new int* [NodeSize];
	for (int i = 0; i < NodeSize; i++)
	{
		(*arr)[i] = new int[NodeSize];
		for (int j = 0; j < NodeSize; j++)
		{
			(*arr)[i][j] = 0;
		}
	}

	SetGraphNode_Symmetry(*arr, A, B, 1);
	SetGraphNode_Symmetry(*arr, A, C, 1);
	SetGraphNode_Symmetry(*arr, A, D, 1);

	SetGraphNode_Symmetry(*arr, B, C, 1);
	SetGraphNode_Symmetry(*arr, B, E, 1);

	SetGraphNode_Symmetry(*arr, C, D, 1);
	SetGraphNode_Symmetry(*arr, C, E, 1);
	SetGraphNode_Symmetry(*arr, C, F, 1);

	SetGraphNode_Symmetry(*arr, E, G, 1);
}

void Graph1_DFS()
{
	int** arr;

	MakeGraph(&arr);
	PrintGraph(arr, NodeSize, NodeSize);

	stack<int> _stack;
	unordered_set<int> _set;

	_stack.push(A);
	_set.insert(A);
	while (true)
	{
		if (_stack.empty())
			break;

		int node = _stack.top();
		_stack.pop();

		cout << (char)(node + 'A') << endl;

		for (int i = NodeSize - 1; i >= 0; i--)
		{
			if (arr[node][i] == 1)
			{
				if (_set.find(i) == _set.end())
				{	// 중복이 없는 경우
					// node 추가
					_set.insert(i);
					_stack.push(i);
				}
				else
				{	// 중복
					// 추가 안함
				}
			}
		}
	}

}

void Graph1_BFS()
{
	int** arr;

	MakeGraph(&arr);
	PrintGraph(arr, NodeSize, NodeSize);


}


