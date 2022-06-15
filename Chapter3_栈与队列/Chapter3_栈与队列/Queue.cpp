
#include<iostream>
#include"Queue.h"
using std::cout;
using std::cin;
using std::endl;
////////////
//循环队列//
////////////
void initQueue(SqQueue&Q){
	Q.base = new QElement[MAXQSIZE];
	if (!Q.base){
		cout << "Error!Initialization Failed!\n";
		return;
	}
	Q.front = Q.rear = 0;
}
void destoryQueue(SqQueue&Q){
	if (Q.base)
		delete Q.base;
	else{
		cout << "Failed to destory Queue!\n";
		return;
	}
}
void clearQueue(SqQueue&Q){
	Q.rear = Q.front;
}
bool queueEmpty(SqQueue Q){
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}
int queueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;  
}
void getHead_Queue(SqQueue Q, QElement&e){
	if (Q.front != Q.rear)
		e = Q.base[Q.front];
}
void enQueue(SqQueue&Q, QElement e){
	//入队
	if ((Q.rear + 1) % MAXQSIZE == Q.front){
		cout << "Full queue!Cannot enqueue!\n";
		return;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE; 
}
void deQueue(SqQueue&Q, QElement&e){
	//出队
	if (Q.front == Q.rear){
		//空表的判断条件
		cout << "Empty queue!Cannot dequeue!\n";
		return;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
}
void printQueue(SqQueue Q){
	cout << "There's " << (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE << " elemnts in the Queue:\n";
	int p = Q.front;
	while (p != Q.rear)
	{
		cout << Q.base[p] << '\t';
		p = (p + 1) % MAXQSIZE;
	}
	cout << endl;
}

/////////
//链队//
////////
/*typedef struct QNode{
	QElement data;
	struct QNode*next;
}QNode, *QueuePtr;
//链队
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;*/

void initLinkQueue(LinkQueue&Q){
	Q.front = Q.rear = new QNode;
	if (!Q.front){
		cout << "Error!Initialization Failed!\n";
		return;
	}
	Q.front->next = nullptr;
}
void destoryLinkQueue(LinkQueue&Q){
	while (Q.front)
	{
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}
void clearLinkQueue(LinkQueue&Q){
	Q.rear = Q.front;
}
bool LinkQueueEmpty(LinkQueue Q){
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
int LinkQueueLength(LinkQueue Q){
	int i=0;
	QNode*p = Q.front->next;
	while (p)
	{
		++i;
		p = p->next;
	}
	return i;
}
void getHead_LinkQueue(LinkQueue Q,QElement&e){
	if (Q.front != Q.rear)
		e = Q.front->next->data;
}
void enLinkQueue(LinkQueue&Q, QElement e){
	//入队
	QNode*p = new QNode;
	if (!p){
		cout << " ERROR! Memory Allocation Failed!\n";
		return;
	}
	p->data = e;
	p->next = nullptr;
	Q.rear->next = p;
	Q.rear = p;
}
void deLinkQueue(LinkQueue&Q, QElement&e){
	//出队 
	if (Q.front == Q.rear){
		//空表的判断条件
		cout << "Empty queue!Cannot dequeue!\n";
		return;
	}
	QNode*p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
}
void printLinkQueue(LinkQueue Q){
	QNode*p = Q.front->next;
	int i = LinkQueueLength(Q);
	cout << "There's " << i << " elemnts in the LinkQueue:\n";
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}