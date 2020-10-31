#include"SqList.h"

void InitList(SqList* L)   //��ʼ��˳���
{
	assert(L);	//����
	memset(L->data, 0, sizeof(L->data));    //��ʼ������
	L->length = 0;
	printf("��ʼ����ɣ�\n");
}

void PrintList(SqList* L)  //��ӡ˳���
{
	assert(L);
	if (0 == L->length)
	{
		printf("��ǰ˳�����Ԫ��Ϊ�գ�\n");
	}
	else
	{
		printf("��ǰ˳����е�Ԫ��Ϊ��");
		for (int i = 0; i < L->length; i++)
		{
			printf("\t%d\t", L->data[i]);
		}
		printf("\n");
	}
}

void PushPront(SqList* L, elemtype value)  //ͷ��
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("��ǰ˳����������޷����룡\n");
	}
	else
	{
		for (int i = L->length; i > 0; i--)
		{
			L->data[i] = L->data[i - 1];
		}
		L->data[0] = value;
		L->length++;
	}
}

void PushBack(SqList* L, elemtype value)	//β��
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("��ǰ˳����������޷����룡\n");
	}
	else
	{
		L->data[L->length] = value;
		L->length++;
	}
}

void PopPront(SqList* L)	//ͷɾ
{
	assert(L);
	if (0 == L->length)
	{
		printf("��ǰ˳���Ϊ�գ��޷�ɾ����\n");
	}
	else
	{
		for (int i = 0; i < L->length - 1; i++)
		{
			L->data[i] = L->data[i + 1];
		}
		L->length--;
	}
}

void PopBack(SqList* L)	//βɾ
{
	assert(L);
	if (0 == L->length)
	{
		printf("��ǰ˳���Ϊ�գ��޷�ɾ����\n");
	}
	else
	{
		L->length--;
	}
}
void InsertElem(SqList* L, int pos, elemtype value)	//����λ�ò���
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("��ǰ˳����������޷����룡\n");
	}
	else if (pos <= 0 || pos > (L->length + 1)) //���ܸ��ղ���
	{
		printf("����λ�÷Ƿ�,�޷����룡\n");
	}         
	else      
	{
		for (int i = L->length - 1; i >= pos - 1; i--)
		{
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = value;
		L->length++;
	}
}

void DeleteElem(SqList* L, int pos)		//����λ��ɾ��
{
	assert(L);
	if (0 == L->length)
	{
		printf("��ǰ˳���Ϊ�գ��޷�ɾ����\n");
	}
	else if (pos <= 0 || pos > (L->length))
	{
		printf("ɾ��λ�÷Ƿ�,�޷�ɾ����\n");
	}
	else
	{
		for (int i = pos; i < L->length; i++)
		{
			L->data[i - 1] = L->data[i];
		}
		L->length--;
	}
}

void LocateElem(SqList* L, elemtype value)  //��ѯĳԪ�ص�λ��
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == value)
		{
			printf("Ҫ��ѯ��Ԫ��λ��Ϊ��%d\n", i + 1);
			return;
		}
	}
	printf("��Ԫ�ز����ڣ�\n");
}

void SortList(SqList* L)
{
	for (int i = 0; i < L->length - 1; i++)
	{
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->data[j] > L->data[j + 1])
			{
				int tmp = L->data[j + 1];
				L->data[j + 1] = L->data[j];
				L->data[j] = tmp;
			}
		}
	}
}

void ClearList(SqList* L)
{
	L->length = 0;
}