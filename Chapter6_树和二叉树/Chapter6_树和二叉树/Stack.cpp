#include<iostream>
#include"Stack.h"
using namespace std;
void initLinkStack(LinkStack&S){
	S = NULL;
}
bool LinkStackEmpty(LinkStack S){
	if (S == NULL)
		return true;
	else
		return false;
}
void pushLinkStack(LinkStack&S, SElemnType e){
	StackNode*p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
}
void popLinkStack(LinkStack&S, SElemnType&e){
	if (S == nullptr){
		cout << "Empty Stack!Cannot Pop!\n";
		return;
	}
	e = S->data;
	StackNode*p = S;
	S = S->next;
	delete p;
}
void getTop(LinkStack S, SElemnType&e) {
	//��e����S��ջ��Ԫ��
	if (!S){
		cout << "Empty Stack!No Elemnts to Get!\n";
		return;
	}
	e = S->data;
}