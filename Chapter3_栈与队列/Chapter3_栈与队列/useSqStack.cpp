#include<iostream>
#include"SqStack.h"
int main(){
	SqStack S;
	//≥ı ºªØ
	SElemType a = 0;
	initStack(S);
	push(S, 1);
	push(S, 2);
	printStack(S);
	pop(S, a);
	printStack(S);
	push(S, 3);
	push(S, 4);
	pop(S, a);
	printStack(S);
	return 0;
}