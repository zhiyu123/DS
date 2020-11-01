#include"SqList.h"
#pragma warning(disable:6031) 

void menu()
{
	printf("*******************************************************************\n");
	printf("**************   1.打印顺序表       2.查看容量和长度 **************\n");
	printf("**************   3.头插             4.尾插           **************\n");
	printf("**************   5.头删             6.尾删           **************\n");
	printf("**************   7.任意位置插入     8.任意位置删除   **************\n");
	printf("**************   9.查询某元素的位置 10.排序          **************\n");
	printf("**************   11.清空            0.退出           **************\n");
	printf("*******************************************************************\n");
}

int main()
{
	SqList L;
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
			L.PrintList();
			break;
		case 2:
			L.ShowCapacityLength();
			break;
		case 3:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.PushPront(num);
			break;
		case 4:
			cout << "请输入要插入的元素：";
			cin >> num;
			L.PushBack(num);
			break;
		case 5:
			L.PopPront();
			break;
		case 6:
			L.PopBack();
			break;
		case 7:
			cout << "请输入插入的位置：";
			cin >> pos;
			cout << "请输入要插入的元素：";
			cin >> num;
			L.InsertElem(pos, num);
			break;
		case 8:
			cout << "请输入要删除的位置：";
			cin >> pos;
			L.DeleteElem(pos);
			break;
		case 9:
			cout << "请输入要查询的元素：";
			cin >> num;
			L.LocateElem(num);
			break;
		case 10:
			L.SortList();
			break;
		case 11:
			L.ClearList();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
