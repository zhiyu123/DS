#include"Queue.h"

Queue::Queue()
{
	this->front = 0;		//��ʼ����Ϊ0
	this->rear = 0;
	this->length = 0;
	cout << "��ǰ�����ѳ�ʼ����ɣ�" << endl;
}

void Queue::PushQueue(elemtype e)
{
	if (rear == MAXSIZE - 1)
	{
		cout << "��ǰ����������" << endl;
	}
	else
	{
		this->data[rear] = e;
		rear++;				//ÿ����һ��Ԫ�أ�ʹrear+1
		this->length++;
	}
}

void Queue::PopQueue()
{
	if (this->front == this->rear)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		front++;				//front+1����ǰһ��Ԫ��ɾ����
		this->length--;
	}
}

void Queue::LengthQueue()
{
	cout << "��ǰ���г���Ϊ��" << this->length << endl;
}

void Queue::PrintQueue()
{
	if (this->length == 0)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ǰ����Ԫ��Ϊ��";
		for (int i = front; i < rear; i++)
		{
			cout << '\t' << this->data[i] << '\t';
		}
		cout << endl;
	}
}