#include<iostream>
#include"Stack.h"
#include"BiTree.h"

using std::cout;
using std::endl;

void LinkTree::printRootNode(BiTree T){
	//��ӡ���ڵ��ֵ
	//�����ʺ���visit()��
	if (T == nullptr)
		return;
	else
	{
		cout << T->data << '\t';
	}
}
void LinkTree::preOrderTraverse(BiTree T){
	//����ݹ����
	if (T == nullptr)
		return;
	else
	{
		printRootNode(T);
		preOrderTraverse(T->lchild);//�ݹ����������
		preOrderTraverse(T->rchild);//�ݹ����������
	}
}
void LinkTree::inOrderTraverse(BiTree T){
	//����ݹ����
	if (T == nullptr)
		return;
	else
	{
		inOrderTraverse(T->lchild);
		printRootNode(T);
		inOrderTraverse(T->rchild);
	}
}
void LinkTree::postOrderTraverse(BiTree T){
	//����ݹ����
	if (T == nullptr)
		return;
	else
	{
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		printRootNode(T);
	}
}
bool LinkTree::nonRec_inOrderTraverse(BiTree T){
	//����ǵݹ����
	BiTree p;
	p = T;
	BiTree q = nullptr;
	LinkStack S;
	initLinkStack(S);
	while (p || !LinkStackEmpty(S))
	{
		if (p)
		{
			pushLinkStack(S, p);
			p->lchild;
		}
		else
		{
			popLinkStack(S, q);
			printRootNode(q);
			p = q->rchild;
		}
	}
	return true;
}