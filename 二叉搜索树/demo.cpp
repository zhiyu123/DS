#include"BiTree.h"

int main()
{
	BiTNode* _root = new BiTNode(10);
	InsertNode(_root, 6);
	InsertNode(_root, 15);
	InsertNode(_root, 8);
	InsertNode(_root, 13);
	InsertNode(_root, 11);
	InsertNode(_root, 14);
	InsertNode(_root, 17);

	cout << "前序遍历为：" << endl;
	PreOrder(_root);
	cout << endl;

	cout << "中序遍历为：" << endl;
	InOrder(_root);
	cout << endl;

	cout << "后序遍历为：" << endl;
	PostOrder(_root);
	cout << endl;

	cout << "层序遍历为：" << endl;
	FloorOrder(_root);
	cout << endl;

	BiTNode* Max = MaxNode(_root);
	cout << "最大值为：" << Max->data << endl;

	BiTNode* Min = MinNode(_root);
	cout << "最小值为：" << Min->data << endl;

	BiTNode* p = SearchNode(_root, 13);
	if (p != NULL)
	{
		cout << "已找到此元素：" << p->data << endl;
	}
	else
	{
		cout << "未找到此元素！" << endl;
	}

	BiTNode* pp = DeleteNode(_root,13);

	cout << "前序遍历为：" << endl;
	PreOrder(pp);
	cout << endl;

	cout << "中序遍历为：" << endl;
	InOrder(pp);
	cout << endl;

	cout << "后序遍历为：" << endl;
	PostOrder(pp);
	cout << endl;

	cout << "层序遍历为：" << endl;
	FloorOrder(_root);
	cout << endl;

	return 0;
}
