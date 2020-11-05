#include"Queue.h"

Queue::Queue()
{
	this->front = 0;		//初始化都为0
	this->rear = 0;
	this->length = 0;
	cout << "当前队列已初始化完成！" << endl;
}

void Queue::PushQueue(elemtype e)
{
	if (rear == MAXSIZE - 1)
	{
		cout << "当前队列已满！" << endl;
	}
	else
	{
		this->data[rear] = e;
		rear++;				//每加入一个元素，使rear+1
		this->length++;
	}
}

void Queue::PopQueue()
{
	if (this->front == this->rear)
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{
		front++;				//front+1即把前一个元素删除了
		this->length--;
	}
}

void Queue::LengthQueue()
{
	cout << "当前队列长度为：" << this->length << endl;
}

void Queue::PrintQueue()
{
	if (this->length == 0)
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{
		cout << "当前队列元素为：";
		for (int i = front; i < rear; i++)
		{
			cout << '\t' << this->data[i] << '\t';
		}
		cout << endl;
	}
}