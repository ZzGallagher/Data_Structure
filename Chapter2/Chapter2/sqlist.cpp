#include"SqList.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//class methods

void printSqList(SqList L){
	cout << "There's " << L.length << " elements in this SqList.\n";
	if (isEmpty(L))
		return;
	cout << "Here's the SqList:\n";
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << "\t";
	cout << endl;
}
bool initSqList(SqList&L){
	//��ʼ����Ϊ˳������һ��Ԥ�����С������ռ�
	L.elem = new int[LIST_INIT_SIZE];
	if (!L.elem)
		return false;
	L.length = 0;	//�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;		//��ʼ�洢����
	return true;
}
bool destorySqList(SqList&L){
	if (L.elem)
		delete L.elem;
	return true;
}
bool clearSqList(SqList&L){
	L.length = 0;
	return true;
}
bool isEmpty(SqList L){
	if (L.length == 0 )
		return true;
	else
		return false;
}
bool isFull(SqList L){
	if (L.length == L.listsize)
		return true;
	else
		return false;
}
int getLength(SqList L){
	return L.length;
}
bool getElem(SqList L, int i, ElemType &e){
	//��e����L�е�iλԪ��
	if (i<1 || i>L.length)
		return false;
	e = L.elem[i - 1];
	return true;
}
int locateElem(SqList L, ElemType e){
	//����L��Ԫ��e��λ��
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == e)
			return (i + 1);
	}
	cout << "Elem not found!\n";
	return -1;
}
bool priorElem(SqList L, ElemType cur_e, ElemType &pre_e){
	int i = locateElem(L, cur_e);
	if (!i)
		return false;
	pre_e = L.elem[i - 2];
	return true;
}
bool nextElem(SqList L, ElemType cur_e, ElemType &next_e){
	int i = locateElem(L, cur_e);
	if (!i)
		return false;
	next_e = L.elem[i];
	return true;
}
bool expanSqList(SqList &L){
	//��˳�������
	ElemType *newbase = new ElemType[LIST_INIT_SIZE + LISTINCREMENT];
	if (!newbase)
		return false;
	for (int i = 0; i < L.length; i++)
		newbase[i] = L.elem[i];
	L.elem = newbase;
	L.listsize += LISTINCREMENT;
	return true;
}
bool insertBack(SqList &L, ElemType data){
	//β�壬��β����������
	if (isFull(L)){
		expanSqList(L);
	}
	L.elem[L.length] = data;
	L.length++;
	return true;
}
bool deleteBack(SqList &L, ElemType &data){
	//βɾ��ɾ�����һλ���ݣ�����data����
	if (isEmpty(L))
		return false;
	data = L.elem[L.length-1];
	L.length--;
	return true;
}
bool insertFront(SqList &L, ElemType data){
	//ͷ�壬����λ��������
	if (isFull(L)){
		expanSqList(L);
	}
	ElemType *p = &L.elem[0];
	for (ElemType *q = &(L.elem[L.length - 1]); q >= p; --q)
		*(q + 1) = *q;
	*p = data;
	++L.length;
	return true;
}
bool deleteFront(SqList &L, ElemType &data){
	//ͷɾ��ɾ����λ����
	if (isEmpty(L))
		return false;
	data = L.elem[0];
	ElemType *p = &(L.elem[L.length - 1]);
	for (ElemType *q = L.elem; q <= p; ++q)
		*q = *(q + 1);
	--L.length;
	return true;
}
bool listInsert(SqList &L, int i, int e){
	//��L�ĵ�iλԪ��֮ǰ�����µ�Ԫ��e
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= L.listsize)
	{
		int* newbase = new int[LIST_INIT_SIZE + LISTINCREMENT];
		if (!newbase)
			return false;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *p = &L.elem[i - 1];
	for (int *q = &(L.elem[L.length - 1]); q >= p; --q)
		*(q + 1) = *q;
	*p = e;
	++L.length;
	return true;
}
bool listDelete(SqList &L, int i, int &e){
	//ɾ��L�ĵ�i��Ԫ�ز���e����
	if (i<1 || i>L.length + 1)	//������30��Ԫ�أ�L.length=30��i=31�Ϸ�
		return false;
	if (L.length >= L.listsize){
		int *newbase = new int[LIST_INIT_SIZE + LISTINCREMENT];
		if (!newbase)
			return false;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *p = &L.elem[L.length - 1];
	e = L.elem[i - 1];
	for (int *q = &L.elem[i - 1]; q <= p; ++q)
		*q = *(q + 1);
	--L.length;
	return true;
}

//void createSqList(SqList&L){
//	int i = 0;
//	cout << "Input elem: ";
//	while (cin >> L.elem[i++] && i<L.listsize){
//		if (cin.get() == '\n') break;
//		if (!cin.get() == '\n') continue;
//		cout << "Input elem: ";
//	}
//}
//bool locateElem(SqList L, int e,compare());
//bool traverse(SqList L,visit());