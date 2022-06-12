//����ʽ
#ifndef POLYNOMIAL_H_

struct term{
	float coef;
	int expn;
};
typedef term ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList;
typedef LinkList polynomial;

void creatPolyn(polynomial&P, int m);//����m���ϵ����ָ����������ʾһԪ����ʽ����������P
void destroyPolyn(polynomial&P);//����һԪ����ʽP
void printPolyn(polynomial P);//��ӡ���һԪ����ʽP
int polynLength(polynomial P);//����һԪ����ʽP������
void addPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa+Pb��������һԪ����ʽPb
void substractPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa-Pb��������һԪ����ʽPb
void multiplyPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa*Pb��������һԪ����ʽPb

#endif