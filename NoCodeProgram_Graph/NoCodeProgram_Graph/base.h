#pragma once

#include<iostream>
#include<unordered_set>
#include<stack>
#include<queue>

using std::cout;
using std::endl;
using std::unordered_set;
using std::stack;
using std::queue;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

void SetGraphNode_Symmetry(int** arr, int row, int col, int data)
{
	arr[row][col] = data;
	arr[col][row] = data;
}
void SetGraphNode(int** arr, int row, int col, int data)
{
	arr[row][col] = data;
}

void PrintGraph(int** arr, int row, int col)
{
	cout << "----Print----" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

#include "DFS_BFS.h"