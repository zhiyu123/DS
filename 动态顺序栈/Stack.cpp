#include"Stack.h"

Stack::Stack()
{
	this->data = new elemtype[INITSIZE];		//��ʼ�����СΪ5
	this->top = -1;		//ջ��Ϊ-1����ջ��
	this->length = 0;	//��ʼ����Ϊ0
	this->capacity = INITSIZE;
	cout << "ջ��ʼ����ɣ��뿪ʼ������" << endl;
}

Stack::~Stack()
{
	delete data;
	data = NULL;
}

void Stack::CheckStack()		//���ݺ���
{
	if (this->length >= this->capacity)
	{
		elemtype* p_tmp = new elemtype[this->length + INITSIZE];	//ÿ�ζ�����INITSIZE��С
		for (int i = 0; i < this->length; i++)
		{
			p_tmp[i] = this->data[i];
		}
		this->capacity += INITSIZE;		//ʹԭ������+5
		elemtype* tmp = this->data;			//����һ����ʱ����������
		this->data = p_tmp;
		p_tmp = tmp;
		delete[]p_tmp;		//��ԭ�пռ��ͷ�
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
	cout << "��ǰ����Ϊ��" << capacity << endl;
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