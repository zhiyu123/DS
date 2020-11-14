#include"LinkQueue.h"

LinkQueue::LinkQueue()
{

	this->front = new Node;		//头节点
	this->rear = front;			//头指针和尾指针都指向头节点
	this->front->next = NULL;		//next指向NULL
	this->length = 0;
	cout << "当前队列已初始化完成！" << endl;
}

LinkQueue::~LinkQueue()		//析构函数
{
	delete front;
	front = NULL;
	delete rear;
	rear = NULL;
}

void LinkQueue::PushQueue(elemtype e)		//入队
{
	rear->next = new Node;
	rear = rear->next;
	rear->next = NULL;
	rear->data = e;
	this->length++;
}

void LinkQueue::PopQueue()		//出队
{
	if (this->front == this->rear)		//相等为空
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{
		if (this->front->next == this->rear)	//只剩一个节点时，头指针的next和尾指针指向的节点一样
		{
			rear = front;			//都指向头节点，代表链队列为空
			front->next = NULL;
			this->length--;
		}
		else
		{
			front->next = front->next->next;	//直接跳过第一个元素,即删除
			this->length--;
		}
	}
}

void LinkQueue::LengthQueue()
{
	cout << "当前队列长度为：" << this->length << endl;
}

void LinkQueue::PrintQueue()
{
	if (this->front == this->rear)
	{
		cout << "当前队列为空！" << endl;
	}
	else
	{
		Node* p_tmp = front;					//保存头指针
		cout << "当前队列元素为：";
		while(this->front != this->rear)
		{
			front = front->next;
			cout << '\t' << front->data << '\t';		//打印
		}
		front = p_tmp;			//回复头指针
		cout << endl;
	}
}