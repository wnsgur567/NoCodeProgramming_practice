#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::pair;

using pairVec = std::vector<std::pair<int, int>>;

pairVec MergeIntervals(pairVec& inputVec);

void Array9_MergeIntervals()
{
	pairVec inputVec;
	inputVec.emplace_back(1, 5);
	inputVec.emplace_back(3, 7);
	inputVec.emplace_back(8, 16);
	inputVec.emplace_back(10, 15);

	pairVec outputVec = MergeIntervals(inputVec);

	for (auto& item :outputVec)
	{
		cout << "[" << item.first << ":" << item.second << "]" << endl;
	}
	cout << endl;
}

static pairVec MergeIntervals(pairVec& inputVec)
{
	if (inputVec.size() == 0)
		return pairVec();

	std::sort(inputVec.begin(), inputVec.end());

	pairVec ret;
	ret.push_back(inputVec[0]);

	for (pairVec::iterator it = inputVec.begin() + 1; it != inputVec.end(); it++)
	{
		auto last_pair = (ret.end() - 1);
		if (last_pair->second < it->first)
		{
			ret.push_back(*it);
		}
		else
		{
			if (last_pair->second < it->second)
			{
				last_pair->second = it->second;
			}
		}
	}

	return ret;
}