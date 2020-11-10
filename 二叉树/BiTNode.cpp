#include"BiTNode.h"

BiTNode::BiTNode(elemtype data)
{
	this->m_data = data;
	this->m_lchild = NULL;
	this->m_rchild = NULL;
}
		
void FirstPrint(BiTNode* root)		//先序遍历
{
	if (root == NULL)
	{
		return;
	}
	cout << root->m_data << " ";
	FirstPrint(root->m_lchild);
	FirstPrint(root->m_rchild);
}

void MiddlePrint(BiTNode* root)				//中序遍历
{
	if (root == NULL)
	{
		return;
	}
	MiddlePrint(root->m_lchild);
	cout << root->m_data << " ";
	MiddlePrint(root->m_rchild);
}

void FinallyPrint(BiTNode* root)		//后序遍历
{
	if (root == NULL)
	{
		return;
	}
	FinallyPrint(root->m_lchild);
	FinallyPrint(root->m_rchild);
	cout << root->m_data << " ";
}

void LeafCount(BiTNode* root, unsigned int& count)		//计算叶子结点的数量
{
	if (root == NULL)
	{
		return;
	}
	LeafCount(root->m_lchild, count);			//左子树叶子结点的数量
	LeafCount(root->m_rchild, count);			//右子树叶子结点的数量
	if (root->m_lchild == NULL && root->m_rchild == NULL)   //找到了count加一
	{
		count++;
	}
}

int TreeDepth(BiTNode* root)			//计算树的高度
{
	if (root == NULL)			//空树返回0
	{
		return 0;
	}
	int left_depth = TreeDepth(root->m_lchild);			//计算左子树的高度
	int right_depth = TreeDepth(root->m_rchild);		//计算右子树的高度
	int Max = left_depth > right_depth ? left_depth : right_depth;	//取最大值
	return Max + 1;								//子树的高度+1就是树的高度
}

BiTNode* CopyTree(BiTNode* root)
{
	if (root == NULL)			//递归结束标志
	{
		return NULL;
	}
	BiTNode* left = CopyTree(root->m_lchild);			//拷贝左子树
	BiTNode* right = CopyTree(root->m_rchild);			//拷贝右子树
	BiTNode* p_new = new BiTNode(root->m_data);			//申请新的内存空间来存放数据
	p_new->m_lchild = left;			
	p_new->m_rchild = right;
	return p_new;						//每次返回新创建的结点，最后返回的是根节点
}

BiTNode* FindLeft(BiTNode* root, stack<BiTNode*>& st)  //寻找左节点
{
	if (root == NULL)
	{
		return NULL;
	}
	//寻找最左边的结点
	while (root->m_lchild != NULL)
	{	
		st.push(root);		//入栈
		root = root->m_lchild;
	}
	return root;		//返回最左边的结点
}

void NoRecursion(BiTNode* root)		//非递归的中序遍历
{
	stack<BiTNode*> st;		//用栈来实现非递归的遍历
	BiTNode* left = FindLeft(root, st);
	while (left != NULL)
	{
		cout << left->m_data << " ";      //访问
		if (left->m_rchild)				//判断有没有右子树
		{
			left = FindLeft(left->m_rchild, st);
		}
		else
		{
			//没有右子树，取出栈顶元素	
			//判断栈是否为空
			if (!st.empty())			//不为空
			{
				left = st.top(); //取出栈顶元素
				st.pop();		//弹出
			}
			else
			{
				cout << "\n遍历结束！" << endl;
				break;
			}
		}
	}
}

BiTNode* CreateTree()	//井号法创建树，先序遍历方式
{
	char data;			//输入结点数据
	cin >> data;
	if (data == '#')
	{
		return NULL;
	}
	//先创建根节点并初始化
	BiTNode* root = new BiTNode(data);
	//创建左子树
	root->m_lchild = CreateTree();
	//创建右子树
	root->m_rchild = CreateTree();

	return root;			//返回值为根节点的地址
}

void DestroyTree(BiTNode* root)			//销毁树必须以后续遍历的方式销毁
{
	if (root == NULL)
	{
		return;
	}
	DestroyTree(root->m_lchild);			//销毁左子树
	DestroyTree(root->m_rchild);			//销毁右子树
	cout << root->m_data << endl;
	delete root;						//销毁根节点
}