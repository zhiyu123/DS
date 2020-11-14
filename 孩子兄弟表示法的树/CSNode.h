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
	CSNode* m_firstchild;		//����
	CSNode* m_rightsib;			//���ֵ�
};

void FirstPrint(CSNode* root);		//�������	
void MiddlePrint(CSNode* root);		//�������
void FinallyPrint(CSNode* root);    //��������
#endif//__CSNode_h__