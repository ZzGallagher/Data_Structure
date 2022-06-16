#pragma once
#ifndef SSTRING_H_

#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;

int index(SString S, SString T, int pos = 0);//返回子串T在主串S中第pos个字符之后的位置。不存在返回0
#endif // !SSTRING_H_