#include"MinPriorityQueue.h"

MinPriorityQueue::MinPriorityQueue()						//���캯��
{
	this->data = new elemtype[CAPACITY + 1];		//Ϊ�˷�����±�1��ʼ�����ݣ���ϳ�0�����Զ��һ��
	this->count = 0;
}

MinPriorityQueue::~MinPriorityQueue()
{
	delete[]data;
	data = NULL;
}

bool MinPriorityQueue::IsLess(int i, int j)				//�ж϶�������i����Ԫ���Ƿ�С������j����Ԫ��
{
	if (data[i] < data[j])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MinPriorityQueue::Swap(int i, int j)			//��������i��j����Ԫ��
{
	int tmp = data[j];
	data[j] = data[i];
	data[i] = tmp;
}

elemtype MinPriorityQueue::DelMin()						//ɾ����������С��Ԫ�أ������������СԪ��
{
	elemtype min = data[1];
	Swap(1, count);
	data[count] = NULL;
	count--;
	Sink(1);
	return min;
}

void MinPriorityQueue::Insert(elemtype e)				//����һ��Ԫ��
{
	data[++count] = e;
	Swim(count);
}

void MinPriorityQueue::Swim(int k)						//ʹ���ϸ��㷨��ʹ����k����Ԫ�ز���ĺ��ʵ�λ��
{
	while (k > 1)
	{
		if (IsLess(k, k / 2))
		{
			Swap(k / 2, k);			//С�ڸ���������
		}
		k = k / 2;
	}
}

void MinPriorityQueue::Sink(int k)					//ʹ���³��㷨��ʹ����k����Ԫ�ز��뵽���ʵ�λ��
{
	while (2 * k <= count)
	{
		int min;
		if (2 * k + 1 <= count)
		{
			if (IsLess(2 * k, 2 * k + 1))
			{
				min = 2 * k;
			}
			else
			{
				min = 2 * k + 1;
			}
		}
		else
		{
			min = 2 * k;
		}

		if (IsLess(k, min))
		{
			break;
		}
		Swap(k, min);
		k = min;
	}
}

int MinPriorityQueue::Size()								//��ȡ������Ԫ�صĸ���
{
	return this->count;
}

bool MinPriorityQueue::Empty()							//�ж϶����Ƿ�Ϊ��
{
	if (this->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
