#include"Stack.h"

Stack::Stack()
{
	this->top = -1;		//栈顶为-1代表栈空
	this->length = 0;	//初始长度为0
	cout << "栈初始化完成，请开始操作！" << endl;
}

Stack::~Stack()
{
	//默认析构即可
}

void Stack::Push(elemtype e)
{
	if (this->length >= MAXSIZE)
	{
		cout << "当前栈已满！ " << endl;
	}
	else
	{
		this->data[top + 1] = e;
		this->length++;
		this->top++;
	}
}

void Stack::Pop()
{
	if (this->length == 0)
	{
		cout << "当前栈空！" << endl;
	}
	else
	{
		cout << "弹出的元素为：" << this->data[top] << endl;
		this->top--;
		this->length--;
	}
}

void Stack::PrintStack()
{
	if (this->length == 0)
	{
		cout << "当前栈为空！" << endl;
	}
	else
	{
		cout << "当前栈元素为：";
		for (int i = 0; i < length; i++)
		{
			cout << '\t' << this->data[i] << '\t';
		}
		cout << endl;
	}
}

void Stack::LengthStack()
{
	cout << "当前栈的元素个数为：" << length << endl;
}

void Stack::TopStack()
{
	if (this->length == 0)
	{
		cout << "当前栈为空，没有栈顶！" << endl;
	}
	else
	{
		cout << "当前栈顶元素为：" << this->data[top] << endl;
	}
}