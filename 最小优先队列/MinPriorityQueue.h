#include<iostream>
using namespace std;

typedef int elemtype;
#define CAPACITY 100

class MinPriorityQueue
{
public:
	MinPriorityQueue();						//构造函数
	~MinPriorityQueue();					//析构函数
	bool IsLess(int i, int j);				//判断堆中索引i处的元素是否小于索引j处的元素
	void Swap(int i, int j);				//交换索引i和j处的元素
	elemtype DelMin();						//删除队列中最小的元素，并返回这个最小元素
	void Insert(elemtype e);				//插入一个元素
	void Swim(int k);						//使用上浮算法，使索引k处的元素插入的合适的位置
	void Sink(int k);						//使用下沉算法，使索引k处的元素插入到合适的位置
	int Size();								//获取队列中元素的个数
	bool Empty();							//判断队列是否为空
public:
	elemtype* data;						//存储元素的数组
	int count;								//队列中元素的个数
};