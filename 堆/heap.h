#pragma once

#include<iostream>
using namespace std;

#define CAPACITY 100			//数组容量
typedef int elemtype;

class Heap
{
public:
	Heap();
	~Heap();
	void Insert(elemtype e);	//往数组中插入一个元素
	elemtype DelMax();			//删除堆中最大的元素，即根节点,并返回删除的元素
	void Swim(int k);			//使用上浮算法，将索引k处的元素在堆中处于一个正确的位置
	void Skin(int k);			//使用下沉算法，将索引k处的元素在堆中处于一个正确的位置
public:
	int count;				//记录堆中的元素个数
	elemtype* data;			//存储堆中的元素
};