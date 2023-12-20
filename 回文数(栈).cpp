
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define SElemType char
#define MaxSize 100
using namespace std;

typedef struct {
	SElemType *top,*base;
	int size;
} *SqStack;

int  InitStack(SqStack &S) {
//	//构造一个空栈
	S = (SqStack)malloc(sizeof(SqStack)); 
	S->base = (SElemType*)malloc(sizeof(SElemType)*MaxSize);
	if(!S->base) return false;
	S->size = MaxSize;
	S->top = S->base;
	return true;
}

bool Push(SqStack S, SElemType e) {
	//入栈：插入元素e
	if(S->top-S->base == MaxSize)
	return false;
	else{
		*(S->top++) = e;
	}
}

bool Pop(SqStack S, SElemType &e) {
	//出栈 ：返回e
	if (S->top == S->base)
		return false;
	else {
		e = *(--S->top);
		return true;
	}
}

bool equal(SElemType m, SElemType n) {
//	cout << m << n << endl;
	if (m == n)
		return true;
	return false;
}

int main() {
	SqStack p;
	SElemType c;
	string s;
	while (cin >> s) {
		int flag = 0;
		int flag1 = 0;
		InitStack(p);
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] != '&' && flag == 0)
				Push(p, s[i]);
			if (s[i] == '&') {
				flag = 1;
				i++;
			}
			if (flag == 1) {
				Pop(p, c);
				if (equal(c, s[i]) == 0) {
					cout << "NO" << endl;
					flag1 = 1;
					break;
				}
				continue; 
			}
		}
		if (flag1 == 0)
			cout << "YES" << endl;
	}

}
/*
a+b&b+a
Heisaworker&rekrowasieh
cdeaf&faedc
*/