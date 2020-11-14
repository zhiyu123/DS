#include"Stack.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.出栈             2.查看长度       **************" << endl;
	cout << "**************   3.入栈             4.打印栈         **************" << endl;
	cout << "**************   5.求栈顶           0.退出           **************" << endl;
	cout << "*******************************************************************" << endl;
}

int main()
{
	Stack L;
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
			L.Pop();
			break;
		case 2:
			L.LengthStack();
			break;
		case 3:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.Push(num);
			break;
		case 4:
			L.PrintStack();
			break;
		case 5:
			L.TopStack();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
