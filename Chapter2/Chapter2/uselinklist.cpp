#include<iostream>
#include"linklist.h"
using namespace std;
void test1();
void test2();
void test3();
int main(){
	//test1();
	//test2();
	test3();
	return 0;
}
void test1(){
	//��������
	LinkList L;
	initList_L(L);
	int a;	//����ֵ
	//β��
	cout << "β��\n";
	insertBack(L, 3);
	insertBack(L, 4);
	insertBack(L, 5);
	printList_L(L);
	//ͷ��
	cout << "ͷ��\n";
	insertFront(L, 2);
	insertFront(L, 1);
	printList_L(L);
	////βɾ
	//cout << "βɾ\n";
	//deleteBack(L, a);
	//printList_L(L);
	////ͷɾ
	//cout << "ͷɾ\n";
	//deleteFront(L, a);
	//printList_L(L);
	////���
	//cout << "���\n";
	//clearList_L(L);
	//printList_L(L);
	//ȡֵ
	cout << "��λ��ȡֵ\n";
	getElem(L, 2, a);
	cout << "a = " << a << endl;
	//����
	cout << "���ҷ���λ��\n";
	a = locateElem(L, 3);
	cout << "Elem 3 is the No." << a << "." << endl;
	//����
	cout << "���ҷ��ص�ַ\n";
	LNode*ptr;
	ptr = locateElem_add(L, 3);
	cout << ptr << endl;
	//ǰ��
	cout << "ǰ��\n";
	priorElem(L, 2, a);
	cout << "The elem before elem 2 is " << a << "." << endl;
	//���
	cout << "���\n";
	nextElem(L, 2, a);
	cout << "The elem after elem 2 is " << a << "." << endl;
}
void test2(){
	//ͷ�巨��β�巨��������
	LinkList L;
	//ͷ�巨
	cout << "ͷ�巨\n";
	createList_Front(L, 5);
	printList_L(L);
	//β�巨
	cout << "β�巨\n";
	createList_Back(L, 5);
	printList_L(L);
}
void test3(){
	//����ɾ��
	LinkList L;
	initList_L(L);
	insertBack(L, 3);
	insertBack(L, 4);
	insertBack(L, 5);
	insertFront(L, 2);
	insertFront(L, 1);
	printList_L(L);
	//����
	cout << "����\n";
	listInsert(L, 3, 0);
	printList_L(L);
	//ɾ��
	int a;
	cout << "ɾ��\n";
	listDelete(L, 3, a);
	printList_L(L);
}