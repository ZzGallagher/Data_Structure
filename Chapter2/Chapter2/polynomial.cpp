#include<iostream>
#include"polynomial.h"
using namespace std;

void creatPolyn(polynomial&P, int m);//����m���ϵ����ָ����������ʾһԪ����ʽ����������P
void destroyPolyn(polynomial&P);//����һԪ����ʽP
void printPolyn(polynomial P);//��ӡ���һԪ����ʽP
int polynLength(polynomial P);//����һԪ����ʽP������
void addPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa+Pb��������һԪ����ʽPb
void substractPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa-Pb��������һԪ����ʽPb
void multiplyPolyn(polynomial&Pa, polynomial&Pb);//Pa=Pa*Pb��������һԪ����ʽPb