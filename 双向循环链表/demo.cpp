#include"DoubleCircleLinkList.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.清空链表         2.查看长度       **************" << endl;
	cout << "**************   3.头插             4.尾插           **************" << endl;
	cout << "**************   5.头删             6.尾删           **************" << endl;
	cout << "**************   7.任意位置插入     8.任意位置删除   **************" << endl;
	cout << "**************   9.查询某元素的位置 10.打印链表      **************" << endl;
	cout << "**************   11.逆序打印链表    0.退出           **************" << endl;
	cout << "*******************************************************************" << endl;
}

int main()
{
	DoubleCircleLinkList L;
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
			L.ClearLinkList();
			break;
		case 2:
			L.Length();
			break;
		case 3:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.PushFront(num);
			break;
		case 4:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.PushBack(num);
			break;
		case 5:
			L.PopFront();
			break;
		case 6:
			L.PopBack();
			break;
		case 7:
			cout << "请输入插入的位置：";
			cin >> pos;
			cout << "请输入要插入的元素：";
			cin >> num;
			L.InsertLinkList(pos, num);
			break;
		case 8:
			cout << "请输入要删除的位置：";
			cin >> pos;
			L.DeleteLinkList(pos);
			break;
		case 9:
			cout << "请输入要查询的元素：";
			cin >> num;
			L.SearchLinkList(num);
			break;
		case 10:
			L.PrintLinkList();
			break;
		case 11:
			L.RPrintLinkList();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			break;
		}
	} while (choose);
	return 0;
}