#include<iostream>
#include"Stack.h"
#include"BiTree.h"

using std::cout;
using std::endl;

void LinkTree::printRootNode(BiTree T){
	//打印根节点的值
	//作访问函数visit()用
	if (T == nullptr)
		return;
	else
	{
		cout << T->data << '\t';
	}
}
void LinkTree::preOrderTraverse(BiTree T){
	//先序递归遍历
	if (T == nullptr)
		return;
	else
	{
		printRootNode(T);
		preOrderTraverse(T->lchild);//递归遍历左子树
		preOrderTraverse(T->rchild);//递归遍历左子树
	}
}
void LinkTree::inOrderTraverse(BiTree T){
	//中序递归遍历
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
	//后序递归遍历
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
	//中序非递归遍历
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