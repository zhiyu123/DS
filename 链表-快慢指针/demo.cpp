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

	Node* Get_mid()				//通过快慢指针获取中间值
	{
		Node* slow = head;		//指向头节点
		Node* fast = head;		//指向头节点
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//快指针移动两个
			slow = slow->next;				//慢指针移动一个
		}
		return slow;
	}
	
	bool IsCircle()			//通过快慢指针判断单链表是否有环
	{
		Node* slow = head;
		Node* fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//快指针移动两个
			slow = slow->next;				//慢指针移动一个
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}

	Node* GetEn()			//通过快慢指针得到环的入口节点
	{
		//遍历链表，先找到环（快慢指针相遇），准备一个临时指针，指向链表的首结点，继续遍历，直到
		//满指针和临时指针相遇，那么相遇所指的节点就是环的入口结点
		Node* slow = head;
		Node* fast = head;
		Node* temp = NULL;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;		//快指针移动两个
			slow = slow->next;				//慢指针移动一个
			if (fast == slow)		//快慢指针相遇，有环
			{
				temp = head;		//让临时指针指向头节点，开始移动
				continue;
			}	
			if (temp != NULL)
			{
				temp = temp->next;			
				if (temp == slow)			//临时指针和慢指针相遇
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
	cout << "中间值为：" << ptr->data << endl;
	
	Node* p_tmp = L.head;
	while (L.head->next != NULL)
	{
		L.head = L.head->next;
	}
	L.head->next = ptr;				//构造一个环用来测试
	L.head = p_tmp;

	if (L.IsCircle())
	{ 
		cout << "单链表有环！" << endl;
	}
	else
	{
		cout << "单链表无环！" << endl;
	}

	Node* ptr2 = L.GetEn();
	cout << "环入口为：" << ptr2->data << endl;
}