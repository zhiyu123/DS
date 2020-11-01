#ifndef __SQLIST_H__
#define __SQLIST_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

#define INITSIZE 5            //初始长度为5
typedef int elemtype;

class SqList
{
public:
	SqList();	//构造函数
	~SqList();	//析构函数
	void IncreaseSize();    //延长顺序表
	void InsertElem(int pos, elemtype value);	//任意位置插入
	void DeleteElem(int pos);		//任意位置删除
	void LocateElem(elemtype value);  //查询某元素的位置
	void PrintList();     //打印顺序表
	void PushPront(elemtype value);  //头插
	void PushBack(elemtype value);	//尾插
	void PopPront();	//头删
	void PopBack();	//尾删
	void SortList(); //排序
	void ClearList(); //清空
	void ShowCapacityLength();
private:
	elemtype* data;		//指向动态分配数组的指针
	int length;		//当前数组长度
	int capacity;   //当前数组容量
};

#endif//__SQLIST_H__