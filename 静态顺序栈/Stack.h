#ifndef __Stack_h__
#define __Stack_h__

#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef int elemtype;

class Stack
{
public:
	Stack();			//构造函数初始化栈
	~Stack();			//析构函数
	void Pop();			//出栈
	void Push(elemtype e);		//入栈
	void PrintStack();		//打印栈
	void LengthStack();		//求长度
	void TopStack();		//求栈顶元素
private:
	elemtype data[MAXSIZE];
	int top;
	int length;
};



#endif//__Stack_h__