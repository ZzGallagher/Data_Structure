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
		struct BiNode*lchild, *rchild;	//二叉链表
	}BiNode, *BiTree;
	//方法
	void printRootNode(BiTree T);	//打印根节点的值 //作访问函数visit()用
	void preOrderTraverse(BiTree T);	//先序递归遍历
	void inOrderTraverse(BiTree T);	//中序递归遍历
	void postOrderTraverse(BiTree T);	//后序递归遍历
	bool nonRec_inOrderTraverse(BiTree T);	//中序非递归遍历
}