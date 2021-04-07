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
	// ���� case
	//cout << "target : " << arr[4] << endl;
	//	int _index = BinarySearch(arr, arr[4], 0, 9);

	// ���� case
	cout << "target : " << 100 << endl;
	int _index = BinarySearch(arr, 100, 0, 9);

	if (_index == -1)
	{
		cout << "Ž�� ����" << endl;
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
	{	// Ž�� ����
		return -1;
	}

	int center = (left + right) / 2;
	if (target == arr[center])
	{	// �˻� ����
		return center;
	}
	else if (arr[center] > target)
	{	// ������ �ִ� ���
		return BinarySearch(arr, target, center + 1, right);
	}
	else
	{	// ������ �ִ� ���
		return BinarySearch(arr, target, left, center - 1);
	}

}