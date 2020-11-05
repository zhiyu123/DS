#include"Queue.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*********************************************************" << endl;
	cout << "**************   1.入队        2.出队      **************" << endl;
	cout << "**************   3.求长度      4.打印      **************" << endl;
	cout << "**************   0.退出                    **************" << endl;
	cout << "*********************************************************" << endl;
}

int main()
{
	Queue L;
	int choose = 0;
	elemtype num = 0;
	elemtype pos = 0;
	do
	{
		menu();
		cout << "请选择：";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "退出成功！" << endl;
			break;
		case 1:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.PushQueue(num);
			break;
		case 2:
			L.PopQueue();
			break;
		case 3:
			L.LengthQueue();
			break;
		case 4:
			L.PrintQueue();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
