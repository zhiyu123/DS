#include"SymbolTable.h"

SymbolTable::SymbolTable()
{
	this->head = new Node;
	head->m_key = 0;
	head->m_value = 0;
	head->next = NULL;
	this->m_length = 0;
	cout << "��ʼ����ɣ��������" << endl;
}

SymbolTable::~SymbolTable()
{
	delete head;
	head = NULL;
}

void SymbolTable::Put(elemtype_key key, elemtype_value value)		//�����ֵ�ԣ����keyԭ���У������value
{
	Node* p_tmp = head;			//����ͷָ��
	while (head->next != NULL)
	{
		head = head->next;
		if (head->m_key == key)
		{
			head->m_value = value;
			cout << "�ü��Ѵ��ڣ������ظ����룬�Ѹ�����ֵ��" << endl;
			head = p_tmp;			//�ָ�ͷָ��
			return;				//�޸ĺͻָ�ͷָ��֮�󷵻�
		}
	}
	//����ѭ������û���ҵ�ƥ���key������Ҫnewһ��Node����ż�ֵ�ԣ�������ͷ
	head = p_tmp;				//�ָ�ͷָ��
	Node* tmp = new Node;
	tmp->m_key = key;
	tmp->m_value = value;
	tmp->next = head->next;
	head->next = tmp;
	this->m_length++;
}

void SymbolTable::Get(elemtype_key key)			//���ݼ�ֵ��value
{
	Node* p_tmp = head;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->m_key == key)
		{
			cout << "���ҵ��ü�����Ӧ��ֵ��" << '\t' << "key:" << head->m_key 
				 << '\t' << "value:" << head->m_value << endl;
			head = p_tmp;		//�ָ�ͷָ��
			return;
		}
	}
	cout << "û���ҵ��ü���Ӧ�ļ�ֵ��" << endl;
	head = p_tmp;		//�ָ�ͷָ��
}

void SymbolTable::Delete(elemtype_key key)		//ɾ��key�ļ�ֵ��
{
	Node* p_tmp = head;
	while (head->next != NULL)
	{
		if (head->next->m_key == key)
		{
			head->next = head->next->next;
			cout << "��ɾ��keyΪ" << key << "�ļ�ֵ��" << endl;
			head = p_tmp;		//�ָ�ͷָ��
			this->m_length--;
			return;
		}
		head = head->next;
	}
	cout << "û���ҵ��ü���Ӧ�ļ�ֵ��!" << endl;
	head = p_tmp;		//�ָ�ͷָ��	
}
void SymbolTable::Length()			//�󳤶�
{
	cout << "��ǰ��ֵ�Եĳ���Ϊ:" << this->m_length << endl;
}

void SymbolTable::Print()			//��ӡ���м�ֵ��
{
	if (this->m_length == 0)
	{
		cout << "��ǰ��ֵ��Ϊ�գ�" << endl;
	}
	else
	{
		Node* p_tmp = head;
		while (head->next != NULL)
		{
			head = head->next;
			cout << "��ֵ�ԣ�" << "key��" << head->m_key << '\t' << "value��" << head->m_value << '\t' << endl;
		}
		head = p_tmp;
	}
}