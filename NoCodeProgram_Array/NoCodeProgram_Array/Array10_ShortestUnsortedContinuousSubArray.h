#pragma once

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using std::vector;
using std::unordered_set;
using std::cout;
using std::endl;

int findUnsortedSubarray(vector<int>& nums);
int find_advanced(vector<int>& nums);

void Array10_ShortestUnsortedContinuousSubarray()
{
	std::vector<int> input = { 2,6,4,8,10,9,15 };

	int result = findUnsortedSubarray(input);
	cout << "result : " << result << endl;

	result = find_advanced(input);
	cout << "result : " << result << endl;
}

// 정렬 한 벡터를 하나 만들고 좌우 피벗을 두고 비교
// 왼쪽 오른쪽에서 첫번째로 변한 부분이 정렬의 시작과 끝점임
// n log n + o n
static int findUnsortedSubarray(vector<int>& nums)
{
	std::vector<int> newVec = nums;
	std::sort(newVec.begin(), newVec.end());

	int left = 0;
	for (int i = 0; i < newVec.size(); i++)
	{
		if (nums[i] != newVec[i])
		{
			left = i;
			break;
		}
	}
	int right = newVec.size() - 1;
	for (int i = newVec.size() - 1; i >= 0; i--)
	{
		if (nums[i] != newVec[i])
		{
			right = i;
			break;
		}
	}

	return right - left + 1;
}

// o(n)
// 그래프를 그리면 보다 직관적으로 확인 가능함
// 꺽이고 나서의 최소값을 알아야 함 (1번 순회) - index 찾기 (1번)
// 꺽이고 나서의 최댓값을 알아야 함 (1번 순회) - index 찾기 (1번)
static int find_advanced(vector<int>& nums)
{
	unordered_set<int> indexies;
	int index = INT_MAX;
	for (int i = 1; i < nums.size(); i++)
	{
		// 전 숫자가 더 작으면
		if (nums[i] < nums[i - 1])
		{
			indexies.insert(i);
		}
		else
			index = i;
	}

	if (index == INT_MAX)
		return 0;


	int min_index = *indexies.begin();
	for (unordered_set<int>::iterator it = indexies.begin(); it != indexies.end(); it++)
	{
		if (nums[min_index] > nums[*it])
			min_index = *it;
	}

	int left = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// 최저점보다 처음으로 큰곳
		if (nums[i] > nums[min_index])
		{
			left = i;
			break;
		}
	}


	indexies.clear();

	index = INT_MIN;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		// 
		if (nums[i] > nums[i + 1])
		{
			indexies.insert(i);			
		}
		else
			index = i;
	}


	int max_index = *indexies.begin();
	for (unordered_set<int>::iterator it = indexies.begin(); it != indexies.end(); it++)
	{
		if (nums[max_index] < nums[*it])
			max_index = *it;
	}

	int right = nums.size() - 1;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[max_index] > nums[i])
		{
			right = i;
			break;
		}
	}

	return right - left + 1;
}