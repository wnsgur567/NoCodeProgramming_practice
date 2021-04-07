#pragma once

#include <iostream>
#include "base.h"
using std::cout;
using std::endl;

// 0 5 0 7 6 3
// 5 7 6 3 0 0
// 단 순서는 유지해야함

void MoveZero1(int* arr, int arr_size);
void MoveZero2(int* arr, int arr_size);

// 0 을 좌측 끝으로 이동시키기
void Array2_MoveZero()
{
	int arr[8] = { 0,5,0,7,6,3,0,1 };

	//MoveZero1(arr, 6);
	MoveZero2(arr, 8);

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << ' ';
	}cout << endl;
}

// 방법 1
// 좌측을 기준으로
// 첫번째로 오는 0번과
// 첫번째로 오는 0번이 아닌 값을 swap
static void MoveZero1(int* arr, int arr_size)
{
	int zero_index = 0;
	int nZero_index = 0;

	while (true)
	{
		while (arr[zero_index] != 0 && zero_index < arr_size)
		{
			++zero_index;
		}
		while (arr[nZero_index] == 0 && nZero_index < arr_size)
		{
			++nZero_index;
		}

		if (zero_index >= arr_size || nZero_index >= arr_size)
			break;

		Swap(&arr[zero_index++], &arr[nZero_index++]);
		for (int i = 0; i < arr_size; i++)
		{
			cout << arr[i] << ' ';
		}cout << endl;
	}
}

// 방법 2
// 0이 아닌 숫자들을 앞에서 부터 복사
// 나머지 부분을 0 으로 set
static void MoveZero2(int* arr, int arr_size)
{
	int index = 0;
	int nonZero_index = 0;

	bool endflag = false;

	while (index < arr_size)
	{
		while (arr[nonZero_index] == 0)
		{
			++nonZero_index;
			if (nonZero_index >= arr_size)
			{
				endflag = true;
				break;
			}
		}
		if (endflag)
			break;

		arr[index++] = arr[nonZero_index++];
		if (nonZero_index >= arr_size)
			break;
	}

	for (; index < arr_size; index++)
	{
		arr[index] = 0;
	}

}