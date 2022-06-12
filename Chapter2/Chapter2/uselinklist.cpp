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
	//基础功能
	LinkList L;
	initList_L(L);
	int a;	//接收值
	//尾插
	cout << "尾插\n";
	insertBack(L, 3);
	insertBack(L, 4);
	insertBack(L, 5);
	printList_L(L);
	//头插
	cout << "头插\n";
	insertFront(L, 2);
	insertFront(L, 1);
	printList_L(L);
	////尾删
	//cout << "尾删\n";
	//deleteBack(L, a);
	//printList_L(L);
	////头删
	//cout << "头删\n";
	//deleteFront(L, a);
	//printList_L(L);
	////清除
	//cout << "清除\n";
	//clearList_L(L);
	//printList_L(L);
	//取值
	cout << "按位序取值\n";
	getElem(L, 2, a);
	cout << "a = " << a << endl;
	//查找
	cout << "查找返回位序\n";
	a = locateElem(L, 3);
	cout << "Elem 3 is the No." << a << "." << endl;
	//查找
	cout << "查找返回地址\n";
	LNode*ptr;
	ptr = locateElem_add(L, 3);
	cout << ptr << endl;
	//前序
	cout << "前序\n";
	priorElem(L, 2, a);
	cout << "The elem before elem 2 is " << a << "." << endl;
	//后继
	cout << "后继\n";
	nextElem(L, 2, a);
	cout << "The elem after elem 2 is " << a << "." << endl;
}
void test2(){
	//头插法和尾插法建立链表
	LinkList L;
	//头插法
	cout << "头插法\n";
	createList_Front(L, 5);
	printList_L(L);
	//尾插法
	cout << "尾插法\n";
	createList_Back(L, 5);
	printList_L(L);
}
void test3(){
	//插入删除
	LinkList L;
	initList_L(L);
	insertBack(L, 3);
	insertBack(L, 4);
	insertBack(L, 5);
	insertFront(L, 2);
	insertFront(L, 1);
	printList_L(L);
	//插入
	cout << "插入\n";
	listInsert(L, 3, 0);
	printList_L(L);
	//删除
	int a;
	cout << "删除\n";
	listDelete(L, 3, a);
	printList_L(L);
}