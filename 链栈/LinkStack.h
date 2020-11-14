#include"Node.h"

class LinkStack
{
public:
	LinkStack();			//构造函数初始化栈
	~LinkStack();			//析构函数
	void Pop();			//出栈
	void Push(elemtype e);		//入栈
	void PrintStack();		//打印栈
	void LengthStack();		//求长度
	void TopStack();		//求栈顶元素
private:
	Node* head;		//头指针
	Node* tail;		//尾指针
	int length;		//长度
};