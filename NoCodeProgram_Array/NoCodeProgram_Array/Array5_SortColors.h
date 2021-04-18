#pragma once

#include<iostream>
#include<vector>

using std::cout;
using std::endl;


void Swap(int* n1, int* n2);
void SortColors(std::vector<int>& inVec);

void Array5_SortColors()
{
	std::vector<int> vec = { 0,0,2,2,0,1,2,1,0 };

	SortColors(vec);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	} cout << endl;

}

//void Swap(int* n1, int* n2)
//{
//	int tmp = *n1;
//	*n1 = *n2;
//	*n2 = tmp;
//}

void SortColors(std::vector<int>& inVec)
{
	int o_ptr = 0;				  // 0 만 저장하는 포인터
	int p_ptr = 0;				  
	int g_ptr = inVec.size() - 1; // 2만 저장하는 포인터

	// P 포인터가 0을 만났을 경우 o_ptr 과 교체 ( swap )
	// p 포인터가 2를 만났을 경우 g_ptr 과 교체 ( swap )	// 예외 사항 있음 (위치가 뒤바뀐 이후 p_ptr 위치에 어떤 숫자가 들어올지 모름)
	// p 포인터가 1을 만났을 경우 추가 작업 없이 다음 위치로 이동

	// P_PTR 과 G_PTR 이 교체될때 종료됨

		
	while (true)
	{
		if (inVec[p_ptr] == 0)
		{
			Swap(&inVec[o_ptr], &inVec[p_ptr]);
			++o_ptr;
			++p_ptr;
		}
		else if (inVec[p_ptr] == 2)
		{
			Swap(&inVec[g_ptr], &inVec[p_ptr]);
			--g_ptr;			
		}
		else if (inVec[p_ptr] == 1)
		{
			++p_ptr;
		}


		for (int i = 0; i < inVec.size(); i++)
		{
			cout << inVec[i] << ' ';
		} cout << endl;


		if (p_ptr > g_ptr)
			break;

	}

}

