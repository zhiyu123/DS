#include<iostream>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
};

class Link
{
public:
	Link()
	{
		this->head = new Node;
		head->data = 0;
		head->next = NULL;
	}

	void PushFront(int value)		//ͷ��
	{
		Node* tmp = new Node;	//����һ���½ڵ�������	
		tmp->data = value;
		tmp->next = head->next;
		head->next = tmp;
	}

	void PrintLinkList()		//��ӡ����
	{
		Node* p_tmp = head;
		cout << "��ǰ�����Ԫ��Ϊ��";
		while (head->next != NULL)
		{
			head = head->next;
			cout << '\t' << head->data << '\t';
		}
		cout << endl;
		head = p_tmp;		
	}

	void reverse()
	{
		//�жϵ�ǰ�����Ƿ�Ϊ����������ǿ��������˳���������ǣ����������reverse��ɷ�ת
		if (head->next == NULL)
		{
			return;
		}
		reverse(head->next);	//��ת��һ���ڵ�
	}

	Node* reverse(Node* curr)			//��תָ���Ľ��curr�����ѷ�ת��Ľ�㷵��
	{  
		if (curr->next == NULL)		//�ݹ��������
		{
			head->next = curr;	//��ͷָ��ָ�����һ��Ԫ��
			return curr;				//�������һ��Ԫ��
		}
		//�ݹ鷴ת��ǰ�ڵ�curr����һ���ڵ�,����ֵ��������ת�󣬵�ǰ������һ�����
		Node* pre = reverse(curr->next);
		
		//�÷��ؽڵ����һ������Ϊ��ǰ���curr 
		pre->next = curr;

		//ÿ�ζ��ѵ�ǰ�ڵ����һ���ڵ��ΪNULL
		curr->next = NULL;

		return curr;	//���ص�ǰ�ڵ�
	}
public:
	Node* head;
};


int main()
{
	Node N1;
	Node N2;
	Node N3;
	Node N4;
	Link L;
	L.PushFront(2);
	L.PushFront(5);
	L.PushFront(7);
	L.PushFront(3);
	L.PrintLinkList();
	L.reverse();
	L.PrintLinkList();
	return 0;
}

