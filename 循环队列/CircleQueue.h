#ifndef __CircleQueue_h__
#define __CircleQueue_h__

#include<iostream>
using namespace std;

typedef int elemtype;
#define MAXSIZE 5

class CircleQueue
{
public:
	CircleQueue();		//构造初始化
	void PushQueue(elemtype e);		//入队
	void PopQueue();		//出队
	void LengthQueue();		//求长度
	void PrintQueue();		//打印
private:
	int front;		//头指针
	int rear;		//尾指针
	int length;		//长度
	elemtype data[MAXSIZE];		//原始数组长度
};


#endif//__CircleQueue_h__