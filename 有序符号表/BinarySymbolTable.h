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
	void Put(int key, int value);		//�����ֵ�ԣ����keyԭ���У������value
	void Get(int key);			//���ݼ�ֵ��value
	void Delete(int key);		//ɾ��key�ļ�ֵ��
	void Length();			//�󳤶�
	void Print();			//��ӡ���м�ֵ��
	void Check();			//�����������
	bool BinarySearch(int* arr, int k, int left, int right);	//���ֲ����㷨
private:
	int m_length;			//����
	int m_capacity;			//��������
	int* m_key;				//key����	
	int* m_value;  			//value����
};

#endif//__BinarySymbolTable_h__