#include"Node.h"

class LinkStack
{
public:
	LinkStack();			//���캯����ʼ��ջ
	~LinkStack();			//��������
	void Pop();			//��ջ
	void Push(elemtype e);		//��ջ
	void PrintStack();		//��ӡջ
	void LengthStack();		//�󳤶�
	void TopStack();		//��ջ��Ԫ��
private:
	Node* head;		//ͷָ��
	Node* tail;		//βָ��
	int length;		//����
};