#include"SqList.h"
#pragma warning(disable:6031) 

void menu()
{
	printf("*******************************************************************\n");
	printf("**************   1.��ӡ˳���       2.�鿴�����ͳ��� **************\n");
	printf("**************   3.ͷ��             4.β��           **************\n");
	printf("**************   5.ͷɾ             6.βɾ           **************\n");
	printf("**************   7.����λ�ò���     8.����λ��ɾ��   **************\n");
	printf("**************   9.��ѯĳԪ�ص�λ�� 10.����          **************\n");
	printf("**************   11.���            0.�˳�           **************\n");
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
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "�˳��ɹ���" << endl;
			break;
		case 1:
			L.PrintList();
			break;
		case 2:
			L.ShowCapacityLength();
			break;
		case 3:
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> num;
			L.PushPront(num);
			break;
		case 4:
			cout << "������Ҫ�����Ԫ�أ�";
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
			cout << "����������λ�ã�";
			cin >> pos;
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> num;
			L.InsertElem(pos, num);
			break;
		case 8:
			cout << "������Ҫɾ����λ�ã�";
			cin >> pos;
			L.DeleteElem(pos);
			break;
		case 9:
			cout << "������Ҫ��ѯ��Ԫ�أ�";
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
			cout << "�����������������!" << endl;
			break;
		}
	} while (choose);
	return 0;
}
