#pragma once

#include"base.h"
#include"Array1_quicksort.h"


int BinarySearch(int* arr, int target, int left, int right);

void Array2_BS()
{
	RandomArrayMaker maker;
	int* arr = maker.GetRandomArray(10, 30);
	quickSort(arr, 0, 9);
	cout << "STD" << endl;
	PrintArray(arr, 10);

	cout << endl << endl;
	// 성공 case
	//cout << "target : " << arr[4] << endl;
	//	int _index = BinarySearch(arr, arr[4], 0, 9);

	// 실패 case
	cout << "target : " << 100 << endl;
	int _index = BinarySearch(arr, 100, 0, 9);

	if (_index == -1)
	{
		cout << "탐색 실패" << endl;
	}
	else
	{
		cout << "index : " << _index << endl;
	}
}


// return val : target index
int BinarySearch(int* arr, int target, int left, int right)
{
	if (left > right)
	{	// 탐색 실패
		return -1;
	}

	int center = (left + right) / 2;
	if (target == arr[center])
	{	// 검색 성공
		return center;
	}
	else if (arr[center] > target)
	{	// 우측에 있는 경우
		return BinarySearch(arr, target, center + 1, right);
	}
	else
	{	// 좌측에 있는 경우
		return BinarySearch(arr, target, left, center - 1);
	}

}