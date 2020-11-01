#include"SqList.h"

SqList::SqList():capacity(INITSIZE),length(0)	//构造函数,初始化容量为5，长度为0
{
	this->data = new elemtype[INITSIZE];
	if (data == NULL)
	{
		cout << "申请内存失败！" << endl;
	}
	else
	{
		cout << "内存分配成功,初始化完成,请执行下面操作！" << endl;
		cout << endl;
	}
}

SqList::~SqList()	//析构函数
{
	if (this->data != NULL)
	{
		delete []data;
		data = NULL;
		this->length = 0;
		this->capacity = INITSIZE;
	}
}

void SqList::IncreaseSize()    //延长顺序表
{
	if (this->capacity <= this->length)   //容量小于长度 要扩容
	{
		elemtype* p_tmp = new elemtype[this->length + INITSIZE];  //每次扩容5个单位的大小
		for (int i = 0; i < this->length; i++)
		{
			p_tmp[i] = this->data[i];
		}
		this->capacity += INITSIZE;
		elemtype* tmp = this->data;
		this->data = p_tmp;
		p_tmp = tmp;
		delete []p_tmp;				//释放原来的内存
		p_tmp = NULL;
	}
}

void SqList::InsertElem(int pos, elemtype value)	//任意位置插入
{
	IncreaseSize();
	if (pos <= 0 || pos > (this->length + 1)) //不能隔空插入
	{
		cout << "插入位置非法,无法插入!" << endl;
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

void SqList::DeleteElem(int pos)	//任意位置删除
{
	if (0 == this->length)
	{
		cout << "当前顺序表为空，无法删除！" << endl;
	}
	else if (pos <= 0 || pos > (this->length))
	{
		cout << "删除位置非法,无法删除！" << endl;
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

void SqList::LocateElem(elemtype value) //查询某元素的位置
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->data[i] == value)
		{
			cout << "要查询的元素位置为：" << i + 1 << endl;
			return;
		}
	}
	cout << "该元素不存在！" << endl;
}

void SqList::PrintList()    //打印顺序表
{
	if (0 == this->length)
	{
		cout << "当前顺序表中元素为空！" << endl;
	}
	else
	{
		cout << "当前顺序表中的元素为：";
		for (int i = 0; i < this->length; i++)
		{
			cout << "\t" << this->data[i] << "\t"; 
		}
		cout << endl;
	}
}

void SqList::PushPront(elemtype value) //头插
{
	IncreaseSize();
	for (int i = this->length; i > 0; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[0] = value;
	this->length++;
}

void SqList::PushBack(elemtype value)	//尾插
{
	IncreaseSize();
	this->data[this->length] = value;
	this->length++;

}
void SqList::PopPront()	//头删
{
	IncreaseSize();
	for (int i = 0; i < this->length - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->length--;
}

void SqList::PopBack()	//尾删
{
	if (0 == this->length)
	{
		cout << "当前顺序表为空，无法删除！" << endl;
	}
	else
	{
		this->length--;
	}
}

void SqList::SortList() //排序
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
void SqList::ClearList() //清空
{
	this->length = 0;
}

void SqList::ShowCapacityLength()
{
	cout << "当前顺序表的容量为：" << this->capacity << endl;
	cout << "当前顺序表的长度为：" << this->length << endl;
}