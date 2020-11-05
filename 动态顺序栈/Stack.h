#ifndef __Stack_h__
#define __Stack_h__

#include<iostream>
using namespace std;

#define INITSIZE 5			//��ʼ��С5
typedef int elemtype;

class Stack
{
public:
	Stack();			//���캯����ʼ��ջ
	~Stack();			//��������
	void CheckStack();	//��⵱ǰ�����Ƿ����ĺ���
	void Pop();			//��ջ
	void Push(elemtype e);		//��ջ
	void PrintStack();		//��ӡջ
	void LengthStack();		//�󳤶�
	void TopStack();		//��ջ��Ԫ��
private:
	elemtype* data;	   //��̬�����ָ�� 
	int top;			//ջ��
	int length;		//����
	int capacity;	//����
};



#endif//__Stack_h__