#include"CSNode.h"

int main()
{
	CSNode NodeA('A'); 
	CSNode NodeB('B'); 
	CSNode NodeC('C');
	CSNode NodeD('D');
	CSNode NodeE('E');
	CSNode NodeF('F');
	CSNode NodeG('G');
	CSNode NodeH('H');
	CSNode NodeI('I');
	CSNode NodeJ('J');
	CSNode NodeK('K');
	CSNode NodeL('L');
	CSNode NodeM('M');
	NodeA.m_firstchild = &NodeB;
	NodeB.m_firstchild = &NodeE;
	NodeB.m_rightsib = &NodeC;
	NodeC.m_firstchild = &NodeG;
	NodeC.m_rightsib = &NodeD;
	NodeD.m_firstchild = &NodeH;
	NodeE.m_firstchild = &NodeK;
	NodeE.m_rightsib = &NodeF;
	NodeH.m_rightsib = &NodeI;
	NodeH.m_firstchild = &NodeM;
	NodeI.m_rightsib = &NodeJ;
	NodeK.m_rightsib = &NodeL;
	cout << "���������" << endl;
	FirstPrint(&NodeA);		    //�������	
	cout << endl;

	cout << "���������" << endl;
	MiddlePrint(&NodeA);		//�������
	cout << endl;

	cout << "���������" << endl;
	FinallyPrint(&NodeA);      //��������
	cout << endl;

	return 0;
}