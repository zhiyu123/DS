#ifndef __BinarySymbolTable_h__
#define __BinarySymbolTable_h__

#include<iostream>
using namespace std;

#define INITSIZE 5

class BinarySymbolTable
{
public:
	BinarySymbolTable();
	~BinarySymbolTable();
	void Put(int key, int value);		//插入键值对，如果key原来有，则更新value
	void Get(int key);			//根据键值找value
	void Delete(int key);		//删除key的键值对
	void Length();			//求长度
	void Print();			//打印所有键值对
	void Check();			//检查数组容量
	bool BinarySearch(int* arr, int k, int left, int right);	//二分查找算法
private:
	int m_length;			//长度
	int m_capacity;			//数组容量
	int* m_key;				//key数组	
	int* m_value;  			//value数组
};

#endif//__BinarySymbolTable_h__