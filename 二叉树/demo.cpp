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

	cout << "先序遍历：" << endl;
	FirstPrint(&BiT_A);
	cout << endl;

	cout << "中序遍历：" << endl;
	MiddlePrint(&BiT_A);
	cout << endl;

	cout << "后序遍历：" << endl;
	FinallyPrint(&BiT_A);
	cout << endl;

	cout << "层序遍历：" << endl;
	FloorPrint(&BiT_A);
	cout << endl;

	unsigned int count = 0;
	LeafCount(&BiT_A, count);
	cout << "叶子结点的数量为：" << count << endl;

	cout << "树的高度为：" << TreeDepth(&BiT_A) << endl;

	BiTNode* ptr = CopyTree(&BiT_A);				//拷贝二叉树
	
	cout << "先序遍历：" << endl;
	FirstPrint(ptr);
	cout << endl;

	cout << "中序遍历：" << endl;
	MiddlePrint(ptr);
	cout << endl;

	cout << "后序遍历：" << endl;
	FinallyPrint(ptr);
	cout << endl;

	cout << "层序遍历：" << endl;
	FloorPrint(ptr);
	cout << endl;

	cout << "非递归的中序遍历：" << endl;
	NoRecursion(&BiT_A);
	cout << endl;

	cout << "井号法创建树：abd##e##cf##g##" << endl;
	BiTNode* root = CreateTree();
	cout << "井号法创建的树的中序遍历：" << endl;
	MiddlePrint(root);
	cout << endl;

	cout << "销毁树的顺序：" << endl;
	DestroyTree(root);		//销毁树
	cout << "树已被销毁！" << endl;
	return 0;
}