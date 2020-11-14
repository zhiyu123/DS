#include"CircleQueue.h"

CircleQueue::CircleQueue()
{
	this->front = 0;		//��ʼ����Ϊ0
	this->rear = 0;
	this->length = 0;
	cout << "��ǰ�����ѳ�ʼ����ɣ�" << endl;
}

void CircleQueue::PushQueue(elemtype e)
{
	if ((rear + 1) % MAXSIZE == front)		//�ж���������
	{
		cout << "��ǰ����������" << endl;
	}
	else
	{
		this->data[rear] = e;
		rear = (++rear) % MAXSIZE;				//ÿ����һ��Ԫ�أ�ʹrear+1
		this->length++;
	}
}

void CircleQueue::PopQueue()
{
	if (this->front == this->rear)		//���Ϊ��
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		front = (++front) % MAXSIZE;				//front+1����ǰһ��Ԫ��ɾ����
		this->length--;
	}
}

void CircleQueue::LengthQueue()
{
	cout << "��ǰ���г���Ϊ��" << this->length << endl;
}

void CircleQueue::PrintQueue()
{
	if (this->front == this->rear)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{	
		int tmp = front;					//����ͷָ��
		cout << "��ǰ����Ԫ��Ϊ��";
		for (int i = 0; i < this->length; i++)
		{
			cout << '\t' << this->data[front % MAXSIZE] << '\t';		//��ӡ
			this->front++;
		}
		front = tmp;			//�ظ�ͷָ��
		cout << endl;
	}
}