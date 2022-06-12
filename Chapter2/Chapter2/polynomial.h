//多项式
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

void creatPolyn(polynomial&P, int m);//输入m项的系数和指数，建立表示一元多项式的有序链表P
void destroyPolyn(polynomial&P);//销毁一元多项式P
void printPolyn(polynomial P);//打印输出一元多项式P
int polynLength(polynomial P);//返回一元多项式P的项数
void addPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa+Pb，并销毁一元多项式Pb
void substractPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa-Pb，并销毁一元多项式Pb
void multiplyPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa*Pb，并销毁一元多项式Pb

#endif