#include"CSNode.h"

CSNode::CSNode(elemtype e)
{
	this->m_data = e;
	this->m_firstchild = NULL;
	this->m_rightsib = NULL;
}

void FirstPrint(CSNode* root)		//�������	
{
	if (root == NULL)		//�ݹ��������
	{
		return;			
	}
	cout << root->m_data << "  " ;
	FirstPrint(root->m_firstchild);
	FirstPrint(root->m_rightsib);
}

void MiddlePrint(CSNode* root)		//�������
{
	if (root == NULL)
	{
		return;
	}
	MiddlePrint(root->m_firstchild);
	cout << root->m_data << "  " ;
	MiddlePrint(root->m_rightsib);
}

void FinallyPrint(CSNode* root)    //��������
{
	if (root == NULL)
	{
		return;
	}
	FinallyPrint(root->m_firstchild);
	FinallyPrint(root->m_rightsib);
	cout << root->m_data << "  ";
}	