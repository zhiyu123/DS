#include"Stack.h"

Stack::Stack()
{
	this->top = -1;		//ջ��Ϊ-1����ջ��
	this->length = 0;	//��ʼ����Ϊ0
	cout << "ջ��ʼ����ɣ��뿪ʼ������" << endl;
}

Stack::~Stack()
{
	//Ĭ����������
}

void Stack::Push(elemtype e)
{
	if (this->length >= MAXSIZE)
	{
		cout << "��ǰջ������ " << endl;
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
		cout << "��ǰջ�գ�" << endl;
	}
	else
	{
		cout << "������Ԫ��Ϊ��" << this->data[top] << endl;
		this->top--;
		this->length--;
	}
}

void Stack::PrintStack()
{
	if (this->length == 0)
	{
		cout << "��ǰջΪ�գ�" << endl;
	}
	else
	{
		cout << "��ǰջԪ��Ϊ��";
		for (int i = 0; i < length; i++)
		{
			cout << '\t' << this->data[i] << '\t';
		}
		cout << endl;
	}
}

void Stack::LengthStack()
{
	cout << "��ǰջ��Ԫ�ظ���Ϊ��" << length << endl;
}

void Stack::TopStack()
{
	if (this->length == 0)
	{
		cout << "��ǰջΪ�գ�û��ջ����" << endl;
	}
	else
	{
		cout << "��ǰջ��Ԫ��Ϊ��" << this->data[top] << endl;
	}
}