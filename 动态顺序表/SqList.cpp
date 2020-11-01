#include"SqList.h"

SqList::SqList():capacity(INITSIZE),length(0)	//���캯��,��ʼ������Ϊ5������Ϊ0
{
	this->data = new elemtype[INITSIZE];
	if (data == NULL)
	{
		cout << "�����ڴ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "�ڴ����ɹ�,��ʼ�����,��ִ�����������" << endl;
		cout << endl;
	}
}

SqList::~SqList()	//��������
{
	if (this->data != NULL)
	{
		delete []data;
		data = NULL;
		this->length = 0;
		this->capacity = INITSIZE;
	}
}

void SqList::IncreaseSize()    //�ӳ�˳���
{
	if (this->capacity <= this->length)   //����С�ڳ��� Ҫ����
	{
		elemtype* p_tmp = new elemtype[this->length + INITSIZE];  //ÿ������5����λ�Ĵ�С
		for (int i = 0; i < this->length; i++)
		{
			p_tmp[i] = this->data[i];
		}
		this->capacity += INITSIZE;
		elemtype* tmp = this->data;
		this->data = p_tmp;
		p_tmp = tmp;
		delete []p_tmp;				//�ͷ�ԭ�����ڴ�
		p_tmp = NULL;
	}
}

void SqList::InsertElem(int pos, elemtype value)	//����λ�ò���
{
	IncreaseSize();
	if (pos <= 0 || pos > (this->length + 1)) //���ܸ��ղ���
	{
		cout << "����λ�÷Ƿ�,�޷�����!" << endl;
	}
	else
	{
		for (int i = this->length - 1; i >= pos - 1; i--)
		{
			this->data[i + 1] = this->data[i];
		}
		this->data[pos - 1] = value;
		this->length++;
	}
}

void SqList::DeleteElem(int pos)	//����λ��ɾ��
{
	if (0 == this->length)
	{
		cout << "��ǰ˳���Ϊ�գ��޷�ɾ����" << endl;
	}
	else if (pos <= 0 || pos > (this->length))
	{
		cout << "ɾ��λ�÷Ƿ�,�޷�ɾ����" << endl;
	}
	else
	{
		for (int i = pos; i < this->length; i++)
		{
			this->data[i - 1] = this->data[i];
		}
		this->length--;
	}
}

void SqList::LocateElem(elemtype value) //��ѯĳԪ�ص�λ��
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->data[i] == value)
		{
			cout << "Ҫ��ѯ��Ԫ��λ��Ϊ��" << i + 1 << endl;
			return;
		}
	}
	cout << "��Ԫ�ز����ڣ�" << endl;
}

void SqList::PrintList()    //��ӡ˳���
{
	if (0 == this->length)
	{
		cout << "��ǰ˳�����Ԫ��Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ǰ˳����е�Ԫ��Ϊ��";
		for (int i = 0; i < this->length; i++)
		{
			cout << "\t" << this->data[i] << "\t"; 
		}
		cout << endl;
	}
}

void SqList::PushPront(elemtype value) //ͷ��
{
	IncreaseSize();
	for (int i = this->length; i > 0; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[0] = value;
	this->length++;
}

void SqList::PushBack(elemtype value)	//β��
{
	IncreaseSize();
	this->data[this->length] = value;
	this->length++;

}
void SqList::PopPront()	//ͷɾ
{
	IncreaseSize();
	for (int i = 0; i < this->length - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->length--;
}

void SqList::PopBack()	//βɾ
{
	if (0 == this->length)
	{
		cout << "��ǰ˳���Ϊ�գ��޷�ɾ����" << endl;
	}
	else
	{
		this->length--;
	}
}

void SqList::SortList() //����
{
	for (int i = 0; i < this->length - 1; i++)
	{
		for (int j = 0; j < this->length - i - 1; j++)
		{
			if (this->data[j] > this->data[j + 1])
			{
				int tmp = this->data[j + 1];
				this->data[j + 1] = this->data[j];
				this->data[j] = tmp;
			}
		}
	}
}
void SqList::ClearList() //���
{
	this->length = 0;
}

void SqList::ShowCapacityLength()
{
	cout << "��ǰ˳��������Ϊ��" << this->capacity << endl;
	cout << "��ǰ˳���ĳ���Ϊ��" << this->length << endl;
}