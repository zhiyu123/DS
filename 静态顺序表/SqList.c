#include"SqList.h"

void InitList(SqList* L)   //初始化顺序表
{
	assert(L);	//断言
	memset(L->data, 0, sizeof(L->data));    //初始化数组
	L->length = 0;
	printf("初始化完成！\n");
}

void PrintList(SqList* L)  //打印顺序表
{
	assert(L);
	if (0 == L->length)
	{
		printf("当前顺序表中元素为空！\n");
	}
	else
	{
		printf("当前顺序表中的元素为：");
		for (int i = 0; i < L->length; i++)
		{
			printf("\t%d\t", L->data[i]);
		}
		printf("\n");
	}
}

void PushPront(SqList* L, elemtype value)  //头插
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("当前顺序表已满，无法插入！\n");
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

void PushBack(SqList* L, elemtype value)	//尾插
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("当前顺序表已满，无法插入！\n");
	}
	else
	{
		L->data[L->length] = value;
		L->length++;
	}
}

void PopPront(SqList* L)	//头删
{
	assert(L);
	if (0 == L->length)
	{
		printf("当前顺序表为空，无法删除！\n");
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

void PopBack(SqList* L)	//尾删
{
	assert(L);
	if (0 == L->length)
	{
		printf("当前顺序表为空，无法删除！\n");
	}
	else
	{
		L->length--;
	}
}
void InsertElem(SqList* L, int pos, elemtype value)	//任意位置插入
{
	assert(L);
	if (MAXSIZE == L->length)
	{
		printf("当前顺序表已满，无法插入！\n");
	}
	else if (pos <= 0 || pos > (L->length + 1)) //不能隔空插入
	{
		printf("插入位置非法,无法插入！\n");
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

void DeleteElem(SqList* L, int pos)		//任意位置删除
{
	assert(L);
	if (0 == L->length)
	{
		printf("当前顺序表为空，无法删除！\n");
	}
	else if (pos <= 0 || pos > (L->length))
	{
		printf("删除位置非法,无法删除！\n");
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

void LocateElem(SqList* L, elemtype value)  //查询某元素的位置
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == value)
		{
			printf("要查询的元素位置为：%d\n", i + 1);
			return;
		}
	}
	printf("该元素不存在！\n");
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