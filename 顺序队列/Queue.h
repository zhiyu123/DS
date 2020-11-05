#ifndef __Queue_h__
#define __Queue_h__

#include<iostream>
using namespace std;

typedef int elemtype;
#define MAXSIZE 4

class Queue
{
public:
	Queue();		//构造初始化
	void PushQueue(elemtype e);		//入队
	void PopQueue();		//出队
	void LengthQueue();		//求长度
	void PrintQueue();		//打印
private:
	int front;		//头指针
	int rear;		//尾指针
	int length;		//长度
	elemtype data[MAXSIZE];
};

#endif//__Queue_h__