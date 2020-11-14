#ifndef __LinkQueue_h__
#define __LinkQueue_h__

#include<iostream>
using namespace std;
#include"Node.h"

typedef int elemtype;

class LinkQueue
{
public:
	LinkQueue();		//�����ʼ��
	~LinkQueue();		//��������
	void PushQueue(elemtype e);		//���
	void PopQueue();		//����
	void LengthQueue();		//�󳤶�
	void PrintQueue();		//��ӡ
private:
	Node* front;		//ͷָ��
	Node* rear;		//βָ��
	int length;		//����
};


#endif//__LinkQueue_h__