#ifndef __NODE_H__
#define __NODE_H__

#include<iostream>
using namespace std;

typedef int elemtype_value;
typedef int elemtype_key;

class Node
{
public:
	elemtype_key m_key;			//��
	elemtype_value m_value;		//ֵ
	Node* next;					//ָ����һ�ڵ�
};

#endif//__NODE_H__