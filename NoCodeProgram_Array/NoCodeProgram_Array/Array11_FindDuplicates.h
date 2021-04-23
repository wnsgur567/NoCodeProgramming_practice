#pragma once

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int FindDuplicates(std::vector<int>& vec);

// n번까지의 숫자가 n+1개의 공간을 가지는 배열에 랜덤 배치됨
// 중복된 숫자를 도출
void Array11_FindDuplicates()
{
	std::vector<int> input1 = { 1,2,3,4,5,3 };	// result 3
	std::vector<int> input2 = { 1,2,3,4,2 };	// result 2

	int result1 = FindDuplicates(input1);
	int result2 = FindDuplicates(input2);

	cout << "result1 : " << result1 << endl;
	cout << "result2 : " << result2 << endl;
}

// counting 은 공간이 on, 아래거는 o1

// 내부 변수의 값을 인덱스 번호로 생각하고 표기가능함
// 이미 확인한 값을 음수로 표기
static int FindDuplicates(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int num = ((vec[i] > 0) ? vec[i] : (-1 * vec[i]));
		if (vec[num] < 0)
		{	// 중복된 수
			return num;
		}
		vec[num] *= -1;
	}
	return -1;
}