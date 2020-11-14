#include"CircleQueue.h"

CircleQueue::CircleQueue()
{
	this->front = 0;		//初始化都为0
	this->rear = 0;
	this->length = 0;
	cout << "当前队列已初始化完成！" << endl;
}

void CircleQueue::PushQueue(elemtype e)
{
	if ((rear + 1) % MAXSIZE == front)		//判断满的条件
	{
		cout << "当前队列已满！" << endl;
	}
	else
	{
		this->data[rear] = e;
		rear = (++rear) % MAXSIZE;				//每加入一个元素，使rear+1
		this->length++;
	}
}

void CircleQueue::PopQueue()
{
	if (this->front == this->rear)		//相等为空
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{
		front = (++front) % MAXSIZE;				//front+1即把前一个元素删除了
		this->length--;
	}
}

void CircleQueue::LengthQueue()
{
	cout << "当前队列长度为：" << this->length << endl;
}

void CircleQueue::PrintQueue()
{
	if (this->front == this->rear)
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{	
		int tmp = front;					//保存头指针
		cout << "当前队列元素为：";
		for (int i = 0; i < this->length; i++)
		{
			cout << '\t' << this->data[front % MAXSIZE] << '\t';		//打印
			this->front++;
		}
		front = tmp;			//回复头指针
		cout << endl;
	}
}