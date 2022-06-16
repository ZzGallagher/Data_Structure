#include<iostream>
#include"SString.h"

int index(SString S, SString T, int pos) {
	//返回子串T在主串S中第pos个字符之后的位置。不存在返回0
	int i = pos, j = 1;
	while (i<=S.length && j<=T.length)
	{
		if (S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length)
		return i - T.length;
	else
		return 0;
}