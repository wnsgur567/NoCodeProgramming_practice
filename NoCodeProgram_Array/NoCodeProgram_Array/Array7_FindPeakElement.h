#pragma once

// 첫 인덱스나 마지막 인덱스의 경우는 하나만 만족해도 해당 됨...

// 1 2 3 일 경우 피크는 3인 index 2가 리턴...

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int FindPeak(const std::vector<int>& vec, int left, int right);

void Array8_Peak()
{
	//vector<int> vec1 = { 1,3,2,4,7,8,6 };
	vector<int> vec1 = { 12,10,8,6,5,3,2 };

	int find_index = FindPeak(vec1, 0, vec1.size() - 1);
	cout << "peak : " << find_index << ',' << vec1[find_index] << endl;
}

static int FindPeak(const std::vector<int>& vec, int left, int right)
{
	if (left == right)
		return left;

	int middle = (left + right) / 2;

	if (vec[middle] < vec[middle + 1])
	{
		return FindPeak(vec, middle + 1, right);
	}
	else
	{
		if(vec[middle] < vec[middle-1])
			return FindPeak(vec, left, middle - 1);
		return middle;
	}

}