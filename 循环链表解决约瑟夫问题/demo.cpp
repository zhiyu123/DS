#include<iostream>
using namespace std;

class Node
{
public:
	Node()
	{
		data = 0;
		next = NULL;
	}

public:
	int data;
	Node* next;
};

class CircleLink
{
public:
	void Create()				//����ѭ������
	{
		Node* tmp = NULL;
		for (int i = 1; i <= 41; i++)
		{
			if (i == 1)   //������һ��Ԫ��
			{
				head = new Node;
				head->data = i;
				head->next = NULL;
				tmp = head;
			}
			else if (i == 41)		//�������һ�����
			{
				head->next = new Node;
				head->next->data = i;
				head->next->next = tmp;			//���һ��Ԫ�ص�nextָ��ͷ�ڵ�
			}
			else                            //1-41
			{
				head->next = new Node;
				head->next->data = i;
				head->next->next = NULL;
				head = head->next;
			}
		}
		head = tmp;
	}

	void Print()
	{
		Node* tmp = head;
		if (head == NULL)
		{
			cout << "��ǰ����Ϊ�գ�" << endl;
		}
		else
		{
			while (head->next != tmp)
			{
				cout << head->data << " ";
				head = head->next;
			}
			cout << head->data << endl;		//��ӡ�������һ��Ԫ��
		}
		head = tmp;
	}

	void Solution()				//�������
	{
		Node* curr = head;		//��¼��ǰ�ڵ�
		Node* pre = NULL;		//��¼��һ�����
		int count = 0;			//����
		while (curr != curr->next)		//ֻʣ��һ��Ԫ��ʱ������nextָ���Լ�,��ֹͣѭ�������Բ����ھ�ѭ��
		{
			count++;
			if (3 == count)
			{
				cout << curr->data << " ";		//��ӡ��̭����
				pre->next = curr->next;				//ɾ����3�Ľ��
				curr = curr->next;					//�ƶ�һλcurr
				count = 0;					//ÿ�ε�3����count
			}
			else
			{
				pre = curr;
				curr = curr->next;
			}
		}
		cout << curr->data << endl;			//��ӡ���һ����
	}

public:
	Node* head;
};


int main()
{
	CircleLink L;
	L.Create();
	L.Print();
	L.Solution();
	return 0;
}