#include<iostream>
using namespace std;

class Node
{
public:
	Node()
	{
		next = NULL;
		data = 0;
	}

public:
	Node* next;
	int data;
};

class LinkList
{
public:
	LinkList()
	{
		this->head = new Node;
		head->data = 0;
		head->next = NULL;
	}

	void Insert(int e)
	{
		Node* tmp = head;

		while (head->next != NULL)
		{
			head = head->next;
		}

		head->next = new Node;
		head->next->data = e;
		head->next->next = NULL;

		head = tmp;
	}

	void Print()
	{
		Node* tmp = head;
		while (head->next != NULL)
		{
			head = head->next;
			cout << head->data << " ";
		}
		head = tmp;
	}

	Node* Get_mid()				//ͨ������ָ���ȡ�м�ֵ
	{
		Node* slow = head;		//ָ��ͷ�ڵ�
		Node* fast = head;		//ָ��ͷ�ڵ�
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//��ָ���ƶ�����
			slow = slow->next;				//��ָ���ƶ�һ��
		}
		return slow;
	}
	
	bool IsCircle()			//ͨ������ָ���жϵ������Ƿ��л�
	{
		Node* slow = head;
		Node* fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//��ָ���ƶ�����
			slow = slow->next;				//��ָ���ƶ�һ��
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}

	Node* GetEn()			//ͨ������ָ��õ�������ڽڵ�
	{
		//�����������ҵ���������ָ����������׼��һ����ʱָ�룬ָ��������׽�㣬����������ֱ��
		//��ָ�����ʱָ����������ô������ָ�Ľڵ���ǻ�����ڽ��
		Node* slow = head;
		Node* fast = head;
		Node* temp = NULL;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//��ָ���ƶ�����
			slow = slow->next;				//��ָ���ƶ�һ��
			if (fast == slow)		//����ָ���������л�
			{
				temp = head;		//����ʱָ��ָ��ͷ�ڵ㣬��ʼ�ƶ�
				continue;
			}	
			if (temp != NULL)
			{
				temp = temp->next;			
				if (temp == slow)			//��ʱָ�����ָ������
				{
					break;
				}
			}
		}
		return temp;
	}

public:
	Node* head;
};

int main()
{
	LinkList L;
	L.Insert(3);
	L.Insert(4);
	L.Insert(7);
	L.Insert(9);
	L.Insert(1);
	L.Insert(2);
	
	L.Print();
	cout << endl;
	Node* ptr = L.Get_mid();
	cout << "�м�ֵΪ��" << ptr->data << endl;
	
	Node* p_tmp = L.head;
	while (L.head->next != NULL)
	{
		L.head = L.head->next;
	}
	L.head->next = ptr;				//����һ������������
	L.head = p_tmp;

	if (L.IsCircle())
	{ 
		cout << "�������л���" << endl;
	}
	else
	{
		cout << "�������޻���" << endl;
	}

	Node* ptr2 = L.GetEn();
	cout << "�����Ϊ��" << ptr2->data << endl;
}