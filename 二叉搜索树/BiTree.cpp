#include"BiTree.h"

BiTree::BiTree()
{
	this->count = 0;
	this->root = NULL;
}

BiTNode* InsertNode(BiTNode* _root, int val)		//���뺯��
{
	if (_root == NULL)			//ÿ���²���Ԫ�ض���Ҷ�ӽڵ㣬����ΪNULLʱ��new
	{
		_root = new BiTNode(val);
		_root->lchild = NULL;
		_root->rchild = NULL;
	}
	else if (_root->data > val)		//����������������
	{
		_root->lchild = InsertNode(_root->lchild, val);
	}
	else if (_root->data < val)		//����������������
	{
		_root->rchild = InsertNode(_root->rchild, val);
	}
	return _root;
}

BiTNode* SearchNode(BiTNode* _root, int val)		//���Һ���
{
	//����ݹ����rootΪ�գ�����ҽ������NULL,���߲��ҳɹ�������ָ���data��ָ��	
	if (_root == NULL || val == _root->data)
	{
		return _root;				//�������������Ľڵ��ָ�����NULL
	}
	else if (val < _root->data)			//�ݹ����������
	{
		return SearchNode(_root->lchild, val);
	}
	else
	{
		return SearchNode(_root->rchild, val);		//�ݹ�������Һ���
	}
}

int FindMaxInLchild(BiTNode* node)		//�������������Ľ��
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

BiTNode* DeleteNode(BiTNode* _root, int val)		//ɾ������
{
	if (_root == NULL)
	{
		return NULL;					//�ݹ�������NULL
	}
	else if (val < _root->data)
	{
		_root->lchild = DeleteNode(_root->lchild, val);	//����������
		return _root;
	}
	else if (val > _root->data)
	{
		_root->rchild = DeleteNode(_root->rchild, val);	//����������
		return _root;
	}
	else if (val == _root->data)			//���˵���иýڵ������ɾ������
	{
		if (_root->lchild == NULL && _root->rchild == NULL)  //�����Ҷ�ӽڵ�,ֱ��ɾ�������ظ��ڵ�NULL
		{
			delete _root;
			_root = NULL;
			return _root;
		}
		//����������ǿ�
		else if (_root->lchild != NULL && _root->rchild == NULL)
		{
			BiTNode* tmp = _root->lchild;
			delete _root;
			_root = NULL;
			return tmp;
		}
		//����������ǿ�
		else if (_root->rchild != NULL && _root->lchild == NULL)
		{
			BiTNode* tmp = _root->rchild;
			delete _root;
			_root = NULL;
			return tmp;
		}
		else if (_root->rchild != NULL && _root->lchild != NULL)	//���ҽڵ㶼��
		{
			int max = FindMaxInLchild(_root->lchild);  //�ҳ����Ԫ��
			_root->data = max;		//������ֵ����Ҫɾ���Ľ��
			_root->lchild = DeleteNode(_root->lchild, max);
			return _root;			//����Ҫɾ���Ľ��ָ��
		}
	}
}

void InOrder(BiTNode* _root)			//�������
{
	if (_root == NULL)
	{
		return;
	}
	InOrder(_root->lchild);
	cout << _root->data << " ";
	InOrder(_root->rchild);
}

void PreOrder(BiTNode* _root)					//ǰ�����
{
	if (_root == NULL)
	{
		return;
	}
	cout << _root->data << " ";
	PreOrder(_root->lchild);
	PreOrder(_root->rchild);
}

void PostOrder(BiTNode* _root)						//�������
{
	if (_root == NULL)
	{
		return;
	}
	PostOrder(_root->lchild);
	PostOrder(_root->rchild);
	cout << _root->data << " ";
}
  
void FloorOrder(BiTNode* root)	//�������_����ʵ��
{
	queue<BiTNode*> q;
	if (root != NULL)
	{
		q.push(root);   //���ڵ������
	}
	while (q.empty() == false)  //���в�Ϊ���ж�
	{
		cout << q.front()->data << " ";

		if (q.front()->lchild != NULL)   //��������ӣ�leftChild�����
		{
			q.push(q.front()->lchild);
		}

		if (q.front()->rchild != NULL)   //������Һ��ӣ�rightChild�����
		{
			q.push(q.front()->rchild);
		}

		q.pop();  //�Ѿ��������Ľڵ������
	}
}

BiTNode* MaxNode(BiTNode* _root)		//���ֵ
{
	while (_root->rchild != NULL)
	{
		_root = _root->rchild;
	}
	return _root;
}

BiTNode* MinNode(BiTNode* _root)			//��Сֵ
{
	while (_root->lchild != NULL)
	{
		_root = _root->lchild;
	}
	return _root;
}