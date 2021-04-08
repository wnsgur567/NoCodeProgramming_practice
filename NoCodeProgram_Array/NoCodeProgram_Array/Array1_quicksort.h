#pragma once

//  https://www.youtube.com/watch?v=H7CNZujkk0k&list=PLDV-cCQnUlIYFOXYzqLoXnEye4WxDa_30&index=2

// pivot 의 설정 방법들
// https://m.blog.naver.com/PostView.nhn?blogId=ljy9378&logNo=221508655059&proxyReferer=https:%2F%2Fwww.google.com%2F

#include "base.h"
#include <map>
#include <iostream>
using std::cout;
using std::endl;

void quickSort(int nums[], int left, int right);

#define ARR_SIZE 10

void Array1_QuickSort()
{
	RandomArrayMaker _rand;

	int arr[ARR_SIZE] = { 11,15,10,14,9,4,7,13,19,12 };

	// 중복 없는 arr

	int i = 0;
	while (i < 100000)
	{
		int copied[ARR_SIZE];
		CopyArr(arr, copied, ARR_SIZE);
		quickSort(copied, 0, ARR_SIZE - 1);
		if (IsSorted(copied, ARR_SIZE) == false)
		{
			cout << "ERROR" << endl;
			break;
		}
		++i;
	}
	cout << "succeed" << endl;




	//int* arr = _rand.GetRandomArray(arr_size, 20);
	/*PrintArray(arr, arr_size);
	quickSort(arr, 0, arr_size - 1);
	PrintArray(arr, arr_size);*/
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
	return -1;
}

static void quickSort(int nums[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(nums, left, right);
		//cout << "-- index, pivot : " << pivot << "," << nums[pivot] << endl;
		// sorting
		Swap(&nums[right], &nums[pivot]);
		pivot = right;

		int lp = left;
		int rp = right - 1;
		int counter = 0;
		while (true)
		{
			while ((nums[lp] < nums[pivot]) &&
				(lp < right))
			{
				++lp;
			}
			while ((nums[rp] > nums[pivot]) &&
				(rp > left))
			{
				--rp;
			}

			// 만나거나 교차되면 중지
			if (lp >= rp)
			{
				break;
			}

			counter++;
			Swap(&nums[rp--], &nums[lp++]);
			//PrintArray(nums, left, right);
		}
		Swap(&nums[lp], &nums[pivot]);
		pivot = lp;
		// sorting end

		//PrintArray(nums, left, right);

		if (counter == 0)
			return;

		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);
	}
}
