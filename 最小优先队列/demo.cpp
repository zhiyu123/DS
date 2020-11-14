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
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "删除的最小元素为：" << q.DelMin() << endl;
	cout << "队列的长度为：" << q.Size() << endl;;
	if (q.Empty())
	{
		cout << "队列为空！" << endl;
	}
	else
	{
		cout << "队列不为空！" << endl;
	}
	return 0;

}