#include"SymbolTable.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.插入             2.删除           **************" << endl;
	cout << "**************   3.查找             4.求长度         **************" << endl;
	cout << "**************   5.打印             0.退出           **************" << endl;
	cout << "*******************************************************************" << endl;
}

int main()
{
	SymbolTable L;
	int choose = 0;
	elemtype_key key = 0;
	elemtype_value value = 0;
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
			cout << "请输入要插入的key：";
			cin >> key;
			cout << "请输入要插入的value：";
			cin >> value;
			L.Put(key, value);
			break;
		case 2:
			cout << "请输入要删除的key：";
			cin >> key;
			L.Delete(key);
			break;
		case 3:
			cout << "请输入要查找值的key：";
			cin >> key;
			L.Get(key);
			break;
		case 4:
			L.Length();
			break;
		case 5:
			L.Print();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			break;
		}
	} while (choose);
	return 0;
}