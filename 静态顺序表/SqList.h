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
	elemtype data[MAXSIZE];          //˳���̬����
	int length;						//��ǰ˳����Ԫ������
}SqList;

void InitList(SqList* L);   //��ʼ��˳���
void PrintList(SqList* L);  //��ӡ˳���
void PushPront(SqList* L, elemtype value);  //ͷ��
void PushBack(SqList* L, elemtype value);	//β��
void PopPront(SqList* L);	//ͷɾ
void PopBack(SqList* L);	//βɾ
void InsertElem(SqList* L, int pos, elemtype value);	//����λ�ò���
void DeleteElem(SqList* L, int pos);		//����λ��ɾ��
void LocateElem(SqList* L, elemtype value);  //��ѯĳԪ�ص�λ��
void SortList(SqList* L); //����
void ClearList(SqList* L); //���

#endif//__SQLIST_H__