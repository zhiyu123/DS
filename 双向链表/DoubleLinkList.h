#ifndef __DOUBLELINKLIST_H__
#define __DOUBLELINKLIST_H__

#include"Node.h"

class DoubleLinkList
{
public:
	DoubleLinkList();			//���캯����ʼ������
	~DoubleLinkList();		//����������������
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
	void RPrintLinkList();			//�����ӡ����
private:
	Node* head;		//ͷָ��   ָ��ͷ�ڵ�
	int length;		//����ǰ����
};

#endif//__DOUBLELINKLIST_H__