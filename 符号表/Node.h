#ifndef __NODE_H__
#define __NODE_H__

#include<iostream>
using namespace std;

typedef int elemtype_value;
typedef int elemtype_key;

class Node
{
public:
	elemtype_key m_key;			//键
	elemtype_value m_value;		//值
	Node* next;					//指向下一节点
};

#endif//__NODE_H__