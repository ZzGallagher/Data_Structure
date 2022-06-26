#ifndef SEARCH_H_
#include<iostream>
typedef int KeyType;
typedef struct{
	KeyType key;
}ElemType;
typedef struct{
	ElemType *R;
	int length;
}SSTable;

int Search1_Seq(SSTable S, KeyType key){
	//顺序表查找
	for (int i = S.length; i >=1; i--)
	{
		if (S.R[i].key == key)
			return i;
	}
	return 0;
}
int Search2_Seq(SSTable S, KeyType key){
	//顺序表查找
	//添加哨兵
	S.R[0].key = key;
	int i;
	for (i = S.length; S.R[i].key != key; i--);
	return i;
}
int Search_Bin(SSTable S, KeyType key){
	//二分查找
	int low = 1;
	int high = S.length;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (S.R[mid].key == key)
			return mid;
		else if (key < S.R[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
int Search_Bin_Recur(SSTable S, KeyType key,int low,int high){
	//二分查找
	//递归算法
	if (low>high)
		return 0;
	int mid = (low + high) / 2;
	if (key == S.R[mid].key)
		return mid;
	else if (key < S.R[mid].key)
		return Search_Bin_Recur(S, key, low, mid - 1);
	else
		return Search_Bin_Recur(S, key, mid + 1, high);
}


#endif // !SEARCH_H_