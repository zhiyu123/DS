#include"DoubleCircleLinkList.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.�������         2.�鿴����       **************" << endl;
	cout << "**************   3.ͷ��             4.β��           **************" << endl;
	cout << "**************   5.ͷɾ             6.βɾ           **************" << endl;
	cout << "**************   7.����λ�ò���     8.����λ��ɾ��   **************" << endl;
	cout << "**************   9.��ѯĳԪ�ص�λ�� 10.��ӡ����      **************" << endl;
	cout << "**************   11.�����ӡ����    0.�˳�           **************" << endl;
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
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "�˳��ɹ���" << endl;
			break;
		case 1:
			L.ClearLinkList();
			break;
		case 2:
			L.Length();
			break;
		case 3:
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> num;
			L.PushFront(num);
			break;
		case 4:
			cout << "������Ҫ�����Ԫ�أ�";
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
			cout << "����������λ�ã�";
			cin >> pos;
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> num;
			L.InsertLinkList(pos, num);
			break;
		case 8:
			cout << "������Ҫɾ����λ�ã�";
			cin >> pos;
			L.DeleteLinkList(pos);
			break;
		case 9:
			cout << "������Ҫ��ѯ��Ԫ�أ�";
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
			cout << "�����������������!" << endl;
			break;
		}
	} while (choose);
	return 0;
}