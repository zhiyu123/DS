#ifndef __NODE_H__
#define __NODE_H__

#include<iostream>
typedef int elemtype;
using namespace std;

class Node
{
public:
	elemtype data;			//������
	Node* next;				//���ָ��
	Node* front;			//ǰ��ָ��
};



#endif//__NODE_H__