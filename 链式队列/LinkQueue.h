#ifndef __LinkQueue_h__
#define __LinkQueue_h__

#include<iostream>
using namespace std;
#include"Node.h"

typedef int elemtype;

class LinkQueue
{
public:
	LinkQueue();		//构造初始化
	~LinkQueue();		//析构函数
	void PushQueue(elemtype e);		//入队
	void PopQueue();		//出队
	void LengthQueue();		//求长度
	void PrintQueue();		//打印
private:
	Node* front;		//头指针
	Node* rear;		//尾指针
	int length;		//长度
};


#endif//__LinkQueue_h__