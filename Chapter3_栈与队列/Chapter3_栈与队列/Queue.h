#ifndef QUEUE_H_

//循环队列
#define MAXQSIZE 6
//P63 约定少用一个元素空间，以“队列头指针在队列尾指针的下一位置（环状的下一位置）时作为队列“满”状态的标志
//MAXQSIZE = 6的队列只能存放5个元素
typedef int QElement;
struct SqQueue{
	QElement*base;
	int front;	//	头元素下标
	int rear;	//尾元素下标
};

void initQueue(SqQueue&Q);
void destoryQueue(SqQueue&Q);
void clearQueue(SqQueue&Q);
bool queueEmpty(SqQueue Q);
int queueLength(SqQueue Q);
void getHead_Queue(SqQueue Q, QElement&e);
void enQueue(SqQueue&Q, QElement e);	//入队
void deQueue(SqQueue&Q, QElement&e);	//出队
void printQueue(SqQueue Q);
////////
//链队//
////////
//链队的结点
typedef struct QNode{
	QElement data;
	struct QNode*next;
}QNode, *QueuePtr;
//链队
typedef struct{
	QNode* front;
	QNode* rear;
}LinkQueue;

void initLinkQueue(LinkQueue&Q);
void destoryLinkQueue(LinkQueue&Q);
void clearLinkQueue(LinkQueue&Q);
bool LinkQueueEmpty(LinkQueue Q);
int LinkQueueLength(LinkQueue Q);
void getHead_LinkQueue(LinkQueue Q, QElement&e);
void enLinkQueue(LinkQueue&Q, QElement e);	//入队
void deLinkQueue(LinkQueue&Q, QElement&e);	//出队 
void printLinkQueue(LinkQueue Q);

#endif // !QUEUE_H_