#include"MinPriorityQueue.h"

MinPriorityQueue::MinPriorityQueue()						//构造函数
{
	this->data = new elemtype[CAPACITY + 1];		//为了方便从下标1开始存数据，会废除0，所以多加一个
	this->count = 0;
}

MinPriorityQueue::~MinPriorityQueue()
{
	delete[]data;
	data = NULL;
}

bool MinPriorityQueue::IsLess(int i, int j)				//判断堆中索引i处的元素是否小于索引j处的元素
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

void MinPriorityQueue::Swap(int i, int j)			//交换索引i和j处的元素
{
	int tmp = data[j];
	data[j] = data[i];
	data[i] = tmp;
}

elemtype MinPriorityQueue::DelMin()						//删除队列中最小的元素，并返回这个最小元素
{
	elemtype min = data[1];
	Swap(1, count);
	data[count] = NULL;
	count--;
	Sink(1);
	return min;
}

void MinPriorityQueue::Insert(elemtype e)				//插入一个元素
{
	data[++count] = e;
	Swim(count);
}

void MinPriorityQueue::Swim(int k)						//使用上浮算法，使索引k处的元素插入的合适的位置
{
	while (k > 1)
	{
		if (IsLess(k, k / 2))
		{
			Swap(k / 2, k);			//小于父亲往上走
		}
		k = k / 2;
	}
}

void MinPriorityQueue::Sink(int k)					//使用下沉算法，使索引k处的元素插入到合适的位置
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

int MinPriorityQueue::Size()								//获取队列中元素的个数
{
	return this->count;
}

bool MinPriorityQueue::Empty()							//判断队列是否为空
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
