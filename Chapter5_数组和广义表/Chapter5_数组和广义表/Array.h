//��ά����
namespace Array{
	//#include<cstdarg>
	//��׼ͷ�ļ����ṩ��va_start,va_arg,va_end
	//���ڴ�ȡ�䳤������
	#define MAX_ARRAY_DIM 8 //ά�����ֵ
	typedef int ElemType;
	typedef struct{
		ElemType *base;
		int dim;
		int *bounds;
		int *constants;
	}Array;
}

//��Ԫ��˳����ʾϡ�����
namespace SpareMatrix{
	#define MAXSIZE 20	//����Ԫ�ظ������ֵΪ12500
	typedef int ElemType;
	typedef struct{
		int i;
		int j;//���±ꡢ���±�
		ElemType e;
	}Triple;
	typedef struct{
		Triple data[MAXSIZE + 1];	//������Ԫ���data[0]����
		int rownum, colnum, elemnum;	//���������������������Ԫ����
	}TSMatrix;//��Ԫ��˳����ʾϡ�����

	void TransposeSMatrix(TSMatrix M, TSMatrix&T);	//������Ԫ���ʾ��洢��ʾ����ϡ�����M��ת�þ���T
	void printTSMatrix(TSMatrix M);
}

//�����
namespace GList {
	typedef int AtomType;
	typedef enum{ATOM,LIST}ElemTag;	//ATOM == 0��ԭ�� LIST == 1���ӱ�
	typedef struct GLNode {
		ElemTag tag;
		union {
			AtomType atom;
			struct {
				struct GLNode* hp, * tp;
			}ptr;	//ptr�Ǳ����ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
		};
	}*GList;//���������
}