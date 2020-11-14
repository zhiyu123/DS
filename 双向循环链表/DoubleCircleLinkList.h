#ifndef __DOUBLE_CIRCLE_LINKLIST_H__
#define __DOUBLE_CIRCLE_LINKLIST_H__

#include"Node.h"

class DoubleCircleLinkList
{
public:
	DoubleCircleLinkList();			//构造函数初始化链表
	~DoubleCircleLinkList();		//析构函数销毁链表
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
	void RPrintLinkList();	//逆序打印链表
private:
	Node* head;		//头指针   指向头节点
	int length;		//链表当前长度
};

#endif//__DOUBLE_CIRCLE_LINKLIST_H__