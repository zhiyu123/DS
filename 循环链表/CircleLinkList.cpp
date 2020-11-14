#include"CircleLinkList.h"

CircleLinkList::CircleLinkList()			//���캯��������ʼ������
{
	this->head = new Node;	//����һ��ͷ�ڵ�
	head->next = head;      //head->next = headʱ����ǰΪ�ձ�
	head->data = 0;				//ͷ�ڵ����������Բ��ù�
	this->length = 0;			//��ǰ����Ϊ0
	cout << "��ǰ�����ѳ�ʼ����ɣ��뿪ʼ������" << endl;
}

CircleLinkList::~CircleLinkList()   //��������������������
{
	delete head;
	this->head = NULL;		//��Ϊ������
}

void CircleLinkList::ClearLinkList()		//�������
{
	head->next = head;
	head->data = 0;
	this->length = 0;
}

void CircleLinkList::PushFront(elemtype value)		//ͷ��
{
	if (0 == this->length)			//��ǰ����Ϊ��ʱ
	{
		head->next = new Node;
		head->next->next = head;
		head->next->data = value;
	}
	else
	{
		Node* tmp = new Node;	//����һ���½ڵ�������	
		tmp->data = value;
		tmp->next = head->next;
		head->next = tmp;
	}
	this->length++;		//���ȼ�һ
}

void CircleLinkList::PushBack(elemtype value)		//β��
{
	Node* p_tmp = head;				//���浱ǰͷָ��
	if (0 == this->length)			//��ǰ����Ϊ��ʱ
	{
		head->next = new Node;
		head->next->next = head;
		head->next->data = value;
	}
	else
	{
		while (head->next != p_tmp)		//�ҵ����һ���ڵ㣬������head����Ϊѭ������head���ƶ�������ѭ��
		{
			head = head->next;
		}
		head->next = new Node;		//���һ���ڵ��nextָ���½ڵ�
		head->next->data = value;		//��ֵ
		head->next->next = p_tmp;		//�������½ڵ��nextָ��head
	}
	head = p_tmp;				//�ָ�ͷָ��
	this->length++;		//���ȼ�һ
}

void CircleLinkList::PopBack()		//βɾ
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
	}
	this->length--;			//���ȼ�һ
	head = p_tmp;		//�ָ�ͷ�ڵ�
}

void CircleLinkList::PopFront()		//ͷɾ
{
	if (0 == this->length)
	{
		cout << "��ǰ����Ϊ�գ��޷�ɾ����" << endl;
	}
	else if (this->length == 1)
	{
		head->next = head;
	}
	else
	{
		head->next = head->next->next;
	}
	this->length--;	//���ȼ�һ
}

void CircleLinkList::InsertLinkList(int pos, elemtype value)		//������λ�ò���Ԫ��
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
		Node* tmp = new Node;
		tmp->next = head->next;
		head->next = tmp;
		tmp->data = value;
		head = p_tmp;			//�ָ�ͷָ��
		this->length++;			//���ȼ�һ
	}
}

void CircleLinkList::DeleteLinkList(int pos)			//����λ��ɾ��Ԫ��
{
	if (pos < 1 || pos > length)
	{
		cout << "Խ���ˣ�" << endl;
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
			for (int i = 0; i < pos - 1; i++)	//�ƶ���Ҫɾ��λ�õ�ǰһ��λ��
			{
				head = head->next;
			}
			head->next = head->next->next;
			head = p_tmp;
			this->length--;
		}
	}
}

void CircleLinkList::PrintLinkList()		//��ӡ����
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

void CircleLinkList::SearchLinkList(elemtype value)		//����Ԫ��
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

void CircleLinkList::Length()
{
	cout << "��ǰ����ĳ���Ϊ��" << this->length << endl;
}