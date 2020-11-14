#include"MaxPriorityQueue.h"

MaxPriorityQueue::MaxPriorityQueue()						//���캯��
{
	this->data = new elemtype[CAPACITY];
	this->count = 0;
}

MaxPriorityQueue::~MaxPriorityQueue()
{
	delete[]data;
	data = NULL;
}

bool MaxPriorityQueue::IsLess(int i, int j)				//�ж϶�������i����Ԫ���Ƿ�С������j����Ԫ��
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

void MaxPriorityQueue::Swap(int i, int j)			//��������i��j����Ԫ��
{
	int tmp = data[j];
	data[j] = data[i];
	data[i] = tmp;
}

elemtype MaxPriorityQueue::DelMax()						//ɾ������������Ԫ�أ�������������Ԫ��
{
	elemtype max = data[1];
	Swap(1, count);
	data[count] = NULL;
	count--;
	Sink(1);
	return max;
}

void MaxPriorityQueue::Insert(elemtype e)				//����һ��Ԫ��
{
	data[++count] = e;
	Swim(count);
}

void MaxPriorityQueue::Swim(int k)						//ʹ���ϸ��㷨��ʹ����k����Ԫ�ز���ĺ��ʵ�λ��
{
	while (k > 1)
	{
		if (IsLess(k / 2, k))
		{
			Swap(k / 2, k);
		}
		k = k / 2;
	}
}

void MaxPriorityQueue::Sink(int k)					//ʹ���³��㷨��ʹ����k����Ԫ�ز��뵽���ʵ�λ��
{
	while (2 * k <= count)
	{
		int max;
		if (2 * k + 1 <= count)
		{
			if (IsLess(2 * k, 2 * k + 1))
			{
				max = 2 * k + 1;
			}
			else
			{
				max = 2 * k;
			}
		}
		else
		{
			max = 2 * k;
		}

		if (!IsLess(k, max))
		{
			break;
		}
		Swap(k, max);
		k = max;
	}
}

int MaxPriorityQueue::Size()								//��ȡ������Ԫ�صĸ���
{
	return this->count;
}

bool MaxPriorityQueue::Empty()							//�ж϶����Ƿ�Ϊ��
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