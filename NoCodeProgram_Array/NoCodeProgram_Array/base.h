#pragma once

#include<time.h>
#include<stdlib.h>
#include<stdio.h>

class RandomArrayMaker
{
private:
	bool IsExist(const int* arr, const int _arr_size, int _num)
	{
		for (int i = 0; i < _arr_size; i++)
		{
			if (arr[i] == _num)
				return true;
		}
		return false;
	}
public:
	RandomArrayMaker()
	{
		srand((unsigned int)time(NULL));
	}

	// 중복되지 않은 arr 할당 및 반환
	int* GetRandomArray(int _arr_size, int max_value)
	{
		int* ret_arr = new int[_arr_size];
		int _curr_size = 0;

		for (int i = 0; i < _arr_size; i++)
		{
			int new_num = rand() % max_value + 1;
			if (false == IsExist(ret_arr, _curr_size, new_num))
			{
				ret_arr[i] = new_num;
			}
			else
			{
				--i;
			}
		}

		return ret_arr;
	}

	// 중복이 반드시 존재하는 arr 할당 및 반환
	int* GetRandomArray_duplicate(int _arr_size, int max_value)
	{
		int* ret_arr = new int[_arr_size];

		for (int i = 0; i < _arr_size; i++)
		{
			ret_arr[i] = rand() % max_value + 1;
		}

		// 바꿀 개수
		int replace_count = max_value / 10 + 1;
		for (int i = 0; i < replace_count; i++)
		{
			int _rand_index = rand() % max_value;
			ret_arr[_rand_index] = ret_arr[0];			
		}

		return ret_arr;
	}
};

void PrintArray(int* arr, int _arr_size)
{
	for (int i = 0; i < _arr_size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* num1, int* num2)
{
	int tmp = *num1;

	*num2 = *num1;
	*num1 = tmp;
}