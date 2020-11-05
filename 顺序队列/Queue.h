#ifndef __Queue_h__
#define __Queue_h__

#include<iostream>
using namespace std;

typedef int elemtype;
#define MAXSIZE 4

class Queue
{
public:
	Queue();		//�����ʼ��
	void PushQueue(elemtype e);		//���
	void PopQueue();		//����
	void LengthQueue();		//�󳤶�
	void PrintQueue();		//��ӡ
private:
	int front;		//ͷָ��
	int rear;		//βָ��
	int length;		//����
	elemtype data[MAXSIZE];
};

#endif//__Queue_h__