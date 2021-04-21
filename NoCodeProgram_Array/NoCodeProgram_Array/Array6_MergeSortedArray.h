#pragma once

// 공간을 확장하지 않고 기존 array 공간을 활용하는게 관건

#include<iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;

void Merge(std::vector<int>& vec1, std::vector<int>& vec2);

// 0 인수가 vec2의 개수만큼 뒤에 정렬되어 있음
void Array6_MergeSortedArray()
{
	vector<int> vec1 = { 1,3,5,0,0,0 };
	vector<int> vec2 = { 2,4,8 };
	Merge(vec1, vec2);
	for (vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	vector<int> vec3 = { 4,5,6,0,0,0 };
	vector<int> vec4 = { 1,2,3 };
	Merge(vec3, vec4);
	for (vector<int>::const_iterator it = vec3.begin(); it != vec3.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

static void Merge(std::vector<int>& vec1, std::vector<int>& vec2)
{
	int index = vec1.size() - 1;
	int secondVecIndex = vec2.size() - 1;

	if (secondVecIndex < 0)
		return;

	int firstVecIndex = index;
	while (vec1[firstVecIndex] == 0)
	{
		--firstVecIndex;
	}

	while (0 <= firstVecIndex && 0 <= secondVecIndex)
	{
		int num1 = vec1[firstVecIndex];
		int num2 = vec2[secondVecIndex];

		if (num1 > num2)
		{
			vec1[index] = num1;
			--firstVecIndex;
			--index;
		}
		else
		{
			vec1[index] = num2;
			--secondVecIndex;
			--index;
		}
	}

	if (secondVecIndex > 0)
	{
		std::copy(vec2.begin(), vec2.begin() + secondVecIndex, vec1.begin());
	}
}