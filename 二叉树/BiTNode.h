#ifndef __BITNODE_H__
#define __BITNODE_H__

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef char elemtype;

class BiTNode
{
public:
	BiTNode(elemtype data);
	elemtype m_data;		//������
	BiTNode* m_lchild;		//����
	BiTNode* m_rchild;		//�Һ���
};

void FirstPrint(BiTNode* root);		//�������
void MiddlePrint(BiTNode* root);	//�������
void FinallyPrint(BiTNode* root);	//�������
void FloorPrint(BiTNode* root);		//�������
void LeafCount(BiTNode* root,unsigned int &count);		//��Ҷ�ӽ�����Ŀ
int TreeDepth(BiTNode* root);		//�����ĸ߶�
BiTNode* CopyTree(BiTNode* root);		//����������
void NoRecursion(BiTNode* root);			//�ǵݹ��������
BiTNode* FindLeft(BiTNode* root, stack<BiTNode*>& st);		//�ǵݹ���������õ������������ĺ���
BiTNode* CreateTree();				//�þ��ŷ�������
void DestroyTree(BiTNode* root);				//������

#endif//__BITNODE_H__