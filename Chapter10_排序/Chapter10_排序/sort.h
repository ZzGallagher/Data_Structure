#pragma once
#ifndef SORT_H_

#define MAXSIZE 20 //��¼������20��
typedef int KeyType; //��ؼ���Ϊ������(int��)
typedef int InfoType; //��������ϢΪ������(int��)

typedef  struct {	//ÿ����¼�Ľṹ
	KeyType key;
	InfoType otherinfo;
}RedType;

typedef struct{
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

void insertSort(SqList& L) {
	//ֱ�Ӳ�������
	//��С����
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key)	//����<��,��Ҫ��L.r[i]���������ӱ�
		{	//ǰi����¼��ɵ�����������ģ����Ҫ����ļ�¼��ǰһ���󣬡�>��i����һλ���ɣ�����Ҫ����
			L.r[0] = L.r[i];	//����Ϊ�ڱ�
			for (j = i - 1; L.r[0].key < L.r[j].key; j--) {
				L.r[j + 1] = L.r[j];
			}
			//forѭ������ʱ��jָ���һ���������ı�Ҫ����Ԫ�أ��ڱ���С�ļ�¼���ڱ���ֵӦ�ò��뵽�˼�¼��
			L.r[j + 1] = L.r[0];
		}
	}
}

void binInsertSort(SqList& L) {
	//�۰��������
	int low, mid, high;
	for (int i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];	//�����ڱ�
		low = 1;
		high = i - 1;
		while (low <= high)
		{	//ȷ������λ�� high+1
			mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; j--) {
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}

void shellSort(SqList& L, int dlta[], int t) {
	//����������dlta[0..t-1]��˳��L��ϣ������
	for (int k = 0; k < t; ++k) {
		shellInsert(L, dlta[k]);
	}
}
void shellInsert(SqList& L, int dk) {
	//��˳���L����һ������Ϊdk��shell����dkΪ��������
	for (int i = dk + 1; i <= L.length; ++i) {
		int j;
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j -= dk) {
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}

void bubbleSort1(SqList& L) {
	//ð������
	int i, j;
	RedType temp;
	for (i = 1; i <= L.length - 1; i++) {
		//�ܹ��Ƚ�length-1��
		for (j = 1; i <= L.length - i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				//����
				temp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = temp;
			}
		}
	}
}

void bubbleSort2(SqList& L) {
	//�Ľ���ð������
	//����ڱ� flag=0��ʾδ�����������������ֱ�ӷ���
	int i, j, flag = 1;
	RedType temp;
	for (i = 1; i <= L.length - 1 && flag == 1; i++) {
		flag = 0;
		for (j = 1; j <= L.length - i; j++) {
			temp = L.r[j];
			L.r[j] = L.r[j + 1];
			L.r[j + 1] = temp;
			flag = 1;
		}
	}
}

void qSort(SqList& L, int low, int high) {
	//�������򣬵���ʱlow=1��high=L.length
	if (low < high) {
		int pivotloc = partition(L, low, high);
		//��L.r[low..high]һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
		qSort(L, low, pivotloc - 1);//�Ե��ӱ�ݹ�����
		qSort(L, pivotloc + 1, high);//�Ը��ӱ�ݹ�����
	}
}
int partition(SqList& L, int low, int high) {
	//�����м�λ��
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey) {
			high--;
			L.r[low] = L.r[high];
		}
		while (low < high && L.r[low].key <= pivotkey) {
			low++;
			L.r[high] = L.r[low];
		}
	}
	L.r[low] = L.r[0];
	return low;
}

void selectSort(SqList&L){
	int k, j;
	RedType temp;
	//i��¼�ܵ�ѭ������������һλ����j��¼ÿ��ѭ���У����μ���㣬k�����
	for (int i = 1; i < L.length; i++){
		k = i;
		for (j = k; j <= L.length; j++){
			if (L.r[j].key < L.r[k].key)
				k = j;
		}
		if (k != i){
			temp = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = temp;
		}
	}
}


#endif // !SORT_H_