#include"BiTree.h"

BiTree::BiTree()
{
	this->count = 0;
	this->root = NULL;
}

BiTNode* InsertNode(BiTNode* _root, int val)		//插入函数
{
	if (_root == NULL)			//每次新插入元素都是叶子节点，所以为NULL时就new
	{
		_root = new BiTNode(val);
		_root->lchild = NULL;
		_root->rchild = NULL;
	}
	else if (_root->data > val)		//向左子树遍历插入
	{
		_root->lchild = InsertNode(_root->lchild, val);
	}
	else if (_root->data < val)		//向右子树遍历插入
	{
		_root->rchild = InsertNode(_root->rchild, val);
	}
	return _root;
}

BiTNode* SearchNode(BiTNode* _root, int val)		//查找函数
{
	//如果递归过程root为空，则查找结果返回NULL,或者查找成功，返回指向该data的指针	
	if (_root == NULL || val == _root->data)
	{
		return _root;				//返回满足条件的节点的指针或者NULL
	}
	else if (val < _root->data)			//递归遍历其左孩子
	{
		return SearchNode(_root->lchild, val);
	}
	else
	{
		return SearchNode(_root->rchild, val);		//递归遍历其右孩子
	}
}

int FindMaxInLchild(BiTNode* node)		//找左子树中最大的结点
{
	if (node == NULL)
	{
		return 0;
	}
	else if (node->rchild == NULL)
	{
		return node->data;
	}
	else
	{
		return FindMaxInLchild(node->rchild);
	}
}

BiTNode* DeleteNode(BiTNode* _root, int val)		//删除函数
{
	if (_root == NULL)
	{
		return NULL;					//递归结束标回NULL
	}
	else if (val < _root->data)
	{
		_root->lchild = DeleteNode(_root->lchild, val);	//左子树遍历
		return _root;
	}
	else if (val > _root->data)
	{
		_root->rchild = DeleteNode(_root->rchild, val);	//右子树遍历
		return _root;
	}
	else if (val == _root->data)			//相等说明有该节点则进行删除操作
	{
		if (_root->lchild == NULL && _root->rchild == NULL)  //如果是叶子节点,直接删除，返回父节点NULL
		{
			delete _root;
			_root = NULL;
			return _root;
		}
		//如果左子树非空
		else if (_root->lchild != NULL && _root->rchild == NULL)
		{
			BiTNode* tmp = _root->lchild;
			delete _root;
			_root = NULL;
			return tmp;
		}
		//如果右子树非空
		else if (_root->rchild != NULL && _root->lchild == NULL)
		{
			BiTNode* tmp = _root->rchild;
			delete _root;
			_root = NULL;
			return tmp;
		}
		else if (_root->rchild != NULL && _root->lchild != NULL)	//左右节点都有
		{
			int max = FindMaxInLchild(_root->lchild);  //找出最大元素
			_root->data = max;		//将最大的值赋给要删除的结点
			_root->lchild = DeleteNode(_root->lchild, max);
			return _root;			//返回要删除的结点指针
		}
	}
}

void InOrder(BiTNode* _root)			//中序遍历
{
	if (_root == NULL)
	{
		return;
	}
	InOrder(_root->lchild);
	cout << _root->data << " ";
	InOrder(_root->rchild);
}

void PreOrder(BiTNode* _root)					//前序遍历
{
	if (_root == NULL)
	{
		return;
	}
	cout << _root->data << " ";
	PreOrder(_root->lchild);
	PreOrder(_root->rchild);
}

void PostOrder(BiTNode* _root)						//后序遍历
{
	if (_root == NULL)
	{
		return;
	}
	PostOrder(_root->lchild);
	PostOrder(_root->rchild);
	cout << _root->data << " ";
}
  
void FloorOrder(BiTNode* root)	//层序遍历_队列实现
{
	queue<BiTNode*> q;
	if (root != NULL)
	{
		q.push(root);   //根节点进队列
	}
	while (q.empty() == false)  //队列不为空判断
	{
		cout << q.front()->data << " ";

		if (q.front()->lchild != NULL)   //如果有左孩子，leftChild入队列
		{
			q.push(q.front()->lchild);
		}

		if (q.front()->rchild != NULL)   //如果有右孩子，rightChild入队列
		{
			q.push(q.front()->rchild);
		}

		q.pop();  //已经遍历过的节点出队列
	}
}

BiTNode* MaxNode(BiTNode* _root)		//最大值
{
	while (_root->rchild != NULL)
	{
		_root = _root->rchild;
	}
	return _root;
}

BiTNode* MinNode(BiTNode* _root)			//最小值
{
	while (_root->lchild != NULL)
	{
		_root = _root->lchild;
	}
	return _root;
}