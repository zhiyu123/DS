#ifndef __Stack_h__
#define __Stack_h__

#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef int elemtype;

class Stack
{
public:
	Stack();			//���캯����ʼ��ջ
	~Stack();			//��������
	void Pop();			//��ջ
	void Push(elemtype e);		//��ջ
	void PrintStack();		//��ӡջ
	void LengthStack();		//�󳤶�
	void TopStack();		//��ջ��Ԫ��
private:
	elemtype data[MAXSIZE];
	int top;
	int length;
};



#endif//__Stack_h__