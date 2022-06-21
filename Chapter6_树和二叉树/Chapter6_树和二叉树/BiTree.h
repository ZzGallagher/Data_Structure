//顺序存储二叉树
namespace SqBiTree{
#define MAX_TREE_SIZE 100 //最大结点数
	typedef int TElemType;
	typedef TElemType SqBiTree[MAX_TREE_SIZE];
	SqBiTree bt;
}

//链式存储二叉树
namespace LinkTree{
	typedef int TElemType;
	typedef struct BiNode{
		TElemType data;
		struct BiNode*lchild, *rchild;
	}BiNode, *BiTree;
}