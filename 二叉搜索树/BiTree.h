#ifndef __BITREE_H__
#define __BITREE_H__

#include"BiTNode.h"

class BiTree
{
public:
	BiTree();
public:
	int count;			//节点数量
	BiTNode* root;		//根节点
};

BiTNode* SearchNode(BiTNode* _root, int val);		//查找函数
BiTNode* InsertNode(BiTNode* _root, int val);		//插入函数
BiTNode* DeleteNode(BiTNode* _root, int val);		//删除函数
void PreOrder(BiTNode* _root);						//前序遍历
void InOrder(BiTNode* _root);						//中序遍历
void PostOrder(BiTNode* _root);						//后序遍历
void FloorOrder(BiTNode* root);					//层序遍历_队列实现
BiTNode* MaxNode(BiTNode* _root);					//最大值
BiTNode* MinNode(BiTNode* _root);					//最小值

#endif//__BITREE_H__