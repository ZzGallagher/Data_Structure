//˳��洢������
namespace SqBiTree{
#define MAX_TREE_SIZE 100 //�������
	typedef int TElemType;
	typedef TElemType SqBiTree[MAX_TREE_SIZE];
	SqBiTree bt;
}

//��ʽ�洢������
namespace LinkTree{
	typedef int TElemType;
	typedef struct BiNode{
		TElemType data;
		struct BiNode*lchild, *rchild;
	}BiNode, *BiTree;
}