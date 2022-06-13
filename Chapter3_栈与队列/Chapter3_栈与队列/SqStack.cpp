#include<iostream>
#include"SqStack.h"
using std::cout;
using std::cin;
using std::endl;
//��������
void initStack(SqStack&S){
	//��ʼ��
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base){
		cout << "Error!Initialization Failed!\n";
		return;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void destoryStack(SqStack&S){
	//����˳��ջ
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
	//���˳��ջ
	if (S.base)
		S.top = S.base;	
}
bool stackEmpty(SqStack S){
	//�ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base)
		return true;
	else
		return false;
}
int stackLength(SqStack S){
	//��ջ�ĳ���
	return S.stacksize;
}
void getTop(SqStack S, SElemType&e){
	//��e����S��ջ��Ԫ��
	if (stackEmpty(S)){
		cout << "Empty Stack!No Elemnts to Get!\n";
		return;
	}
	e = *S.top;
}
void push(SqStack&S, SElemType e){
	//��ջ
	if (S.top - S.base == S.stacksize){
		cout << "Full Stack!Cannot Push!\n";
		return;
	}
	*S.top++ = e;
}
void pop(SqStack&S, SElemType&e){
	//��ջ
	if (stackEmpty(S)){
		cout << "Empty Stack!Cannot Pop!\n";
		return;
	}
	e = *(--S.top);
}
void printStack(SqStack S){
	//(S.top - S.base) / sizeof(SElemType)����Ҫ��������cout���Զ�ʶ��
	cout << "There's " << S.top - S.base << " elemnts in the Sequence Stack.\n";
	for (SElemType*p = S.base; p < S.top; p++)
		cout << *p << '\t';
	cout << endl;
	cout << "Stacksize = " << S.stacksize << endl;
}