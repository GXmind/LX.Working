#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SElemType char
#define MaxSize 1000
using namespace std;

typedef struct {
	SElemType *top, *base;
	int size;
} *SqStack;

int  InitStack(SqStack &S) {
	//构造一个空栈
	S = (SqStack)malloc(sizeof(SqStack));
	S->base = (SElemType*)malloc(sizeof(SElemType) * MaxSize);
	if (!S->base)
		return false;
	S->size = MaxSize;
	S->top = S->base;
	return true;
}

bool Push(SqStack S, SElemType e) {
	//入栈：插入元素e
	if (S->top - S->base == MaxSize)
		return false;
	else {
		*(S->top++) = e;
	}
}

int Pop(SqStack S, SElemType &e) {
	//出栈 ：返回e
	if (S->top == S->base)
		return false;
	else {
		e = *(--S->top);
		return true;
	}
}

bool PrintStack(SqStack S) {
	SElemType *p;
	if (S->top == S->base) return false;
	p = S->top;
	while (p > S->base) {
		p--;
		cout << *p;
	}
	return true;
}

int main() {
	SqStack h, s;
	string str;
	int n, a, b;
	while(cin >> n){
	a = b = 0;
	InitStack(h);
	InitStack(s);
	cin >> str;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] != '#') {
			if (str[i] == 'P') cout << str[i];
			if (str[i] == 'S') {
				Push(s, str[i]);
				a++;
			}
			if (str[i] == 'H') {
				Push(h, str[i]);
				b++;
			}
		} else {
			PrintStack(s);
			PrintStack(h);
			a = b = 0;
			InitStack(h);
			InitStack(s);
			cout << endl;
		}
	}
    }
	return 0;
}

/*
2
PSHPSH#HSHHSPPS#
*/