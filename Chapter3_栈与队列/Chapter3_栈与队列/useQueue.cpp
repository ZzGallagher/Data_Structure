#include<iostream>
#include"Queue.h"
using std::cout;
using std::cin;
using std::endl;
void test1(void);
void test2(void);
int main(){
	//test1();
	test2();
	return 0;
}
void test1(){
	//顺序队列
	SqQueue Q;
	int a;
	initQueue(Q);
	cout << "顺序队列\n";
	//进队
	enQueue(Q, 1);
	enQueue(Q, 2);
	enQueue(Q, 3);
	enQueue(Q, 4);
	enQueue(Q, 5);
	printQueue(Q);
	//出队
	deQueue(Q, a);
	deQueue(Q, a);
	printQueue(Q);
	//gethead
	enQueue(Q, 1);
	enQueue(Q, 2);
	printQueue(Q);
	getHead_Queue(Q, a);
	cout << a << endl;
	cout << "Length = " << queueLength(Q) << endl;
}
void test2(){
	//链队
	LinkQueue Q;
	int a;
	initLinkQueue(Q);
	cout << "链队\n";
	//进队
	enLinkQueue(Q, 1);
	enLinkQueue(Q, 2);
	enLinkQueue(Q, 3);
	enLinkQueue(Q, 4);
	enLinkQueue(Q, 5);
	printLinkQueue(Q);
	//出队
	deLinkQueue(Q, a);
	deLinkQueue(Q, a);
	printLinkQueue(Q);
	//gethead
	enLinkQueue(Q, 1);
	enLinkQueue(Q, 2);
	printLinkQueue(Q);
	getHead_LinkQueue(Q, a);
	cout << a << endl;
	cout << "Length = " << LinkQueueLength(Q) << endl;
}