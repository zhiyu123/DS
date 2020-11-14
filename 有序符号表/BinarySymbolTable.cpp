#include"BinarySymbolTable.h"

BinarySymbolTable::BinarySymbolTable()
{
	this->m_length = 0;
	this->m_capacity = INITSIZE;
	this->m_key = new int[INITSIZE];
	this->m_value = new int[INITSIZE];
	for (int i = 0; i < INITSIZE; i++)		//数组都初始化为0
	{
		m_key[i] = 0;
		m_value[i] = 0;
	}
	cout << "初始化完成，请操作！" << endl;
}

BinarySymbolTable::~BinarySymbolTable()
{
	delete m_key;
	m_key = NULL;
	delete m_value;
	m_value = NULL;
}

void BinarySymbolTable::Check()
{
	if (this->m_length >= this->m_capacity)
	{
		int* p_tmp_key = new int[INITSIZE + this->m_length];		//每次扩容5个单位，key
		int* p_tmp_value = new int[INITSIZE + this->m_length];	//value
		for (int i = 0; i < this->m_length; i++)
		{
			p_tmp_key[i] = this->m_key[i];
			p_tmp_value[i] = this->m_key[i];
		}
		this->m_capacity += INITSIZE;		//容量每次增加INITSIZE
		int* tmp_key = this->m_key;			//交换两个空间
		this->m_key = p_tmp_key;
		p_tmp_key = tmp_key;
		delete []p_tmp_key;			//删除空间
		p_tmp_key = NULL;

		int* tmp_value = this->m_value;			//交换两个空间
		this->m_value = p_tmp_value;
		p_tmp_value = tmp_value;
		delete []p_tmp_value;			//删除空间
		p_tmp_value = NULL;
	}
}

void BinarySymbolTable::Put(int key, int value)		//插入键值对，如果key原来有，则更新value
{
	Check();
	for (int i = 0; i < this->m_length; i++)
	{
		if (m_key[i] == key)
		{
			m_value[i] = value;
			cout << "该键已存在，不能重复插入，已更新其值！" << endl;
			return;
		}
	}
	//跳出循环即是没有找到匹配的key，所以要插入一个新的键值对
	for (int i = 0; i < m_length; i++)				//遍历整个数组
	{
		if (key < this->m_key[i])						//要插入的key和当前数组中所有的key比较
		{
			for (int j = m_length - 1; j >= i; j--)		//将key插入到数组中第一个大于他的已有key之前
			{											//所以将他后面的所有key和value一次后移一个单位
				m_key[j + 1] = m_key[j];
				m_value[j + 1] = m_value[j];
			}
			this->m_key[i] = key;					//插入新的key和value
			this->m_value[i] = value;
			this->m_length++;
			return;
		}
	}
	//如果出循环体意味着当前数组中没有比要插入的key还大的key，那就把新的key插入到最后，即m_length处
	this->m_key[m_length] = key;
	this->m_value[m_length] = value;
	this->m_length++;
}

bool BinarySymbolTable::BinarySearch(int* arr, int k, int left, int right)//二分查找
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return false;
}

void BinarySymbolTable::Get(int key)			//根据键值找value,通过二分查找
{
	bool ret = BinarySearch(this->m_key, key, 0, m_length - 1);
	if (ret == false)
	{
		cout << "没有找到该键对应的键值对" << endl;
	}
	else
	{
		cout << "已找到该键所对应的值：" << '\t' << "key:" << this->m_key[ret]
			 << '\t' << "value:" << this->m_value[ret] << endl;
		return;
	}
}
  
void BinarySymbolTable::Delete(int key)		//删除key的键值对
{
	for(int i = 0; i < this->m_length; i++)
	{
		if (m_key[i] == key)
		{
			for (int j = i; j < this->m_length - 1; j++)
			{
				m_key[j] = m_key[j + 1];
				m_value[j] = m_value[j + 1];
			}
			cout << "已删除key为" << key << "的键值对" << endl;
			this->m_length--;
			return;
		}
	}
	cout << "没有找到该键对应的键值对!" << endl;	
}

void BinarySymbolTable::Length()			//求长度
{
	cout << "当前键值对的长度为:" << this->m_length << endl;
	cout << "当前键值对的容量为:" << this->m_capacity << endl;
}

void BinarySymbolTable::Print()			//打印所有键值对
{
	if (this->m_length == 0)
	{
		cout << "当前键值对为空！" << endl;
	}
	else
	{
		for(int i = 0; i < this->m_length; i++)
		{
			cout << "键值对：" << "key：" << this->m_key[i] << '\t' 
				 << "value：" << this->m_value[i] << '\t' << endl;
		}
	}
}