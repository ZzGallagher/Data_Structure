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
		struct BiNode*lchild, *rchild;	//��������
	}BiNode, *BiTree;
	//����
	void printRootNode(BiTree T);	//��ӡ���ڵ��ֵ //�����ʺ���visit()��
	void preOrderTraverse(BiTree T);	//����ݹ����
	void inOrderTraverse(BiTree T);	//����ݹ����
	void postOrderTraverse(BiTree T);	//����ݹ����
	bool nonRec_inOrderTraverse(BiTree T);	//����ǵݹ����
}