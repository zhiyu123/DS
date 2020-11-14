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

	cout << "ǰ�����Ϊ��" << endl;
	PreOrder(_root);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	InOrder(_root);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	PostOrder(_root);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	FloorOrder(_root);
	cout << endl;

	BiTNode* Max = MaxNode(_root);
	cout << "���ֵΪ��" << Max->data << endl;

	BiTNode* Min = MinNode(_root);
	cout << "��СֵΪ��" << Min->data << endl;

	BiTNode* p = SearchNode(_root, 13);
	if (p != NULL)
	{
		cout << "���ҵ���Ԫ�أ�" << p->data << endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ�أ�" << endl;
	}

	BiTNode* pp = DeleteNode(_root,13);

	cout << "ǰ�����Ϊ��" << endl;
	PreOrder(pp);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	InOrder(pp);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	PostOrder(pp);
	cout << endl;

	cout << "�������Ϊ��" << endl;
	FloorOrder(_root);
	cout << endl;

	return 0;
}
