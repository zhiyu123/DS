#ifndef __NODE_H__
#define __NODE_H__

#include<iostream>
typedef int elemtype;
using namespace std;

class Node
{
public:
	elemtype data;			//数据域
	Node* next;				//后继指针
	Node* front;			//前驱指针
};



#endif//__NODE_H__