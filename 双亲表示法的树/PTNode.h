#ifndef __PTNode_h__
#define __PTNode_h__

#include<iostream>
using namespace std;

typedef char elemtype;
#define MAXSIZE 100

class PTNode
{
public:
	elemtype m_data;		//�ڵ�����
	int m_parent;		//˫������
};

#endif//__PTNode_h__