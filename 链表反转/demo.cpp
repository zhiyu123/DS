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

	void PushFront(int value)		//头插
	{
		Node* tmp = new Node;	//申请一个新节点来插入	
		tmp->data = value;
		tmp->next = head->next;
		head->next = tmp;
	}

	void PrintLinkList()		//打印链表
	{
		Node* p_tmp = head;
		cout << "当前链表的元素为：";
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
		//判断当前链表是否为空链表，如果是空链表，则退出，如果不是，则调用重载reverse完成反转
		if (head->next == NULL)
		{
			return;
		}
		reverse(head->next);	//反转第一个节点
	}

	Node* reverse(Node* curr)			//反转指定的结点curr，并把反转后的结点返回
	{  
		if (curr->next == NULL)		//递归结束条件
		{
			head->next = curr;	//让头指针指向最后一个元素
			return curr;				//返回最后一个元素
		}
		//递归反转当前节点curr的下一个节点,返回值就是链表反转后，当前结点的上一个结点
		Node* pre = reverse(curr->next);
		
		//让返回节点的下一个结点变为当前结点curr 
		pre->next = curr;

		//每次都把当前节点的下一个节点变为NULL
		curr->next = NULL;

		return curr;	//返回当前节点
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

