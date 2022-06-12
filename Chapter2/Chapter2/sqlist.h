//顺序表
#ifndef _SqList_

#define LIST_INIT_SIZE 5
#define LISTINCREMENT 2
typedef int ElemType;	//int为ElemType，仅为数据类型举例用

typedef struct {
		ElemType *elem;	
		int length;
		int listsize;	//容量
	}SqList;
	//常用
	void printSqList(SqList L);
	//void createSqList(SqList&L); //不需要这样一个函数，只需要初始化后，往其中插入新的值
	//ADT
	bool initSqList(SqList&L);	//初始化，为顺序表分配一个预定义大小的数组空间
	bool destorySqList(SqList&L);	//销毁
	bool clearSqList(SqList&L);	//清除元素
	bool isEmpty(SqList L);
	bool isFull(SqList L);
	int getLength(SqList L);
	bool getElem(SqList L, int i, ElemType &e);	//用e返回L中第i位元素
	int locateElem(SqList L, ElemType e);	//返回L中元素e的位序
	bool priorElem(SqList L, ElemType cur_e, ElemType &pre_e);
	bool nextElem(SqList L, ElemType cur_e, ElemType &next_e);
	bool expanSqList(SqList &L);	//给顺序表扩容
	bool insertBack(SqList &L, ElemType data);		//尾插，向尾部插入数据
	bool deleteBack(SqList &L, ElemType &data);		//尾删，删除最后一位数据，并用data返回
	bool insertFront(SqList &L, ElemType data);		//头插，在首位插入数据
	bool deleteFront(SqList &L, ElemType &data);	//头删，删除首位数据
	bool listInsert(SqList &L, int i, ElemType e);	//在L的第i位元素之前插入新的元素e
	bool listDelete(SqList &L, int i, ElemType &e);	//删除L的第i个元素并用e返回

	//bool locateElem(SqList L, int e,compare());
	//bool traverse(SqList L,visit());
#endif