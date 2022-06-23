#ifndef STACK_H_
#include"BiTree.h"
typedef LinkTree::BiTree SElemnType;
typedef struct StackNode
{
	SElemnType data;
	struct StackNode*next;
}StackNode, *LinkStack;

void initLinkStack(LinkStack&S);
bool LinkStackEmpty(LinkStack S);
void pushLinkStack(LinkStack&S, SElemnType e);
void popLinkStack(LinkStack&S, SElemnType&e);
void getTop(LinkStack S, SElemnType&e);
#endif // !STACK_H_