#ifndef __SQLIST_H__
#define __SQLIST_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

#define INITSIZE 5            //��ʼ����Ϊ5
typedef int elemtype;

class SqList
{
public:
	SqList();	//���캯��
	~SqList();	//��������
	void IncreaseSize();    //�ӳ�˳���
	void InsertElem(int pos, elemtype value);	//����λ�ò���
	void DeleteElem(int pos);		//����λ��ɾ��
	void LocateElem(elemtype value);  //��ѯĳԪ�ص�λ��
	void PrintList();     //��ӡ˳���
	void PushPront(elemtype value);  //ͷ��
	void PushBack(elemtype value);	//β��
	void PopPront();	//ͷɾ
	void PopBack();	//βɾ
	void SortList(); //����
	void ClearList(); //���
	void ShowCapacityLength();
private:
	elemtype* data;		//ָ��̬���������ָ��
	int length;		//��ǰ���鳤��
	int capacity;   //��ǰ��������
};

#endif//__SQLIST_H__