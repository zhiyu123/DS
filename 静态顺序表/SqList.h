#ifndef __SQLIST_H__
#define __SQLIST_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXSIZE 5
typedef int elemtype;

typedef struct SqList
{
	elemtype data[MAXSIZE];          //顺序表静态数组
	int length;						//当前顺序表的元素数量
}SqList;

void InitList(SqList* L);   //初始化顺序表
void PrintList(SqList* L);  //打印顺序表
void PushPront(SqList* L, elemtype value);  //头插
void PushBack(SqList* L, elemtype value);	//尾插
void PopPront(SqList* L);	//头删
void PopBack(SqList* L);	//尾删
void InsertElem(SqList* L, int pos, elemtype value);	//任意位置插入
void DeleteElem(SqList* L, int pos);		//任意位置删除
void LocateElem(SqList* L, elemtype value);  //查询某元素的位置
void SortList(SqList* L); //排序
void ClearList(SqList* L); //清空

#endif//__SQLIST_H__