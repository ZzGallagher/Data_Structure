#include<iostream>
#include"SString.h"
int main() {
	SString S = { "abcde",5 };
	SString T = { "abc",3 };
	int a = 3;
	a = index(S, T);
	std::cout << a << std::endl;
	return 0;
}