//������
#ifndef _SqList_

typedef int ElemType;	//intΪElemType����Ϊ�������;�����

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList;

void initList_L(LinkList&L);
void createList_Front(LinkList&L, int n);//ͷ�巨��������
void createList_Back(LinkList&L, int n);//β�巨��������
void destroyList_L(LinkList&L);
void clearList_L(LinkList&L);
bool isEmpty(LinkList L);
//bool isFull(LinkList L);����Ҫ�����ĺ���
int getLength(LinkList L);
bool getElem(LinkList L, int i, ElemType&e);
int locateElem(LinkList L, ElemType e);
LNode* locateElem_add(LinkList L, ElemType e);
bool priorElem(LinkList L, ElemType cur_e, ElemType&pre_e);
bool nextElem(LinkList L, ElemType cur_e, ElemType&next_e);
void insertBack(LinkList &L, ElemType e);//β��
void insertFront(LinkList &L, ElemType e);//ͷ��
void deleteBack(LinkList &L, ElemType&e);//βɾ
void deleteFront(LinkList&L, ElemType&e);//ͷɾ
void listInsert(LinkList&L, int i, ElemType e);//�ڵ�i�����ǰ����Ԫ��e
void listDelete(LinkList&L, int i, ElemType&e);//ɾ����i����㲢��e����
void printList_L(LinkList L);
#endif