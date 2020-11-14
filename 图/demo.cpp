
#include"graph.h"

void menu()
{
	cout << endl;
	cout << "****************************************************************************" << endl;
	cout << "1�����ͼ�ж��������              2�����ͼ�бߵ�����" << endl;
	cout << "3����ͼ�в��붥��                  4����ͼ��ɾ������" << endl;
	cout << "5���������ڱ�<x, y>�������ñ�    6�������ڱ�<x, y>����ɾ���ñ�" << endl;
	cout << "7����ӡ                            8�����붥��ĵ�һ���ڽӵ�" << endl;
	cout << "9��DFS                             10��BFS" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

int main()
{
	ALGraph G;
	elemtype x;
	elemtype y;
	int choose = 0;
	do
	{
		menu();
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 1:
			G.GetV();
			break;
		case 2:
			G.GetE();
			break;
		case 3:
			cout << "��������붥���ֵ��";
			cin >> x;
			G.InsertVertex(x);
			break;
		case 4:
			cout << "������Ҫɾ�������ֵ��";
			cin >> x;
			G.DeleteVertex(x);
			break;
		case 5:
			cout << "��������ӱߵ���ʼ���㣺";
			cin >> x;
			cout << "��������ӱߵ���ֹ���㣺";
			cin >> y;
			G.AddEdge(x, y);
			break;
		case 6:
			cout << "������Ҫɾ���ߵ���ʼ���㣺";
			cin >> x;
			cout << "������Ҫɾ���ߵ���ֹ���㣺";
			cin >> y;
			G.RemoveEdge(x, y);
			break;
		case 7:
			G.Print();
			break;
		case 8:
			cout << "�����붥�㣺";
			cin >> x;
			G.FirstNeighbor(x);
			break;
		case 9:
			G.DFS();
			break;
		case 10:
			G.BFS();
			break;
		case 0:
			cout << "�˳�" << endl;
			break;
		}
	} while (choose);
	return 0;
}