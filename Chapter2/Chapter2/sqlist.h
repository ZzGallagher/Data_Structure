//˳���
#ifndef _SqList_

#define LIST_INIT_SIZE 5
#define LISTINCREMENT 2
typedef int ElemType;	//intΪElemType����Ϊ�������;�����

typedef struct {
		ElemType *elem;	
		int length;
		int listsize;	//����
	}SqList;
	//����
	void printSqList(SqList L);
	//void createSqList(SqList&L); //����Ҫ����һ��������ֻ��Ҫ��ʼ���������в����µ�ֵ
	//ADT
	bool initSqList(SqList&L);	//��ʼ����Ϊ˳������һ��Ԥ�����С������ռ�
	bool destorySqList(SqList&L);	//����
	bool clearSqList(SqList&L);	//���Ԫ��
	bool isEmpty(SqList L);
	bool isFull(SqList L);
	int getLength(SqList L);
	bool getElem(SqList L, int i, ElemType &e);	//��e����L�е�iλԪ��
	int locateElem(SqList L, ElemType e);	//����L��Ԫ��e��λ��
	bool priorElem(SqList L, ElemType cur_e, ElemType &pre_e);
	bool nextElem(SqList L, ElemType cur_e, ElemType &next_e);
	bool expanSqList(SqList &L);	//��˳�������
	bool insertBack(SqList &L, ElemType data);		//β�壬��β����������
	bool deleteBack(SqList &L, ElemType &data);		//βɾ��ɾ�����һλ���ݣ�����data����
	bool insertFront(SqList &L, ElemType data);		//ͷ�壬����λ��������
	bool deleteFront(SqList &L, ElemType &data);	//ͷɾ��ɾ����λ����
	bool listInsert(SqList &L, int i, ElemType e);	//��L�ĵ�iλԪ��֮ǰ�����µ�Ԫ��e
	bool listDelete(SqList &L, int i, ElemType &e);	//ɾ��L�ĵ�i��Ԫ�ز���e����

	//bool locateElem(SqList L, int e,compare());
	//bool traverse(SqList L,visit());
#endif