#include<iostream>
#include"SqList.h"
using namespace std;
void test1(void);
void test2(void);
int main(){
	test1();
	test2();
	return 0;
}
void test1(void){
	//测试基本功能
	SqList L;
	initSqList(L);
	for (int i = 0; i < 8; i++)
		//控制插入几个数字
		insertBack(L, i + 1);
	//clearSqList(L);
	printSqList(L);
	int n = getLength(L);
	cout << "length = " << n << endl;
	cout << "listsize = " << L.listsize << endl;
	//getElem,
	int a = 0;
	getElem(L, 4, a);
	cout << "N0.4 elem is " << a << endl;
	//locateElem
	cout << locateElem(L, 9) << endl;
	//prior
	a = 0;
	priorElem(L, 7, a);
	cout << a << endl;
	//next
	a = 0;
	nextElem(L, 7, a);
	cout << a << endl;
}
void test2(){
	//测试插入删除
	SqList L;
	int a;
	initSqList(L);
	cout << "尾插\n";
	insertBack(L, 1);
	insertBack(L, 2);
	insertBack(L, 3);
	insertBack(L, 4);
	printSqList(L);
	cout << "头插\n";
	insertFront(L, 3);
	printSqList(L);
	cout << "尾删\n";
	deleteBack(L, a);
	printSqList(L);
	cout << "头删\n";
	deleteFront(L, a);
	printSqList(L);
	cout << "插入\n";
	listInsert(L, 2, 9);
	printSqList(L);
	cout << "删除\n";
	listDelete(L, 2, a);
	printSqList(L);
}