#include"LinkStack.h"

LinkStack::LinkStack()			//构造函数初始化栈
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;		//长度为0
	cout << "链栈初始化完成！" << endl;
}

LinkStack::~LinkStack()			//析构函数
{
	delete head;
	head = NULL;
	delete tail;
	tail = NULL;
}

void LinkStack::Pop()		//出栈
{
	if (0 == this->length)
	{
		cout << "当前栈为空！" << endl;
	}
	else
	{
		if (head == tail)		//如果栈中只有一个元素，需要特殊处理
		{
			this->head = NULL;
			this->tail = NULL;
			this->length--;
		}
		else
		{
			Node* p_tmp = head;		//保存头指针
			cout << "出栈的元素为：" << tail->data << endl;
			while (head->next != tail)		//找到倒数第二个节点
			{
				head = head->next;
			}
			tail = head;		//将当前节点给tail
			tail->next = NULL;
			head = p_tmp;		//恢复头指针
			this->length--;
		}
	}
}

void LinkStack::Push(elemtype e)	//入栈
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

void LinkStack::PrintStack()	//打印栈
{
	if (0 == this->length)
	{
		cout << "当前栈为空！" << endl;
	}
	else
	{
		Node* p_tmp = head;
		cout << "栈元素为：";
		while (head != NULL)
		{
			cout << '\t' << head->data << '\t';
			head = head->next;
		}
		head = p_tmp;
		cout << endl;
	}
}

void LinkStack::LengthStack()		//求长度
{
	cout << "当前栈长度为：" << this->length << endl;
}

void LinkStack::TopStack()		//求栈顶元素
{
	if (0 == this->length)
	{
		cout << "当前栈为空！" << endl;
	}
	else
	{
		cout << "当前栈顶元素为：" << tail->data << endl;
	}
}