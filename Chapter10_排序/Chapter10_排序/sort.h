#pragma once
#ifndef SORT_H_

#define MAXSIZE 20 //记录不超过20个
typedef int KeyType; //设关键字为整型量(int型)
typedef int InfoType; //设其他信息为整型量(int型)

typedef  struct {	//每个记录的结构
	KeyType key;
	InfoType otherinfo;
}RedType;

typedef struct{
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

void insertSort(SqList& L) {
	//直接插入排序
	//从小到大
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key)	//若“<”,需要将L.r[i]插入有序子表
		{	//前i个记录组成的序列是有序的，如果要插入的记录比前一个大，“>”i后移一位即可，不需要排序
			L.r[0] = L.r[i];	//复制为哨兵
			for (j = i - 1; L.r[0].key < L.r[j].key; j--) {
				L.r[j + 1] = L.r[j];
			}
			//for循环结束时，j指向第一个遍历到的比要插入元素（哨兵）小的记录，哨兵的值应该插入到此记录后
			L.r[j + 1] = L.r[0];
		}
	}
}

void binInsertSort(SqList& L) {
	//折半插入排序
	int low, mid, high;
	for (int i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];	//设置哨兵
		low = 1;
		high = i - 1;
		while (low <= high)
		{	//确定插入位置 high+1
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
	//按增量序列dlta[0..t-1]对顺序L作希尔排序
	for (int k = 0; k < t; ++k) {
		shellInsert(L, dlta[k]);
	}
}
void shellInsert(SqList& L, int dk) {
	//对顺序表L进行一趟增量为dk的shell排序，dk为步长因子
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
	//冒泡排序
	int i, j;
	RedType temp;
	for (i = 1; i <= L.length - 1; i++) {
		//总共比较length-1趟
		for (j = 1; i <= L.length - i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				//交换
				temp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = temp;
			}
		}
	}
}

void bubbleSort2(SqList& L) {
	//改进的冒泡排序
	//添加哨兵 flag=0表示未发生交换，排序完成直接返回
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
	//快速排序，调用时low=1，high=L.length
	if (low < high) {
		int pivotloc = partition(L, low, high);
		//将L.r[low..high]一分为二，pivotloc为枢轴元素排好序的位置
		qSort(L, low, pivotloc - 1);//对低子表递归排序
		qSort(L, pivotloc + 1, high);//对高子表递归排序
	}
}
int partition(SqList& L, int low, int high) {
	//返回中间位置
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
	//i记录总的循环次数（到哪一位），j记录每次循环中，依次检查结点，k做标记
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