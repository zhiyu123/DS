#include"Queue.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*********************************************************" << endl;
	cout << "**************   1.���        2.����      **************" << endl;
	cout << "**************   3.�󳤶�      4.��ӡ      **************" << endl;
	cout << "**************   0.�˳�                    **************" << endl;
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
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "�˳��ɹ���" << endl;
			break;
		case 1:
			cout << "������Ҫ�����Ԫ�أ�";
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
			cout << "�����������������!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
