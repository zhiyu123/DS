#pragma once

#include<iostream>
using namespace std;

#define CAPACITY 100			//��������
typedef int elemtype;

class Heap
{
public:
	Heap();
	~Heap();
	void Insert(elemtype e);	//�������в���һ��Ԫ��
	elemtype DelMax();			//ɾ����������Ԫ�أ������ڵ�,������ɾ����Ԫ��
	void Swim(int k);			//ʹ���ϸ��㷨��������k����Ԫ���ڶ��д���һ����ȷ��λ��
	void Skin(int k);			//ʹ���³��㷨��������k����Ԫ���ڶ��д���һ����ȷ��λ��
public:
	int count;				//��¼���е�Ԫ�ظ���
	elemtype* data;			//�洢���е�Ԫ��
};