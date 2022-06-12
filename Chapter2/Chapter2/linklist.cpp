//ֻ��ͷָ��ĵ�����
#include<iostream>
#include"linklist.h"
using namespace std;

void initList_L(LinkList&L)
{
	L = new LNode;
	L->next = nullptr;
}
void createList_Front(LinkList&L, int n){
	//ͷ�巨��������
	//��Ҫһ��ͷָ�븨����ֱ��ʹ��L
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
	//β�巨��������
	//��Ҫһ��βָ�븨��
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
	//����������ͷָ�뿪ʼ�����ͷ����н��
	LNode*p;
	while (L){
		p = L;
		L = L->next;
		delete p;
	}
}
void clearList_L(LinkList&L){
	//��ͷָ�롢ͷ���֮�������������нڵ�
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
	//��ֵ���ң�����λ��
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
	//��ֵ���ң����ظý���ַ
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
	//��pre_e����cur_e��ǰ����Ҫ��cur_e��Ϊ��Ԫ���
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
	//��next_e����cur_e�ĺ�̣�Ҫ��cur_e��Ϊβ���
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
	//β��
	LNode*s = new LNode;
	s->data = e;
	s->next = nullptr;
	LNode*r = new LNode; 
	//���ǿ������У�r�ǿ�ָ������
	r = L->next;	//βָ��
	if (!r){
		L->next = s;
	}
	else
	{
		while (r->next)	//��r�ǿ�ָ�룬�ᱨ��
		{
			r = r->next;
		}
		r->next = s;
	}
}
void insertFront(LinkList &L, ElemType e){
	//ͷ��
	LNode*s = new LNode;
	s->data = e;
	s->next = L->next;
	L->next = s;
}
void deleteBack(LinkList &L, ElemType&e){
	//βɾ
	LNode*r, *p;
	p = L->next;
	if (!p)
	{
		//���ǿձ����
		cout << "�Ѿ��ǿձ�\n";
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
	//ͷɾ
	LNode*p = L->next;
	L->next = p->next;
	delete p;
}
void listInsert(LinkList&L, int i, ElemType e){
	//�ڵ�i�����ǰ����Ԫ��e
	LNode*s = new LNode;
	s->data = e;
	LNode*p = L;
	int j = 0;	//�˴�j=0����j=1��Ҫ�����������
	//��p=L����j=0;p=L->next,��j=1
	//��j����p��ָ�������
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
	//ɾ����i����㲢��e����
	LNode*p = L;
	int j = 0;
	//p��Ҫָ��Ҫɾ���ĵ�i������ǰ��
	while (p->next && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > (i - 1)){
		cout << "Error!\n";
		return;
	}
	LNode*q = p->next;	//qָ��Ҫɾ���Ľ�㣨��i����
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