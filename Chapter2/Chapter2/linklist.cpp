//只有头指针的单链表
#include<iostream>
#include"linklist.h"
using namespace std;

void initList_L(LinkList&L)
{
	L = new LNode;
	L->next = nullptr;
}
void createList_Front(LinkList&L, int n){
	//头插法建立链表
	//需要一个头指针辅助，直接使用L
	L = new LNode;
	L->next = nullptr;
	for (int i = n; i > 0; --i){
		LNode *p = new LNode;
		cout << "Enter data:";
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
void createList_Back(LinkList&L, int n){
	//尾插法建立链表
	//需要一个尾指针辅助
	L = new LNode;
	L->next = nullptr;
	LNode *r = L;
	for (int i = 0; i < n; i++){
		LNode *p = new LNode;
		cout << "Enter data:";
		cin >> p->data;
		//if (cin.get() == '\n')
		//	continue;
		p->next = nullptr;
		r->next = p;
		r = p;
	}
}
void destroyList_L(LinkList&L){
	//销毁链表，从头指针开始依次释放虽有结点
	LNode*p;
	while (L){
		p = L;
		L = L->next;
		delete p;
	}
}
void clearList_L(LinkList&L){
	//除头指针、头结点之外销毁其他所有节点
	LNode*p, *q;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = nullptr;
}
bool isEmpty(LinkList L){
	if (L->next == nullptr)
		return true;
	else
		return false;
}
int getLength(LinkList L){
	int i = 0;
	LNode*p = L->next;
	while (p){
		++i;
		p = p->next;
	}
	return i;
}
bool getElem(LinkList L, int i, ElemType&e){
	LNode*p = L->next;
	int j = 1;
	while (p && j < i){
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return false;
	e = p->data;
	return true;
}
int locateElem(LinkList L, ElemType e){
	//按值查找，返回位序
	LNode*p = L->next;
	int j = 1;
	while (p)
	{
		if (p->data == e)
			return j;
		p = p->next;
		++j;
	}
	cout << "Data not found!\n";
	return 0;
}
LNode* locateElem_add(LinkList L, ElemType e){
	//按值查找，返回该结点地址
	LNode*p = L->next;
	while (p){
		if (p->data == e)
			return p;
		p = p->next;
	}
	cout << "Data not found!\n";
	return nullptr;
}
bool priorElem(LinkList L, ElemType cur_e, ElemType&pre_e){
	//用pre_e返回cur_e的前驱，要求cur_e不为首元结点
	LNode*p, *q;
	p = L;
	q = p->next;
	while (q && q->data!=cur_e)
	{
		p = p->next;
		q = p->next;
	}
	if (!q)
		return false;
	pre_e = p->data;
	return true;
}
bool nextElem(LinkList L, ElemType cur_e, ElemType&next_e){
	//用next_e返回cur_e的后继，要求cur_e不为尾结点
	LNode*p, *q;
	p = L->next;
	q = p->next;
	while (p && p->data !=cur_e)
	{
		p = p->next;
		q = p->next;
	}
	if (!q)
		return false;
	next_e = q->data;
	return true;
}
void insertBack(LinkList &L, ElemType e){
	//尾插
	LNode*s = new LNode;
	s->data = e;
	s->next = nullptr;
	LNode*r = new LNode; 
	//考虑空链表中，r是空指针的情况
	r = L->next;	//尾指针
	if (!r){
		L->next = s;
	}
	else
	{
		while (r->next)	//若r是空指针，会报错
		{
			r = r->next;
		}
		r->next = s;
	}
}
void insertFront(LinkList &L, ElemType e){
	//头插
	LNode*s = new LNode;
	s->data = e;
	s->next = L->next;
	L->next = s;
}
void deleteBack(LinkList &L, ElemType&e){
	//尾删
	LNode*r, *p;
	p = L->next;
	if (!p)
	{
		//考虑空表情况
		cout << "已经是空表！\n";
		return;
	}
	else
	{
		r = p->next;
		while (r->next){
			p = p->next;
			r = p->next;
		}
		p->next = nullptr;
		delete r;
	}
}
void deleteFront(LinkList&L, ElemType&e){
	//头删
	LNode*p = L->next;
	L->next = p->next;
	delete p;
}
void listInsert(LinkList&L, int i, ElemType e){
	//在第i个结点前插入元素e
	LNode*s = new LNode;
	s->data = e;
	LNode*p = L;
	int j = 0;	//此处j=0还是j=1需要具体情况考虑
	//若p=L，则j=0;p=L->next,则j=1
	//即j等于p所指结点的序号
	while (p && j < i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > (i - 1)){
		cout << "Error!\n";
		return;
	}
	s->next = p->next;
	p->next = s;
}
void listDelete(LinkList&L, int i, ElemType&e){
	//删除第i个结点并用e返回
	LNode*p = L;
	int j = 0;
	//p需要指向要删除的第i个结点的前驱
	while (p->next && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > (i - 1)){
		cout << "Error!\n";
		return;
	}
	LNode*q = p->next;	//q指向要删除的结点（第i个）
	p->next = q->next;
	delete q;
}
void printList_L(LinkList L){
	LNode*p = L->next;
	if (!p){
		cout << "The linklist is empty.\n";
		return;
	}
	cout << "There's " << getLength(L) << " elements in the linklist:\n";
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}