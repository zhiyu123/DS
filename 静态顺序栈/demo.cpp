#include"Stack.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.��ջ             2.�鿴����       **************" << endl;
	cout << "**************   3.��ջ             4.��ӡջ         **************" << endl;
	cout << "**************   5.��ջ��           0.�˳�           **************" << endl;
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
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "�˳��ɹ���" << endl;
			break;
		case 1:
			L.Pop();
			break;
		case 2:
			L.LengthStack();
			break;
		case 3:
			cout << "������Ҫ�����Ԫ�أ�";
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
			cout << "�����������������!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
