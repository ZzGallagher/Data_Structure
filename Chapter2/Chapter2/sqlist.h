//顺序表
#include<iostream>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#ifndef _SQLIST_

struct Sqlist{
		int *elem;	//int为ElemType，仅为数据类型举例用
		int length;
		int listsize;	//容量
	};
	//常用
	void printSqList(Sqlist L);
	void createSqList(Sqlist&L);
	//ADT
	bool initSqList(Sqlist&L);	//初始化，为顺序表分配一个预定义大小的数组空间
	bool destorySqList(Sqlist&L);	//销毁
	bool clearSqList(Sqlist&L);	//清除元素
	bool isEmpty(Sqlist L);
	bool isFull(Sqlist L);
	int getLength(Sqlist L);
	bool getElem(Sqlist L, int i, int &e);	//用e返回L中第i位元素
	int locateElem(Sqlist L, int e);	//返回L中元素e的位序
	bool priorElem(Sqlist L, int cur_e, int &pre_e);
	bool nextElem(Sqlist L, int cur_e, int &next_e);
	bool listInsert(Sqlist &L, int i, int e);	//在L的第i位元素之前插入新的元素e
	bool listDelete(Sqlist &L, int i, int &e);	//删除L的第i个元素并用e返回
	//bool locateElem(Sqlist L, int e,compare());
	//bool traverse(Sqlist L,visit());
#endif