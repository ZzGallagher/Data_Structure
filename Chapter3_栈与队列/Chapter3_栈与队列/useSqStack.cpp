#include<iostream>
#include"SqStack.h"
void test1();
void conversionDECtoBIN();
int main(){
	conversionDECtoBIN();
	return 0;
}
void test1(){
	SqStack S;
	//≥ı ºªØ
	SElemType a = 0;
	initStack(S);
	push(S, 1);
	push(S, 2);
	printStack(S);
	pop(S, a);
	printStack(S);
	push(S, 3);
	push(S, 4);
	pop(S, a);
	printStack(S);
}
void conversionDECtoBIN(){
	using std::cout;
	using std::cin;
	using std::endl;
	SqStack S;
	initStack(S);
	int num, a;
	cout << "Enter a number in DEC:";
	cin >> num;
	while (num)
	{
		push(S, num % 2);
		num /= 2;
	}
	cout << "Converted to BIN:";
	while (!stackEmpty(S))
	{
		pop(S, a);
		cout << a;
	}
	cout << endl;
}