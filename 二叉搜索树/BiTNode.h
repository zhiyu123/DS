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
	int data;				//键值（数据域）,因为当前数据设为整数，所以也可使用数据当为键值，保证其唯一性	
	BiTNode* lchild;		//左孩子
	BiTNode* rchild;		//右孩子
};

#endif//__BITNODE_H__