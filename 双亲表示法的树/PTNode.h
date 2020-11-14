#ifndef __PTNode_h__
#define __PTNode_h__

#include<iostream>
using namespace std;

typedef char elemtype;
#define MAXSIZE 100

class PTNode
{
public:
	elemtype m_data;		//节点数据
	int m_parent;		//双亲坐标
};

#endif//__PTNode_h__