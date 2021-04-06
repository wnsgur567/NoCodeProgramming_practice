#pragma once

//  https://www.youtube.com/watch?v=H7CNZujkk0k&list=PLDV-cCQnUlIYFOXYzqLoXnEye4WxDa_30&index=2

// pivot 의 설정 방법들
// https://m.blog.naver.com/PostView.nhn?blogId=ljy9378&logNo=221508655059&proxyReferer=https:%2F%2Fwww.google.com%2F

#include "base.h"

void Array1_QuickSort()
{
	RandomArrayMaker _rand;

	int arr_size = 10;
	int* arr = _rand.GetRandomArray(arr_size, 20);
	PrintArray(arr, arr_size);

	//quickSort(arr, 0, 6);
}

// 
static int partition(int nums[], int left, int right)
{
	int pivot;


}

static void quickSort(int nums[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(nums, left, right);
		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);
	}
}
