#ifndef QUEUE_H_

//ѭ������
#define MAXQSIZE 6
//P63 Լ������һ��Ԫ�ؿռ䣬�ԡ�����ͷָ���ڶ���βָ�����һλ�ã���״����һλ�ã�ʱ��Ϊ���С�����״̬�ı�־
//MAXQSIZE = 6�Ķ���ֻ�ܴ��5��Ԫ��
typedef int QElement;
struct SqQueue{
	QElement*base;
	int front;	//	ͷԪ���±�
	int rear;	//βԪ���±�
};

void initQueue(SqQueue&Q);
void destoryQueue(SqQueue&Q);
void clearQueue(SqQueue&Q);
bool queueEmpty(SqQueue Q);
int queueLength(SqQueue Q);
void getHead_Queue(SqQueue Q, QElement&e);
void enQueue(SqQueue&Q, QElement e);	//���
void deQueue(SqQueue&Q, QElement&e);	//����
void printQueue(SqQueue Q);
////////
//����//
////////
//���ӵĽ��
typedef struct QNode{
	QElement data;
	struct QNode*next;
}QNode, *QueuePtr;
//����
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
void enLinkQueue(LinkQueue&Q, QElement e);	//���
void deLinkQueue(LinkQueue&Q, QElement&e);	//���� 
void printLinkQueue(LinkQueue Q);

#endif // !QUEUE_H_