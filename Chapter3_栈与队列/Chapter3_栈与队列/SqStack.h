//˳��ջ
#ifndef SQSTACK_H_

#define STACK_INIT_SIZE 10 //�洢�ռ��ʼ������
#define STACKINCREMENT 10	//�洢�ռ��������
typedef int SElemType;
typedef struct{
	SElemType*base;	//��ջ����֮ǰ������֮��baseֵΪNULL
	SElemType*top;	//ջ��ָ��
	int stacksize;	//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;
//ջ�գ�top==base
//ջ����top-base=stacksize

//����
void initStack(SqStack&S);	//��ʼ��
void destoryStack(SqStack&S);	//����˳��ջ
void clearStack(SqStack&S);	//���˳��ջ
bool stackEmpty(SqStack S);	//�ж�ջ�Ƿ�Ϊ��
int stackLength(SqStack S);	//��ջ�ĳ���
void getTop(SqStack S, SElemType&e);	//��e����S��ջ��Ԫ��
void push(SqStack&S, SElemType e);	//��ջ
void pop(SqStack&S, SElemType&e);	//��ջ
void printStack(SqStack S);
#endif