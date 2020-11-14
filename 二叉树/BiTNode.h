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
	elemtype m_data;		//数据域
	BiTNode* m_lchild;		//左孩子
	BiTNode* m_rchild;		//右孩子
};

void FirstPrint(BiTNode* root);		//先序遍历
void MiddlePrint(BiTNode* root);	//中序遍历
void FinallyPrint(BiTNode* root);	//后序遍历
void FloorPrint(BiTNode* root);		//层序遍历
void LeafCount(BiTNode* root,unsigned int &count);		//求叶子结点的数目
int TreeDepth(BiTNode* root);		//求树的高度
BiTNode* CopyTree(BiTNode* root);		//拷贝二叉树
void NoRecursion(BiTNode* root);			//非递归中序遍历
BiTNode* FindLeft(BiTNode* root, stack<BiTNode*>& st);		//非递归中序遍历用到的找左子树的函数
BiTNode* CreateTree();				//用井号法创建树
void DestroyTree(BiTNode* root);				//销毁树

#endif//__BITNODE_H__