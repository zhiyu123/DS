#ifndef __CIRCLELINKLIST_H__
#define __CIRCLELINKLIST_H__

#include"Node.h"

class CircleLinkList
{
public:
	CircleLinkList();			//构造函数初始化链表
	~CircleLinkList();		//析构函数销毁链表
	void ClearLinkList();		//清空链表
	void PushFront(elemtype value);	//头插
	void PushBack(elemtype value);	//尾插
	void PopFront();			//头删
	void PopBack();			//尾删
	void InsertLinkList(int pos, elemtype value); //在第pos位置插入元素value
	void DeleteLinkList(int pos); //删除第pos个位置的元素
	void PrintLinkList();//打印链表
	void Length();		//查看长度
	void SearchLinkList(elemtype value);	//查找value的位置
private:
	Node* head;		//头指针   指向头节点
	int length;		//链表当前长度
};

#endif//_CIRCLELINKLIST_H__