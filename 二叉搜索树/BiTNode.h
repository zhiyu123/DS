#ifndef __BITNODE_H__
#define __BITNODE_H__

#include<iostream>
#include<queue>
using namespace std;

class BiTNode
{
public:
	BiTNode(int val);
public:
	int data;				//��ֵ��������,��Ϊ��ǰ������Ϊ����������Ҳ��ʹ�����ݵ�Ϊ��ֵ����֤��Ψһ��	
	BiTNode* lchild;		//����
	BiTNode* rchild;		//�Һ���
};

#endif//__BITNODE_H__