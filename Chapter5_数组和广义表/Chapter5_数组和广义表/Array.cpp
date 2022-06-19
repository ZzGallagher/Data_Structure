#include"Array.h"

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
	row = column = 0;
	for (row; row <= M.rownum - 1; ++row){
		for (column; column <= M.colnum - 1; ++column){

		}
	}

}