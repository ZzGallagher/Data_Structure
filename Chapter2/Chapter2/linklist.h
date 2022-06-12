//单链表
#ifndef _SqList_

typedef int ElemType;	//int为ElemType，仅为数据类型举例用

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList;

void initList_L(LinkList&L);
void createList_Front(LinkList&L, int n);//头插法建立链表
void createList_Back(LinkList&L, int n);//尾插法建立链表
void destroyList_L(LinkList&L);
void clearList_L(LinkList&L);
bool isEmpty(LinkList L);
//bool isFull(LinkList L);不需要这样的函数
int getLength(LinkList L);
bool getElem(LinkList L, int i, ElemType&e);
int locateElem(LinkList L, ElemType e);
LNode* locateElem_add(LinkList L, ElemType e);
bool priorElem(LinkList L, ElemType cur_e, ElemType&pre_e);
bool nextElem(LinkList L, ElemType cur_e, ElemType&next_e);
void insertBack(LinkList &L, ElemType e);//尾插
void insertFront(LinkList &L, ElemType e);//头插
void deleteBack(LinkList &L, ElemType&e);//尾删
void deleteFront(LinkList&L, ElemType&e);//头删
void listInsert(LinkList&L, int i, ElemType e);//在第i个结点前插入元素e
void listDelete(LinkList&L, int i, ElemType&e);//删除第i个结点并用e返回
void printList_L(LinkList L);
#endif