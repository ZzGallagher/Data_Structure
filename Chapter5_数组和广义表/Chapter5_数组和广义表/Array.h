//多维数组
namespace Array{
	//#include<cstdarg>
	//标准头文件，提供宏va_start,va_arg,va_end
	//用于存取变长参数表
	#define MAX_ARRAY_DIM 8 //维数最大值
	typedef int ElemType;
	typedef struct{
		ElemType *base;
		int dim;
		int *bounds;
		int *constants;
	}Array;
}

//三元组顺序表表示稀疏矩阵
namespace SpareMatrix{
	#define MAXSIZE 20	//非零元素个数最大值为12500
	typedef int ElemType;
	typedef struct{
		int i;
		int j;//行下标、列下标
		ElemType e;
	}Triple;
	typedef struct{
		Triple data[MAXSIZE + 1];	//非零三元组表，data[0]不用
		int rownum, colnum, elemnum;	//矩阵的行数、列数、非零元个数
	}TSMatrix;//三元组顺序表表示稀疏矩阵

	void TransposeSMatrix(TSMatrix M, TSMatrix&T);	//采用三元组表示表存储表示，求稀疏矩阵M的转置矩阵T
	void printTSMatrix(TSMatrix M);
}

//广义表
namespace GList {
	typedef int AtomType;
	typedef enum{ATOM,LIST}ElemTag;	//ATOM == 0：原子 LIST == 1：子表
	typedef struct GLNode {
		ElemTag tag;
		union {
			AtomType atom;
			struct {
				struct GLNode* hp, * tp;
			}ptr;	//ptr是表结点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
		};
	}*GList;//广义表类型
}