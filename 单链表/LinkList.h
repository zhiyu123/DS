#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include"Node.h"

class LinkList
{
public:
	LinkList();			//���캯����ʼ������
	~LinkList();		//����������������
	void ClearLinkList();		//�������
	void PushFront(elemtype value);	//ͷ��
	void PushBack(elemtype value);	//β��
	void PopFront();			//ͷɾ
	void PopBack();			//βɾ
	void InsertLinkList(int pos, elemtype value); //�ڵ�posλ�ò���Ԫ��value
	void DeleteLinkList(int pos); //ɾ����pos��λ�õ�Ԫ��
	void PrintLinkList();//��ӡ����
	void Length();		//�鿴����
	void SearchLinkList(elemtype value);	//����value��λ��
private:
	Node* head;		//ͷָ��   ָ��ͷ�ڵ�
	int length;		//����ǰ����
};

#endif//_LINKLIST_H__