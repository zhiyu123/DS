
#include"graph.h"

void menu()
{
	cout << endl;
	cout << "****************************************************************************" << endl;
	cout << "1、获得图中顶点的数量              2、获得图中边的数量" << endl;
	cout << "3、在图中插入顶点                  4、在图中删除顶点" << endl;
	cout << "5、若不存在边<x, y>，则插入该边    6、若存在边<x, y>，则删除该边" << endl;
	cout << "7、打印                            8、求传入顶点的第一个邻接点" << endl;
	cout << "9、DFS                             10、BFS" << endl;
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
		cout << "请选择：";
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
			cout << "请输入插入顶点的值：";
			cin >> x;
			G.InsertVertex(x);
			break;
		case 4:
			cout << "请输入要删除顶点的值：";
			cin >> x;
			G.DeleteVertex(x);
			break;
		case 5:
			cout << "请输入添加边的起始顶点：";
			cin >> x;
			cout << "请输入添加边的终止顶点：";
			cin >> y;
			G.AddEdge(x, y);
			break;
		case 6:
			cout << "请输入要删除边的起始顶点：";
			cin >> x;
			cout << "请输入要删除边的终止顶点：";
			cin >> y;
			G.RemoveEdge(x, y);
			break;
		case 7:
			G.Print();
			break;
		case 8:
			cout << "请输入顶点：";
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
			cout << "退出" << endl;
			break;
		}
	} while (choose);
	return 0;
}