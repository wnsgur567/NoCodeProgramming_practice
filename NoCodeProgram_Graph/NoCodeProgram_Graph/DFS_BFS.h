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
	cout << "DFS : ";
	while (true)
	{
		if (_stack.empty())
			break;

		int node = _stack.top();
		_stack.pop();

		cout << (char)(node + 'A') << ' ';

		for (int i = NodeSize - 1; i > node; i--)
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
	cout << endl;

}

void Graph1_BFS()
{
	int** arr;

	MakeGraph(&arr);
	PrintGraph(arr, NodeSize, NodeSize);

	queue<int> _queue;
	unordered_set<int> _set;
	_queue.push(A);
	_set.insert(A);

	cout << "BFS : ";
	while (true)
	{
		if (_queue.empty())
			break;

		int curr_node = _queue.front();
		_queue.pop();

		cout << (char)(curr_node + 'A') << ' ';

		for (int i = curr_node + 1; i < NodeSize; i++)
		{
			if (_set.find(i) == _set.end())
			{	// 미등록된 노드이면
				_set.insert(i);
				_queue.push(i);
			}
			else
			{

			}
		}
	}
	cout << endl;

}

bool CanVisitAllRoos(std::vector<std::vector<int>>& rooms);

// https://leetcode.com/problems/keys-and-rooms/
void Graph1_KeysAndRooms()
{
	// 0번방 이외의 방은 처음에 모두 잠겨있음
	// room		:		0		1		2		3			
	// key		:		[1,3]	[3,0,1]	[2]		[0]	
	// 과 같이 주어짐
	// 위에서는 2번방을 입장할 방법이 없음
	// 모든 방을 입장 가능하다면 true 아니면 false

	std::vector<std::vector<int>> input = {
		{1,3},
		{3,0,1},
		{2},
		{0}
	};

	std::vector<std::vector<int>> input2 = {
		{1},
		{2},
		{3},
		{}
	};

	bool result = CanVisitAllRoos(input);

	cout << (result ? "TRUE" : "FALSE") << endl;

	result = CanVisitAllRoos(input2);
	cout << (result ? "TRUE" : "FALSE") << endl;
}

static bool CanVisitAllRoos(std::vector<std::vector<int>>& rooms)
{
	int room_count = rooms.size();

	queue<int> _queue;
	unordered_set<int> _set;

	// 0번방 입장
	_queue.push(0);
	_set.insert(0);

	while (true)
	{
		if (_queue.empty())
			break;

		int curr_room = _queue.front();
		_queue.pop();


		for (int j = 0; j < rooms[curr_room].size(); j++)
		{
			if (_set.find(rooms[curr_room][j]) == _set.end())
			{	// 미방문한 방이면 등록
				_set.insert(rooms[curr_room][j]);
				_queue.push(rooms[curr_room][j]);
			}
			else
			{

			}
		}

	}

	if (room_count == _set.size())
		return true;
	return false;
}


