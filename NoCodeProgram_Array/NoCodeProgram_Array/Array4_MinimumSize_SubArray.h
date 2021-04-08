#pragma once

#include<iostream>
#include<vector>

using std::cout;
using std::endl;

int minSubArrayLen(int s, std::vector<int>& nums);

void Array4_MinimumSize_SubArraySum()
{
	int arr[] = { 2,3,1,2,4,3 };
	int target = 7;

	std::vector<int> _vec = { 2,3,1,2,4,3 };

	cout << minSubArrayLen(target, _vec) << endl;
}


// �׻� arr �� ����� �̷���� �־�� ��
// ���� ª�� subarray�� len�� �����ؾ���
// sum �� target ���� ũ�ų� ���� �ּ� len

static int minSubArrayLen(int s, std::vector<int>& nums)
{
	int n = nums.size();
	int ans = INT_MAX;
	int left = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		while (sum >= s) {
			ans = std::min(ans, i + 1 - left);
			sum -= nums[left++];
		}
	}
	return (ans != INT_MAX) ? ans : 0;
}
