#pragma once

#include <iostream>
#include "base.h"
using std::cout;
using std::endl;

// 0 5 0 7 6 3
// 5 7 6 3 0 0
// �� ������ �����ؾ���

void MoveZero1(int* arr, int arr_size);
void MoveZero2(int* arr, int arr_size);

// 0 �� ���� ������ �̵���Ű��
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

// ��� 1
// ������ ��������
// ù��°�� ���� 0����
// ù��°�� ���� 0���� �ƴ� ���� swap
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

// ��� 2
// 0�� �ƴ� ���ڵ��� �տ��� ���� ����
// ������ �κ��� 0 ���� set
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