//˳���
#include<iostream>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#ifndef _SQLIST_

struct Sqlist{
		int *elem;	//intΪElemType����Ϊ�������;�����
		int length;
		int listsize;	//����
	};
	//����
	void printSqList(Sqlist L);
	void createSqList(Sqlist&L);
	//ADT
	bool initSqList(Sqlist&L);	//��ʼ����Ϊ˳������һ��Ԥ�����С������ռ�
	bool destorySqList(Sqlist&L);	//����
	bool clearSqList(Sqlist&L);	//���Ԫ��
	bool isEmpty(Sqlist L);
	bool isFull(Sqlist L);
	int getLength(Sqlist L);
	bool getElem(Sqlist L, int i, int &e);	//��e����L�е�iλԪ��
	int locateElem(Sqlist L, int e);	//����L��Ԫ��e��λ��
	bool priorElem(Sqlist L, int cur_e, int &pre_e);
	bool nextElem(Sqlist L, int cur_e, int &next_e);
	bool listInsert(Sqlist &L, int i, int e);	//��L�ĵ�iλԪ��֮ǰ�����µ�Ԫ��e
	bool listDelete(Sqlist &L, int i, int &e);	//ɾ��L�ĵ�i��Ԫ�ز���e����
	//bool locateElem(Sqlist L, int e,compare());
	//bool traverse(Sqlist L,visit());
#endif