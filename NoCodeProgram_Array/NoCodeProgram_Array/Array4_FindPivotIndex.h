#pragma once

// https://www.youtube.com/watch?v=6gQm5De94aU&list=PLDV-cCQnUlIYFOXYzqLoXnEye4WxDa_30&index=5

// 좌측 합과 우측 합이 동일해지는 pivot을 구하기

#include <iostream>
using std::cout;
using std::endl;

int PivotIndex(int* arr, int _arr_size);
int PivotIndex2(int* arr, int _arr_size);
int GetSum(int* arr, int left, int right);

void Array4_FindPivotIndex()
{
	int arr[] = { 1,8,2,9,2,3,6 };

	int index = PivotIndex2(arr, 7);
	if (index == -1)
		cout << "find fail" << endl;
	else
		cout << "pivot : " << index << endl;
}

static int PivotIndex(int* arr, int _arr_size)
{
	int left_sum = 0;
	int right_sum = 0;

	// i 를 pivot으로 두고 계산
	for (int i = 1; i < _arr_size - 1; i++)
	{
		left_sum = GetSum(arr,0, i - 1);
		right_sum = GetSum(arr, i + 1, _arr_size - 1);
		if (left_sum == right_sum)
			return i;
	}

	// 탐색 실패
	return -1;
}

// 개선판
static int PivotIndex2(int* arr, int _arr_size)
{
	int sum = GetSum(arr, 0, _arr_size - 1);
	int left_sum = 0;
	int right_sum = sum;

	// i 를 pivot으로 두고 계산
	right_sum -= arr[0];
	for (int i = 1; i < _arr_size - 1; i++)
	{
		int num = arr[i];
		right_sum = right_sum - num;
		left_sum = left_sum + arr[i - 1];

		if (left_sum == right_sum)
			return i;
	}

	// 탐색 실패
	return -1;
}

static int GetSum(int* arr,int left, int right)
{
	int sum = 0;
	for (int i = left; i <= right; i++)
	{
		sum += arr[i];
	}
	return sum;
}