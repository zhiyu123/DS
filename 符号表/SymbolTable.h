#include"Node.h"

class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();
	void Put(elemtype_key key, elemtype_value value);		//�����ֵ�ԣ����keyԭ���У������value
	void Get(elemtype_key key);			//���ݼ�ֵ��value
	void Delete(elemtype_key key);		//ɾ��key�ļ�ֵ��
	void Length();			//�󳤶�
	void Print();			//��ӡ���м�ֵ��
private:
	int m_length;			//����
	Node* head;			//ͷָ��
};