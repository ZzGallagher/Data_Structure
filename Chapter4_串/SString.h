#pragma once
#ifndef SSTRING_H_

#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;

int index(SString S, SString T, int pos = 0);//�����Ӵ�T������S�е�pos���ַ�֮���λ�á������ڷ���0
#endif // !SSTRING_H_