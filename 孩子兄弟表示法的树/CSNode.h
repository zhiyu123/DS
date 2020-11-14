#ifndef __CSNode_h__
#define __CSTNode_h__

#include<iostream>
using namespace std;

typedef char elemtype;

class CSNode
{
public:
	CSNode(elemtype e);
	elemtype m_data;
	CSNode* m_firstchild;		//左孩子
	CSNode* m_rightsib;			//右兄弟
};

void FirstPrint(CSNode* root);		//先序遍历	
void MiddlePrint(CSNode* root);		//中序遍历
void FinallyPrint(CSNode* root);    //后续遍历
#endif//__CSNode_h__