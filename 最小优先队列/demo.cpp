#include"MinPriorityQueue.h"

int main()
{
	MinPriorityQueue q;
	q.Insert(32);
	q.Insert(43);
	q.Insert(22);
	q.Insert(65);
	q.Insert(8);
	q.Insert(23);
	q.Insert(4);
	q.Insert(5);
	q.Insert(77);
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "ɾ������СԪ��Ϊ��" << q.DelMin() << endl;
	cout << "���еĳ���Ϊ��" << q.Size() << endl;;
	if (q.Empty())
	{
		cout << "����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "���в�Ϊ�գ�" << endl;
	}
	return 0;

}