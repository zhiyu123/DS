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
	void Create()				//构建循环链表
	{
		Node* tmp = NULL;
		for (int i = 1; i <= 41; i++)
		{
			if (i == 1)   //构建第一个元素
			{
				head = new Node;
				head->data = i;
				head->next = NULL;
				tmp = head;
			}
			else if (i == 41)		//构造最后一个结点
			{
				head->next = new Node;
				head->next->data = i;
				head->next->next = tmp;			//最后一个元素的next指向头节点
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
			cout << "当前链表为空！" << endl;
		}
		else
		{
			while (head->next != tmp)
			{
				cout << head->data << " ";
				head = head->next;
			}
			cout << head->data << endl;		//打印链表最后一个元素
		}
		head = tmp;
	}

	void Solution()				//解决方案
	{
		Node* curr = head;		//记录当前节点
		Node* pre = NULL;		//记录上一个结点
		int count = 0;			//计数
		while (curr != curr->next)		//只剩下一个元素时，他的next指向自己,就停止循环，所以不等于就循环
		{
			count++;
			if (3 == count)
			{
				cout << curr->data << " ";		//打印淘汰的数
				pre->next = curr->next;				//删除报3的结点
				curr = curr->next;					//移动一位curr
				count = 0;					//每次到3重置count
			}
			else
			{
				pre = curr;
				curr = curr->next;
			}
		}
		cout << curr->data << endl;			//打印最后一个数
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