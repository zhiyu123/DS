#include"LinkQueue.h"

LinkQueue::LinkQueue()
{

	this->front = new Node;		//ͷ�ڵ�
	this->rear = front;			//ͷָ���βָ�붼ָ��ͷ�ڵ�
	this->front->next = NULL;		//nextָ��NULL
	this->length = 0;
	cout << "��ǰ�����ѳ�ʼ����ɣ�" << endl;
}

LinkQueue::~LinkQueue()		//��������
{
	delete front;
	front = NULL;
	delete rear;
	rear = NULL;
}

void LinkQueue::PushQueue(elemtype e)		//���
{
	rear->next = new Node;
	rear = rear->next;
	rear->next = NULL;
	rear->data = e;
	this->length++;
}

void LinkQueue::PopQueue()		//����
{
	if (this->front == this->rear)		//���Ϊ��
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		if (this->front->next == this->rear)	//ֻʣһ���ڵ�ʱ��ͷָ���next��βָ��ָ��Ľڵ�һ��
		{
			rear = front;			//��ָ��ͷ�ڵ㣬����������Ϊ��
			front->next = NULL;
			this->length--;
		}
		else
		{
			front->next = front->next->next;	//ֱ��������һ��Ԫ��,��ɾ��
			this->length--;
		}
	}
}

void LinkQueue::LengthQueue()
{
	cout << "��ǰ���г���Ϊ��" << this->length << endl;
}

void LinkQueue::PrintQueue()
{
	if (this->front == this->rear)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		Node* p_tmp = front;					//����ͷָ��
		cout << "��ǰ����Ԫ��Ϊ��";
		while(this->front != this->rear)
		{
			front = front->next;
			cout << '\t' << front->data << '\t';		//��ӡ
		}
		front = p_tmp;			//�ظ�ͷָ��
		cout << endl;
	}
}