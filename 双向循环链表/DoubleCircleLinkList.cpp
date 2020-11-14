#include"DoubleCircleLinkList.h"

DoubleCircleLinkList::DoubleCircleLinkList()			//���캯��������ʼ������
{
	this->head = new Node;	//����һ��ͷ�ڵ�
	head->front = head;
	head->next = head;
	head->data = 0;				//ͷ�ڵ����������Բ��ù�
	this->length = 0;			//��ǰ����Ϊ0
	cout << "��ǰ�����ѳ�ʼ����ɣ��뿪ʼ������" << endl;
}

DoubleCircleLinkList::~DoubleCircleLinkList()   //��������������������
{
	delete head;
	this->head = NULL;
}

void DoubleCircleLinkList::ClearLinkList()		//�������
{
	head->next = head;
	head->front = head;
	head->data = 0;
	this->length = 0;
}

void DoubleCircleLinkList::PushFront(elemtype value)		//ͷ��
{
	if (0 == this->length)			//��ǰ����Ϊ��ʱ
	{
		head->next = new Node;
		head->next->next = head;
		head->next->front = head;
		head->front = head->next;
		head->next->data = value;
	}
	else
	{
		Node* tmp = new Node;			//����һ���½ڵ�������	
		tmp->next = head->next;
		head->next->front = tmp;
		head->next = tmp;
		tmp->front = head;
		tmp->data = value;
	}
	this->length++;		//���ȼ�һ
}

void DoubleCircleLinkList::PushBack(elemtype value)		//β��
{
	Node* p_tmp = head;				//���浱ǰͷָ��
	if (0 == this->length)			//��ǰ����Ϊ��ʱ
	{
		head->next = new Node;
		head->next->next = head;
		head->next->front = head;
		head->front = head->next;
		head->next->data = value;
	}
	else
	{
		while (head->next != p_tmp)		//�ҵ����һ���ڵ�
		{
			head = head->next;
		}
		head->next = new Node;		//���һ���ڵ��nextָ���½ڵ�
		head->next->next = p_tmp;		//�������½ڵ��nextָ��ͷ�ڵ�
		head->next->front = head;
		p_tmp->front = head->next;
		head->next->data = value;		//��ֵ
	}
	head = p_tmp;				//�ָ�ͷָ��
	this->length++;		//���ȼ�һ
}

void DoubleCircleLinkList::PopBack()		//βɾ
{
	Node* p_tmp = head;			//����ͷָ��
	if (0 == this->length)
	{
		cout << "��ǰ����Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		while (head->next->next != p_tmp)	//��ͷָ��ָ�����ڶ����ڵ�
		{
			head = head->next;
		}
		head->next = p_tmp;		//ɾ��β�ڵ�
		p_tmp->front = head;
	}
	this->length--;			//���ȼ�һ
	head = p_tmp;		//�ָ�ͷ�ڵ�
}

void DoubleCircleLinkList::PopFront()		//ͷɾ
{
	if (0 == this->length)
	{
		cout << "��ǰ����Ϊ�գ��޷�ɾ����" << endl;
	}
	else if (1 == this->length)
	{
		head->next = head;
		head->front = head;
	}
	else
	{
		head->next = head->next->next;
		head->next->front = head;
	}
	this->length--;	//���ȼ�һ
}

void DoubleCircleLinkList::InsertLinkList(int pos, elemtype value)		//������λ�ò���Ԫ��
{
	if (pos < 1 || pos > this->length + 1)
	{
		cout << "����Խ�磡" << endl;
	}
	else
	{
		Node* p_tmp = head;				//����ͷ�ڵ�
		for (int i = 0; i < pos - 1; i++)			//�ƶ���Ҫ����λ�õ�ǰһ��λ��
		{
			head = head->next;
		}
		if (head->next == p_tmp)			//�ڱ�β������head->next->front = tmp;
		{
			Node* tmp = new Node;
			tmp->next = head->next;
			tmp->front = head;
			head->next = tmp;
			p_tmp->front = tmp;
			tmp->data = value;
			head = p_tmp;			//�ָ�ͷָ��
			this->length++;			//���ȼ�һ
		}
		else
		{
			Node* tmp = new Node;
			tmp->next = head->next;
			head->next->front = tmp;
			tmp->front = head;
			head->next = tmp;
			tmp->data = value;
			head = p_tmp;			//�ָ�ͷָ��
			this->length++;			//���ȼ�һ
		}
	}
}

void DoubleCircleLinkList::DeleteLinkList(int pos)			//����λ��ɾ��Ԫ��
{
	if (pos < 1 || pos > this->length)
	{
		cout << "����Խ�磡" << endl;
	}
	else
	{
		if (0 == this->length)
		{
			cout << "��ǰ����Ϊ�գ��޷�ɾ����" << endl;
		}
		else
		{
			Node* p_tmp = head;
			for (int i = 0; i < pos - 1; i++)		//�ƶ���ɾ��Ԫ�ص�ǰһ��Ԫ��λ��
			{
				head = head->next;
			}
			if (head->next->next == p_tmp)		//ĩβԪ�ص�ɾ��
			{
				head->next = p_tmp;
				p_tmp->front = head;
				head = p_tmp;
				this->length--;
			}
			else
			{
				head->next = head->next->next;
			    head->next->front = head;
				head = p_tmp;
				this->length--;
			}
		}
	}
}

void DoubleCircleLinkList::PrintLinkList()		//��ӡ����
{
	if (this->length == 0)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		Node* p_tmp = head;
		cout << "��ǰ�����Ԫ��Ϊ��";
		while (head->next != p_tmp)
		{
			head = head->next;
			cout << '\t' << head->data << '\t';
		}
		cout << endl;
		head = p_tmp;
	}
}


void DoubleCircleLinkList::RPrintLinkList()		//�����ӡ����
{
	if (this->length == 0)
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
	}
	else
	{
		Node* p_tmp = head;
		cout << "��ǰ�����Ԫ��Ϊ��";
		while (head->front != p_tmp)
		{
			head = head->front;
			cout << '\t' << head->data << '\t';
		}
		cout << endl;
		head = p_tmp;
	}
}

void DoubleCircleLinkList::SearchLinkList(elemtype value)		//����Ԫ��
{
	int count = 0;
	Node* p_tmp = head;
	while (head->next != p_tmp)
	{
		head = head->next;			//��Ϊͷָ��ָ��ͷ�ڵ㣬�������ƶ�ͷָ�룬�ڴ�ӡ
		count++;
		if (head->data == value)
		{
			cout << "Ҫ��ѯ��Ԫ��λ��Ϊ��" << count << endl;
			head = p_tmp;
			return;
		}
	}
	cout << "�Ҳ�����Ԫ�أ�" << endl;
	head = p_tmp;
}

void DoubleCircleLinkList::Length()
{
	cout << "��ǰ����ĳ���Ϊ��" << this->length << endl;
}