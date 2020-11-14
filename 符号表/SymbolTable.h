#include"Node.h"

class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();
	void Put(elemtype_key key, elemtype_value value);		//插入键值对，如果key原来有，则更新value
	void Get(elemtype_key key);			//根据键值找value
	void Delete(elemtype_key key);		//删除key的键值对
	void Length();			//求长度
	void Print();			//打印所有键值对
private:
	int m_length;			//长度
	Node* head;			//头指针
};