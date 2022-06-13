#ifndef LINKSTACK_H_

typedef int SElemnType;
typedef struct StackNode
{
	SElemnType data;
	struct StackNode*next;
}StackNode,*LinkStack;

void initLinkStack(LinkStack&S);
bool LinkStackEmpty(LinkStack S);
void pushLinkStack(LinkStack&S, SElemnType e);
void popLinkStack(LinkStack&S, SElemnType&e);
void getTop(LinkStack S, SElemnType&e);
#endif // !LINKSTACK_H_
