#include"MaxPriorityQueue.h"

MaxPriorityQueue::MaxPriorityQueue()						//构造函数
{
	this->data = new elemtype[CAPACITY];
	this->count = 0;
}

MaxPriorityQueue::~MaxPriorityQueue()
{
	delete[]data;
	data = NULL;
}

bool MaxPriorityQueue::IsLess(int i, int j)				//判断堆中索引i处的元素是否小于索引j处的元素
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

void MaxPriorityQueue::Swap(int i, int j)			//交换索引i和j处的元素
{
	int tmp = data[j];
	data[j] = data[i];
	data[i] = tmp;
}

elemtype MaxPriorityQueue::DelMax()						//删除队列中最大的元素，并返回这个最大元素
{
	elemtype max = data[1];
	Swap(1, count);
	data[count] = NULL;
	count--;
	Sink(1);
	return max;
}

void MaxPriorityQueue::Insert(elemtype e)				//插入一个元素
{
	data[++count] = e;
	Swim(count);
}

void MaxPriorityQueue::Swim(int k)						//使用上浮算法，使索引k处的元素插入的合适的位置
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

void MaxPriorityQueue::Sink(int k)					//使用下沉算法，使索引k处的元素插入到合适的位置
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

int MaxPriorityQueue::Size()								//获取队列中元素的个数
{
	return this->count;
}

bool MaxPriorityQueue::Empty()							//判断队列是否为空
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