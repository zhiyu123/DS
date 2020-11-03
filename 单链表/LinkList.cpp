#include"LinkList.h"

LinkList::LinkList()			//构造函数用来初始化链表
{
	this->head = new Node;	//申请一个头节点
	head->next = NULL;      //代表当前为空表
	head->data = 0;				//头节点的数据域可以不用管
	this->length = 0;			//当前长度为0
	cout << "当前链表已初始化完成，请开始操作！" << endl;
}

LinkList::~LinkList()   //析构函数用来销毁链表
{
	delete head;
	this->head = NULL;		//置为空链表
}

void LinkList::ClearLinkList()		//清空链表
{
	head->next = NULL;
	head->data = 0;
	this->length = 0;
}

void LinkList::PushFront(elemtype value)		//头插
{
	if (0 == this->length)			//当前链表为空时
	{
		head->next = new Node;
		head->next->next = NULL;
		head->next->data = value;
	}
	else
	{
		Node* tmp = new Node;	//申请一个新节点来插入	
		tmp->data = value;
		tmp->next = head->next;
		head->next = tmp;
	}
	this->length++;		//长度加一
}

void LinkList::PushBack(elemtype value)		//尾插
{
	Node* p_tmp = head;				//保存当前头指针
	if (0 == this->length)			//当前链表为空时
	{
		head->next = new Node;
		head->next->next = NULL;
		head->next->data = value;
	}
	else
	{
		while (head->next != NULL)		//找到最后一个节点
		{
			head = head->next;
		}
		head->next = new Node;		//最后一个节点的next指向新节点
		head->next->data = value;		//赋值
		head->next->next = NULL;		//让最后的新节点的next指向NULL
	}
	head = p_tmp;				//恢复头指针
	this->length++;		//长度加一
}

void LinkList::PopBack()		//尾删
{
	Node* p_tmp = head;			//保存头指针
	if (0 == this->length)
	{
		cout << "当前链表为空，无法删除！" << endl;
	}
	else
	{
		while (head->next->next != NULL)	//让头指针指向倒数第二个节点
		{
			head = head->next;
		}
		head->next = NULL;		//删除尾节点
	}
	this->length--;			//长度减一
	head = p_tmp;		//恢复头节点
}

void LinkList::PopFront()		//头删
{
	if (0 == this->length)
	{
		cout << "当前链表为空，无法删除！" << endl;
	}
	else if(this->length == 1)
	{
		head->next = NULL;
	}
	else
	{
		head->next = head->next->next;
	}
	this->length--;	//长度减一
}

void LinkList::InsertLinkList(int pos, elemtype value)		//在任意位置插入元素
{
	if (pos < 1 || pos > this->length + 1)
	{
		cout << "输入越界！" << endl;
	}
	else
	{
		Node* p_tmp = head;				//保存头节点
		for (int i = 0; i < pos - 1; i++)			//移动到要插入位置的前一个位置
		{
			head = head->next;
		}
		Node* tmp = new Node;
		tmp->next = head->next;
		head->next = tmp;
		tmp->data = value;
		head = p_tmp;			//恢复头指针
		this->length++;			//长度加一
	}
}

void LinkList::DeleteLinkList(int pos)			//任意位置删除元素
{
	if (pos < 1 || pos > this->length)
	{
		cout << "输入越界！" << endl;
	}
	else
	{
		if (0 == this->length)
		{
			cout << "当前链表为空，无法删除！" << endl;
		}
		else
		{
			Node* p_tmp = head;
			for (int i = 0; i < pos - 1; i++)//移动到要删除位置的前一个位置
			{
				head = head->next;
			}
			head->next = head->next->next;
			head = p_tmp;
			this->length--;
		}
	}
}

void LinkList::PrintLinkList()		//打印链表
{
	if (this->length == 0)
	{
		cout << "当前链表为空！" << endl;
	}
	else
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
}

void LinkList::SearchLinkList(elemtype value)		//查找元素
{
	int count = 0;
	Node* p_tmp = head;	
	while (head->next != NULL)
	{
		head = head->next;			//因为头指针指向头节点，所以先移动头指针，在打印
		count++;
		if (head->data == value)
		{
			cout << "要查询的元素位置为：" << count << endl;
			head = p_tmp;
			return;
		}
	}
	cout << "找不到此元素！" << endl;
	head = p_tmp;
}

void LinkList::Length()
{
	cout << "当前链表的长度为：" << this->length << endl;
}