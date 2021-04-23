#pragma once

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int FindDuplicates(std::vector<int>& vec);

// n�������� ���ڰ� n+1���� ������ ������ �迭�� ���� ��ġ��
// �ߺ��� ���ڸ� ����
void Array11_FindDuplicates()
{
	std::vector<int> input1 = { 1,2,3,4,5,3 };	// result 3
	std::vector<int> input2 = { 1,2,3,4,2 };	// result 2

	int result1 = FindDuplicates(input1);
	int result2 = FindDuplicates(input2);

	cout << "result1 : " << result1 << endl;
	cout << "result2 : " << result2 << endl;
}

// counting �� ������ on, �Ʒ��Ŵ� o1

// ���� ������ ���� �ε��� ��ȣ�� �����ϰ� ǥ�Ⱑ����
// �̹� Ȯ���� ���� ������ ǥ��
static int FindDuplicates(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int num = ((vec[i] > 0) ? vec[i] : (-1 * vec[i]));
		if (vec[num] < 0)
		{	// �ߺ��� ��
			return num;
		}
		vec[num] *= -1;
	}
	return -1;
}