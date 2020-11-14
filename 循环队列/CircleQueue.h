#ifndef __CircleQueue_h__
#define __CircleQueue_h__

#include<iostream>
using namespace std;

typedef int elemtype;
#define MAXSIZE 5

class CircleQueue
{
public:
	CircleQueue();		//�����ʼ��
	void PushQueue(elemtype e);		//���
	void PopQueue();		//����
	void LengthQueue();		//�󳤶�
	void PrintQueue();		//��ӡ
private:
	int front;		//ͷָ��
	int rear;		//βָ��
	int length;		//����
	elemtype data[MAXSIZE];		//ԭʼ���鳤��
};


#endif//__CircleQueue_h__