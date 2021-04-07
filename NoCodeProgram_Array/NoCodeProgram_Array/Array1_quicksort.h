#pragma once

//  https://www.youtube.com/watch?v=H7CNZujkk0k&list=PLDV-cCQnUlIYFOXYzqLoXnEye4WxDa_30&index=2

// pivot 의 설정 방법들
// https://m.blog.naver.com/PostView.nhn?blogId=ljy9378&logNo=221508655059&proxyReferer=https:%2F%2Fwww.google.com%2F

#include "base.h"
#include <map>

void quickSort(int nums[], int left, int right);

void Array1_QuickSort()
{
	RandomArrayMaker _rand;

	int arr_size = 10;
	int* arr = _rand.GetRandomArray(arr_size, 20);
	PrintArray(arr, arr_size);

	quickSort(arr, 0, arr_size - 1);

	PrintArray(arr, arr_size);
}


static int partition(int nums[], int left, int right)
{
	int arr_size = right - left + 1;
	if (arr_size < 3)
		return right;

	srand((unsigned int)time(NULL));

	//  Median Of Three Pivot
	std::map<int, int> _map;
	int rand_index;
	while (_map.size() != 3)
	{
		rand_index = rand() % arr_size + left;
		_map[rand_index] = nums[rand_index];
	}

	int sum = 0;
	int max = 0;
	int min = INT_MAX;
	for (std::map<int, int>::const_iterator it = _map.begin(); it != _map.end(); it++)
	{
		sum += it->second;
		if (max < it->second)
			max = it->second;
		if (min > it->second)
			min = it->second;
	}
	int median = sum - min - max;
	for (std::map<int, int>::const_iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (median == it->second)
		{
			return it->first;
		}
	}
}

static void quickSort(int nums[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(nums, left, right);

		// sorting
		Swap(&nums[right], &nums[pivot]);
		pivot = right;

		int lp = left;
		int rp = right;

		while (lp < rp)
		{
			while (nums[lp] < nums[pivot]) lp++;
			while (nums[rp] > nums[pivot]) rp--;
			Swap(&nums[rp], &nums[lp]);
		}
		Swap(&nums[rp], &nums[pivot]);
		pivot = rp;
		// sorting end

		PrintArray(nums, right - left + 1);

		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);
	}
}
