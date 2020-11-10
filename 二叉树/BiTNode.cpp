#include"BiTNode.h"

BiTNode::BiTNode(elemtype data)
{
	this->m_data = data;
	this->m_lchild = NULL;
	this->m_rchild = NULL;
}
		
void FirstPrint(BiTNode* root)		//�������
{
	if (root == NULL)
	{
		return;
	}
	cout << root->m_data << " ";
	FirstPrint(root->m_lchild);
	FirstPrint(root->m_rchild);
}

void MiddlePrint(BiTNode* root)				//�������
{
	if (root == NULL)
	{
		return;
	}
	MiddlePrint(root->m_lchild);
	cout << root->m_data << " ";
	MiddlePrint(root->m_rchild);
}

void FinallyPrint(BiTNode* root)		//�������
{
	if (root == NULL)
	{
		return;
	}
	FinallyPrint(root->m_lchild);
	FinallyPrint(root->m_rchild);
	cout << root->m_data << " ";
}

void LeafCount(BiTNode* root, unsigned int& count)		//����Ҷ�ӽ�������
{
	if (root == NULL)
	{
		return;
	}
	LeafCount(root->m_lchild, count);			//������Ҷ�ӽ�������
	LeafCount(root->m_rchild, count);			//������Ҷ�ӽ�������
	if (root->m_lchild == NULL && root->m_rchild == NULL)   //�ҵ���count��һ
	{
		count++;
	}
}

int TreeDepth(BiTNode* root)			//�������ĸ߶�
{
	if (root == NULL)			//��������0
	{
		return 0;
	}
	int left_depth = TreeDepth(root->m_lchild);			//�����������ĸ߶�
	int right_depth = TreeDepth(root->m_rchild);		//�����������ĸ߶�
	int Max = left_depth > right_depth ? left_depth : right_depth;	//ȡ���ֵ
	return Max + 1;								//�����ĸ߶�+1�������ĸ߶�
}

BiTNode* CopyTree(BiTNode* root)
{
	if (root == NULL)			//�ݹ������־
	{
		return NULL;
	}
	BiTNode* left = CopyTree(root->m_lchild);			//����������
	BiTNode* right = CopyTree(root->m_rchild);			//����������
	BiTNode* p_new = new BiTNode(root->m_data);			//�����µ��ڴ�ռ����������
	p_new->m_lchild = left;			
	p_new->m_rchild = right;
	return p_new;						//ÿ�η����´����Ľ�㣬��󷵻ص��Ǹ��ڵ�
}

BiTNode* FindLeft(BiTNode* root, stack<BiTNode*>& st)  //Ѱ����ڵ�
{
	if (root == NULL)
	{
		return NULL;
	}
	//Ѱ������ߵĽ��
	while (root->m_lchild != NULL)
	{	
		st.push(root);		//��ջ
		root = root->m_lchild;
	}
	return root;		//��������ߵĽ��
}

void NoRecursion(BiTNode* root)		//�ǵݹ���������
{
	stack<BiTNode*> st;		//��ջ��ʵ�ַǵݹ�ı���
	BiTNode* left = FindLeft(root, st);
	while (left != NULL)
	{
		cout << left->m_data << " ";      //����
		if (left->m_rchild)				//�ж���û��������
		{
			left = FindLeft(left->m_rchild, st);
		}
		else
		{
			//û����������ȡ��ջ��Ԫ��	
			//�ж�ջ�Ƿ�Ϊ��
			if (!st.empty())			//��Ϊ��
			{
				left = st.top(); //ȡ��ջ��Ԫ��
				st.pop();		//����
			}
			else
			{
				cout << "\n����������" << endl;
				break;
			}
		}
	}
}

BiTNode* CreateTree()	//���ŷ������������������ʽ
{
	char data;			//����������
	cin >> data;
	if (data == '#')
	{
		return NULL;
	}
	//�ȴ������ڵ㲢��ʼ��
	BiTNode* root = new BiTNode(data);
	//����������
	root->m_lchild = CreateTree();
	//����������
	root->m_rchild = CreateTree();

	return root;			//����ֵΪ���ڵ�ĵ�ַ
}

void DestroyTree(BiTNode* root)			//�����������Ժ��������ķ�ʽ����
{
	if (root == NULL)
	{
		return;
	}
	DestroyTree(root->m_lchild);			//����������
	DestroyTree(root->m_rchild);			//����������
	cout << root->m_data << endl;
	delete root;						//���ٸ��ڵ�
}