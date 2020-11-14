#include"LinkStack.h"

LinkStack::LinkStack()			//���캯����ʼ��ջ
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;		//����Ϊ0
	cout << "��ջ��ʼ����ɣ�" << endl;
}

LinkStack::~LinkStack()			//��������
{
	delete head;
	head = NULL;
	delete tail;
	tail = NULL;
}

void LinkStack::Pop()		//��ջ
{
	if (0 == this->length)
	{
		cout << "��ǰջΪ�գ�" << endl;
	}
	else
	{
		if (head == tail)		//���ջ��ֻ��һ��Ԫ�أ���Ҫ���⴦��
		{
			this->head = NULL;
			this->tail = NULL;
			this->length--;
		}
		else
		{
			Node* p_tmp = head;		//����ͷָ��
			cout << "��ջ��Ԫ��Ϊ��" << tail->data << endl;
			while (head->next != tail)		//�ҵ������ڶ����ڵ�
			{
				head = head->next;
			}
			tail = head;		//����ǰ�ڵ��tail
			tail->next = NULL;
			head = p_tmp;		//�ָ�ͷָ��
			this->length--;
		}
	}
}

void LinkStack::Push(elemtype e)	//��ջ
{
	Node* p_tmp = new Node;
	if (0 == this->length)
	{
		head = p_tmp;
		tail = p_tmp;
		head->next = NULL;
		head->data = e;
	}
	else
	{
		tail->next = p_tmp;
		p_tmp->next = NULL;
		tail = p_tmp;
		tail->data = e;
	}
	this->length++;
}

void LinkStack::PrintStack()	//��ӡջ
{
	if (0 == this->length)
	{
		cout << "��ǰջΪ�գ�" << endl;
	}
	else
	{
		Node* p_tmp = head;
		cout << "ջԪ��Ϊ��";
		while (head != NULL)
		{
			cout << '\t' << head->data << '\t';
			head = head->next;
		}
		head = p_tmp;
		cout << endl;
	}
}

void LinkStack::LengthStack()		//�󳤶�
{
	cout << "��ǰջ����Ϊ��" << this->length << endl;
}

void LinkStack::TopStack()		//��ջ��Ԫ��
{
	if (0 == this->length)
	{
		cout << "��ǰջΪ�գ�" << endl;
	}
	else
	{
		cout << "��ǰջ��Ԫ��Ϊ��" << tail->data << endl;
	}
}