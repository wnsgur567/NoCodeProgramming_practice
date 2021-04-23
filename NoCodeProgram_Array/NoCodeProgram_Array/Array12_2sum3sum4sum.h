#pragma once


#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using std::vector;
using std::unordered_set;
using std::cout;
using std::endl;


vector<int> TwoSum_Brute(vector<int> vec, int target);
vector<int> TwoSum(vector<int> vec, int target);
void Print(const vector<int>& vec);

void Array12_TwoSum()
{
	vector<int> input1 = { 2,7,11,15 };
	vector<int> input2 = { 3,2,4 };
	vector<int> input3 = { 3,3 };

	vector<int> result1 = TwoSum_Brute(input1, 9);
	vector<int> result2 = TwoSum_Brute(input2, 6);
	vector<int> result3 = TwoSum_Brute(input3, 6);

	Print(result1);
	Print(result2);
	Print(result3);
}

static void Print(const vector<int>& vec)
{
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << "]" << endl;
}

// 값을 리턴해야 할 경우 사용 가능
// 혹은 이미 정렬된 어레이를 사용할 경우 사용 가능함
static vector<int> TwoSum(vector<int> vec, int target)
{
	// 정렬한 이후 인덱스 2개를 사용해서 순회
	vector<int> ret;

	std::sort(vec.begin(), vec.end());

	int left = 0;
	int right = vec.size() - 1;

	while (left < right)
	{
		int sum = vec[left] + vec[right];
		if (sum == target)
		{
			ret.push_back(left);
			ret.push_back(right);
			break;
		}
		else if (sum < target)
		{
			++left;
		}
		else
		{
			--right;
		}
	}

	return ret;
}

static vector<int> TwoSum_Brute(vector<int> vec, int target)
{
	vector<int> ret;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			int sum = vec[i] + vec[j];
			if (sum == target)
			{
				ret.push_back(i);
				ret.push_back(j);
				return ret;
			}
		}
	}
	return ret;
}


void Print(vector<vector<int>> vecvec);
vector<vector<int>> ThreeSum(vector<int> vec, int target);
// sorted
void Array12_TreeSum()
{
	vector<int> input1 = { 1,2,5,9,10,11,12,15,19 };
	vector<int> input2 = { 1,2,3,4,5 };
	vector<int> input3 = { -7,-1,1,2,3,5 };
	vector<int> input4 = { 2,2,2,2 };

	vector<vector<int>> result1 = ThreeSum(input1, 20);
	vector<vector<int>> result2 = ThreeSum(input2, 7);
	vector<vector<int>> result3 = ThreeSum(input3, 0);
	vector<vector<int>> result4 = ThreeSum(input4, 6);

	Print(result1);
	Print(result2);
	Print(result3);
	Print(result4);
}

static void Print(vector<vector<int>> vecvec)
{

	cout << "[ ";
	for (int i = 0; i < vecvec.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < vecvec[i].size(); j++)
		{
			cout << vecvec[i][j] << ' ';
		}
		cout << "]" << "\t";
	}
	cout << "]" << endl;
}

static vector<vector<int>> ThreeSum(vector<int> vec, int target)
{
	vector<vector<int>> ret;

	int base;
	for (int j = 0; j < vec.size() - 2; j++)
	{
		base = j;
		int left = base + 1;
		int right = vec.size() - 1;

		while (left < right)
		{
			int sum = vec[base] + vec[left] + vec[right];
			if (sum == target)
			{
				vector<int> tmpvec;
				tmpvec.push_back(base);
				tmpvec.push_back(left);
				tmpvec.push_back(right);
				ret.push_back(tmpvec);
				break;
			}
			else if (sum < target)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
	}
	return ret;
}

vector<vector<int>> FourSum(vector<int> vec, int target);

void Array12_FourSum()
{
	//vector<int> input = { 1,0,-1,0,-2,2 };
	vector<int> input = { 2,2,2,2,2 };

	auto output = FourSum(input, 8);
	Print(output);
}


// distinct 로는 잘 되는데....
static vector<vector<int>> FourSum(vector<int> vec, int target)
{
	std::sort(vec.begin(), vec.end());

	vector<vector<int>> ret;

	for (int k = 0; k < vec.size() - 3; k++)
	{
		auto find_index = ThreeSum(vec, target - vec[k]);

		for (int i = 0; i < find_index.size(); i++)
		{
			vector<int> tmpVec;
			tmpVec.push_back(vec[k]);
			tmpVec.push_back(vec[find_index[i][0]]);
			tmpVec.push_back(vec[find_index[i][1]]);
			tmpVec.push_back(vec[find_index[i][2]]);
			ret.push_back(tmpVec);
		}
		vec.erase(vec.begin());
	}

	return ret;
}