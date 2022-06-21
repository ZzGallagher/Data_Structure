#include"Array.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void SpareMatrix::TransposeSMatrix(TSMatrix M, TSMatrix&T){
	//采用三元组表示表存储表示，求稀疏矩阵M的转置矩阵T
	T.rownum = M.colnum;
	T.colnum = M.rownum;
	T.elemnum = M.elemnum;
	if (T.elemnum){
		int q = 1;
		for (int col = 1; col < M.colnum; ++col){
			for (int p = 1; p <= M.elemnum; ++p){
				if (M.data[p].j == col){
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
}

void SpareMatrix::printTSMatrix(TSMatrix M){
	int row, column;
	int p = 1;
	row = column = 1;
	for (row; row <= M.rownum ; ++row){
		for (column; column <= M.colnum ; ++column){
			if (row == M.data[p].i && column == M.data[p].j)
			{
				cout << M.data[p].e << '\t';
				++p;
			}
			else
				cout << 0 << '\t';
		}
		cout << endl;
	}
}