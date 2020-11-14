#include<iostream>
using namespace std;

typedef int elemtype;
#define CAPACITY 100

class MinPriorityQueue
{
public:
	MinPriorityQueue();						//���캯��
	~MinPriorityQueue();					//��������
	bool IsLess(int i, int j);				//�ж϶�������i����Ԫ���Ƿ�С������j����Ԫ��
	void Swap(int i, int j);				//��������i��j����Ԫ��
	elemtype DelMin();						//ɾ����������С��Ԫ�أ������������СԪ��
	void Insert(elemtype e);				//����һ��Ԫ��
	void Swim(int k);						//ʹ���ϸ��㷨��ʹ����k����Ԫ�ز���ĺ��ʵ�λ��
	void Sink(int k);						//ʹ���³��㷨��ʹ����k����Ԫ�ز��뵽���ʵ�λ��
	int Size();								//��ȡ������Ԫ�صĸ���
	bool Empty();							//�ж϶����Ƿ�Ϊ��
public:
	elemtype* data;						//�洢Ԫ�ص�����
	int count;								//������Ԫ�صĸ���
};