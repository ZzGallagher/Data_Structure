//顺序栈
#ifndef SQSTACK_H_

#define STACK_INIT_SIZE 10 //存储空间初始分配量
#define STACKINCREMENT 10	//存储空间分配增量
typedef int SElemType;
typedef struct{
	SElemType*base;	//在栈构造之前和销毁之后，base值为NULL
	SElemType*top;	//栈顶指针
	int stacksize;	//当前已分配的存储空间，以元素为单位
}SqStack;
//栈空：top==base
//栈满：top-base=stacksize

//方法
void initStack(SqStack&S);	//初始化
void destoryStack(SqStack&S);	//销毁顺序栈
void clearStack(SqStack&S);	//清空顺序栈
bool stackEmpty(SqStack S);	//判断栈是否为空
int stackLength(SqStack S);	//求栈的长度
void getTop(SqStack S, SElemType&e);	//用e返回S的栈顶元素
void push(SqStack&S, SElemType e);	//入栈
void pop(SqStack&S, SElemType&e);	//出栈
void printStack(SqStack S);
#endif