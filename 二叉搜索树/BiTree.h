#ifndef __BITREE_H__
#define __BITREE_H__

#include"BiTNode.h"

class BiTree
{
public:
	BiTree();
public:
	int count;			//�ڵ�����
	BiTNode* root;		//���ڵ�
};

BiTNode* SearchNode(BiTNode* _root, int val);		//���Һ���
BiTNode* InsertNode(BiTNode* _root, int val);		//���뺯��
BiTNode* DeleteNode(BiTNode* _root, int val);		//ɾ������
void PreOrder(BiTNode* _root);						//ǰ�����
void InOrder(BiTNode* _root);						//�������
void PostOrder(BiTNode* _root);						//�������
void FloorOrder(BiTNode* root);					//�������_����ʵ��
BiTNode* MaxNode(BiTNode* _root);					//���ֵ
BiTNode* MinNode(BiTNode* _root);					//��Сֵ

#endif//__BITREE_H__