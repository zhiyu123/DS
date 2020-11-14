#include"BiTNode.h"

int main()
{
	BiTNode BiT_A('A');
	BiTNode BiT_B('B');
	BiTNode BiT_C('C');
	BiTNode BiT_D('D');
	BiTNode BiT_E('E');
	BiTNode BiT_F('F');
	BiTNode BiT_G('G');

	BiT_A.m_lchild = &BiT_B;
	BiT_A.m_rchild = &BiT_C;

	BiT_B.m_lchild = &BiT_D;
	BiT_B.m_rchild = &BiT_E;

	BiT_C.m_lchild = &BiT_F;
	BiT_C.m_rchild = &BiT_G;

	cout << "���������" << endl;
	FirstPrint(&BiT_A);
	cout << endl;

	cout << "���������" << endl;
	MiddlePrint(&BiT_A);
	cout << endl;

	cout << "���������" << endl;
	FinallyPrint(&BiT_A);
	cout << endl;

	cout << "���������" << endl;
	FloorPrint(&BiT_A);
	cout << endl;

	unsigned int count = 0;
	LeafCount(&BiT_A, count);
	cout << "Ҷ�ӽ�������Ϊ��" << count << endl;

	cout << "���ĸ߶�Ϊ��" << TreeDepth(&BiT_A) << endl;

	BiTNode* ptr = CopyTree(&BiT_A);				//����������
	
	cout << "���������" << endl;
	FirstPrint(ptr);
	cout << endl;

	cout << "���������" << endl;
	MiddlePrint(ptr);
	cout << endl;

	cout << "���������" << endl;
	FinallyPrint(ptr);
	cout << endl;

	cout << "���������" << endl;
	FloorPrint(ptr);
	cout << endl;

	cout << "�ǵݹ�����������" << endl;
	NoRecursion(&BiT_A);
	cout << endl;

	cout << "���ŷ���������abd##e##cf##g##" << endl;
	BiTNode* root = CreateTree();
	cout << "���ŷ��������������������" << endl;
	MiddlePrint(root);
	cout << endl;

	cout << "��������˳��" << endl;
	DestroyTree(root);		//������
	cout << "���ѱ����٣�" << endl;
	return 0;
}