#include<iostream>
using namespace std;

typedef int elemtype;

#define CAPACITY 100

class MaxPriorityQueue
{
public:
	MaxPriorityQueue();						//���캯��
	~MaxPriorityQueue();					//��������
	bool IsLess(int i, int j);				//�ж϶�������i����Ԫ���Ƿ�С������j����Ԫ��
	void Swap(int i, int j);				//��������i��j����Ԫ��
	elemtype DelMax();						//ɾ������������Ԫ�أ�������������Ԫ��
	void Insert(elemtype e);				//����һ��Ԫ��
	void Swim(int k);						//ʹ���ϸ��㷨��ʹ����k����Ԫ�ز���ĺ��ʵ�λ��
	void Sink(int k);						//ʹ���³��㷨��ʹ����k����Ԫ�ز��뵽���ʵ�λ��
	int Size();								//��ȡ������Ԫ�صĸ���
	bool Empty();							//�ж϶����Ƿ�Ϊ��
public:
	elemtype* data;						//�洢Ԫ�ص�����
	int count;								//������Ԫ�صĸ���
};