#include<iostream>
#include"SqStack.h"
using std::cout;
using std::cin;
using std::endl;
//方法定义
void initStack(SqStack&S){
	//初始化
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base){
		cout << "Error!Initialization Failed!\n";
		return;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void destoryStack(SqStack&S){
	//销毁顺序栈
	if (S.base){
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	else{
		cout << "Error!Stack Destroy Failed!\n";
		return;
	}
}
void clearStack(SqStack&S){
	//清空顺序栈
	if (S.base)
		S.top = S.base;	
}
bool stackEmpty(SqStack S){
	//判断栈是否为空
	if (S.top == S.base)
		return true;
	else
		return false;
}
int stackLength(SqStack S){
	//求栈的长度
	return S.stacksize;
}
void getTop(SqStack S, SElemType&e){
	//用e返回S的栈顶元素
	if (stackEmpty(S)){
		cout << "Empty Stack!No Elemnts to Get!\n";
		return;
	}
	e = *S.top;
}
void push(SqStack&S, SElemType e){
	//入栈
	if (S.top - S.base == S.stacksize){
		cout << "Full Stack!Cannot Push!\n";
		return;
	}
	*S.top++ = e;
}
void pop(SqStack&S, SElemType&e){
	//出栈
	if (stackEmpty(S)){
		cout << "Empty Stack!Cannot Pop!\n";
		return;
	}
	e = *(--S.top);
}
void printStack(SqStack S){
	//(S.top - S.base) / sizeof(SElemType)不必要这样做，cout会自动识别
	cout << "There's " << S.top - S.base << " elemnts in the Sequence Stack.\n";
	for (SElemType*p = S.base; p < S.top; p++)
		cout << *p << '\t';
	cout << endl;
	cout << "Stacksize = " << S.stacksize << endl;
}