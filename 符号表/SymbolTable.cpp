#include"SymbolTable.h"

SymbolTable::SymbolTable()
{
	this->head = new Node;
	head->m_key = 0;
	head->m_value = 0;
	head->next = NULL;
	this->m_length = 0;
	cout << "初始化完成，请操作！" << endl;
}

SymbolTable::~SymbolTable()
{
	delete head;
	head = NULL;
}

void SymbolTable::Put(elemtype_key key, elemtype_value value)		//插入键值对，如果key原来有，则更新value
{
	Node* p_tmp = head;			//保存头指针
	while (head->next != NULL)
	{
		head = head->next;
		if (head->m_key == key)
		{
			head->m_value = value;
			cout << "该键已存在，不能重复插入，已更新其值！" << endl;
			head = p_tmp;			//恢复头指针
			return;				//修改和恢复头指针之后返回
		}
	}
	//跳出循环即是没有找到匹配的key，所以要new一个Node来存放键值对，在链表头
	head = p_tmp;				//恢复头指针
	Node* tmp = new Node;
	tmp->m_key = key;
	tmp->m_value = value;
	tmp->next = head->next;
	head->next = tmp;
	this->m_length++;
}

void SymbolTable::Get(elemtype_key key)			//根据键值找value
{
	Node* p_tmp = head;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->m_key == key)
		{
			cout << "已找到该键所对应的值：" << '\t' << "key:" << head->m_key 
				 << '\t' << "value:" << head->m_value << endl;
			head = p_tmp;		//恢复头指针
			return;
		}
	}
	cout << "没有找到该键对应的键值对" << endl;
	head = p_tmp;		//恢复头指针
}

void SymbolTable::Delete(elemtype_key key)		//删除key的键值对
{
	Node* p_tmp = head;
	while (head->next != NULL)
	{
		if (head->next->m_key == key)
		{
			head->next = head->next->next;
			cout << "已删除key为" << key << "的键值对" << endl;
			head = p_tmp;		//恢复头指针
			this->m_length--;
			return;
		}
		head = head->next;
	}
	cout << "没有找到该键对应的键值对!" << endl;
	head = p_tmp;		//恢复头指针	
}
void SymbolTable::Length()			//求长度
{
	cout << "当前键值对的长度为:" << this->m_length << endl;
}

void SymbolTable::Print()			//打印所有键值对
{
	if (this->m_length == 0)
	{
		cout << "当前键值对为空！" << endl;
	}
	else
	{
		Node* p_tmp = head;
		while (head->next != NULL)
		{
			head = head->next;
			cout << "键值对：" << "key：" << head->m_key << '\t' << "value：" << head->m_value << '\t' << endl;
		}
		head = p_tmp;
	}
}