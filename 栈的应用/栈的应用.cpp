// 栈的应用.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

class SqStack {
private:
	char *base;
	int top;
	int stacksize;
public:
	SqStack(int m);
	SqStack() {
		delete[]base; top = 0; stacksize = 0;
}
	void Push(int x);
	char Pop();
	char GetTop();
	int StackEmpty();
	void ClearStack();
};
SqStack::SqStack(int m) {
	base = new char[m];
	if (base == NULL) {
		cout << "栈创建失败，退出！" << endl;
		exit(1);
	}
	stacksize = m;
	top = -1;
}
void SqStack::Push(int x) {
	if (top == stacksize - 1) {
		cout << "栈满，无法入栈！";
	}
	top++;
	if(x<10) base[top] = (char)(x+48);
	else base[top] = (char)x;
}
char SqStack::Pop() {
	int x;
	if (top == -1) cout << "栈空，不能出栈！";
	x = base[top--];
	return x;
}
char SqStack::GetTop() {
	if (top == -1) cout << "栈空，栈顶无元素！" << endl;
	return base[top];
}
int SqStack::StackEmpty() {
	if (top == -1) return 1;
	else return 0;
}
void SqStack::ClearStack() {
	top = -1;
}
void conversion(int N) {
	SqStack s(20);
	int m;
	while (N) {
		m = (int)(N % 16);
		if (m >= 10) m = m + 55;
		s.Push(m);
		N = N / 16;
	}
	while (!s.StackEmpty()) {
			char e;
			e= s.Pop();
			cout << e;
		}
	cout << endl;
	s.~SqStack();
}
int main()
{
	cout << "请输入一个整数：";
	int N;
	cin >> N;
	cout << "转化为十六进制：";
	conversion(N);
    return 0;
}

