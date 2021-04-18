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
	int o_ptr = 0;				  // 0 �� �����ϴ� ������
	int p_ptr = 0;				  
	int g_ptr = inVec.size() - 1; // 2�� �����ϴ� ������

	// P �����Ͱ� 0�� ������ ��� o_ptr �� ��ü ( swap )
	// p �����Ͱ� 2�� ������ ��� g_ptr �� ��ü ( swap )	// ���� ���� ���� (��ġ�� �ڹٲ� ���� p_ptr ��ġ�� � ���ڰ� ������ ��)
	// p �����Ͱ� 1�� ������ ��� �߰� �۾� ���� ���� ��ġ�� �̵�

	// P_PTR �� G_PTR �� ��ü�ɶ� �����

		
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

