#include"Stack.h"

Stack::Stack()
{
	this->data = new elemtype[INITSIZE];		//初始数组大小为5
	this->top = -1;		//栈顶为-1代表栈空
	this->length = 0;	//初始长度为0
	this->capacity = INITSIZE;
	cout << "栈初始化完成，请开始操作！" << endl;
}

Stack::~Stack()
{
	delete data;
	data = NULL;
}

void Stack::CheckStack()		//扩容函数
{
	if (this->length >= this->capacity)
	{
		elemtype* p_tmp = new elemtype[this->length + INITSIZE];	//每次多扩容INITSIZE大小
		for (int i = 0; i < this->length; i++)
		{
			p_tmp[i] = this->data[i];
		}
		this->capacity += INITSIZE;		//使原有容量+5
		elemtype* tmp = this->data;			//申请一个临时变量来交换
		this->data = p_tmp;
		p_tmp = tmp;
		delete[]p_tmp;		//将原有空间释放
		p_tmp = NULL;
	}
}

void Stack::Push(elemtype e)
{
	CheckStack();
	this->data[top + 1] = e;
	this->length++;
	this->top++;
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
	cout << "当前容量为：" << capacity << endl;
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