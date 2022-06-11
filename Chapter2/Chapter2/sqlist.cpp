#include"sqlist.h"

using std::cin;
using std::cout;
using std::endl;

//class methods
void createSqList(Sqlist&L){
	int i = 0;
	cout << "Input elem: ";
	while (cin >> L.elem[i++] && i<L.listsize){
		if (cin.get() == '\n') break;
		if (!cin.get() == '\n') continue;
		cout << "Input elem: ";
	}
}
void printSqList(Sqlist L){
	cout << "Here's the SqList:\n";
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << " , ";
	cout << endl;
	cout << "There's " << L.length << " elements in this sqlist.\n";
}
bool initSqList(Sqlist&L){
	//��ʼ����Ϊ˳������һ��Ԥ�����С������ռ�
	L.elem = new int[LIST_INIT_SIZE];
	if (!L.elem)
		return false;
	L.length = 0;	//�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;		//��ʼ�洢����
	return true;
}
bool destorySqList(Sqlist&L){
	if (L.elem)
		delete L.elem;
	return true;
}
bool clearSqList(Sqlist&L){
	L.length = 0;
	return true;
}
bool isEmpty(Sqlist L){
	if (L.length == L.listsize)
		return true;
	else
		return false;
}
bool isFull(Sqlist L){
	if (L.length == 0)
		return true;
	else
		return false;
}
int getLength(Sqlist L){
	return L.length;
}
bool getElem(Sqlist L, int i, int &e){
	//��e����L�е�iλԪ��
	if (i<1 || i>L.length)
		return false;
	e = L.elem[i - 1];
	return true;
}
int locateElem(Sqlist L, int e){
	//����L��Ԫ��e��λ��
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == e)
			return (i + 1);
	}
	cout << "Elem not found!\n";
	return 0;
}
bool priorElem(Sqlist L, int cur_e, int &pre_e){
	int i = locateElem(L, cur_e);
	if (!i)
		return false;
	pre_e = L.elem[i - 2];
	return true;
}
bool nextElem(Sqlist L, int cur_e, int &next_e){
	int i = locateElem(L, cur_e);
	if (!i)
		return false;
	next_e = L.elem[i];
	return true;
}
bool listInsert(Sqlist &L, int i, int e){
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
bool listDelete(Sqlist &L, int i, int &e){
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
	return true;
}
//bool locateElem(Sqlist L, int e,compare());
//bool traverse(Sqlist L,visit());