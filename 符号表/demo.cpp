#include"SymbolTable.h"
#pragma warning(disable:6031) 

void menu()
{
	cout << "*******************************************************************" << endl;
	cout << "**************   1.����             2.ɾ��           **************" << endl;
	cout << "**************   3.����             4.�󳤶�         **************" << endl;
	cout << "**************   5.��ӡ             0.�˳�           **************" << endl;
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
		cout << "��ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "�˳��ɹ���" << endl;
			break;
		case 1:
			cout << "������Ҫ�����key��";
			cin >> key;
			cout << "������Ҫ�����value��";
			cin >> value;
			L.Put(key, value);
			break;
		case 2:
			cout << "������Ҫɾ����key��";
			cin >> key;
			L.Delete(key);
			break;
		case 3:
			cout << "������Ҫ����ֵ��key��";
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
			cout << "�����������������!" << endl;
			break;
		}
	} while (choose);
	return 0;
}