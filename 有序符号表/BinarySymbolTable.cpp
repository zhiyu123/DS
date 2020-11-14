#include"BinarySymbolTable.h"

BinarySymbolTable::BinarySymbolTable()
{
	this->m_length = 0;
	this->m_capacity = INITSIZE;
	this->m_key = new int[INITSIZE];
	this->m_value = new int[INITSIZE];
	for (int i = 0; i < INITSIZE; i++)		//���鶼��ʼ��Ϊ0
	{
		m_key[i] = 0;
		m_value[i] = 0;
	}
	cout << "��ʼ����ɣ��������" << endl;
}

BinarySymbolTable::~BinarySymbolTable()
{
	delete m_key;
	m_key = NULL;
	delete m_value;
	m_value = NULL;
}

void BinarySymbolTable::Check()
{
	if (this->m_length >= this->m_capacity)
	{
		int* p_tmp_key = new int[INITSIZE + this->m_length];		//ÿ������5����λ��key
		int* p_tmp_value = new int[INITSIZE + this->m_length];	//value
		for (int i = 0; i < this->m_length; i++)
		{
			p_tmp_key[i] = this->m_key[i];
			p_tmp_value[i] = this->m_key[i];
		}
		this->m_capacity += INITSIZE;		//����ÿ������INITSIZE
		int* tmp_key = this->m_key;			//���������ռ�
		this->m_key = p_tmp_key;
		p_tmp_key = tmp_key;
		delete []p_tmp_key;			//ɾ���ռ�
		p_tmp_key = NULL;

		int* tmp_value = this->m_value;			//���������ռ�
		this->m_value = p_tmp_value;
		p_tmp_value = tmp_value;
		delete []p_tmp_value;			//ɾ���ռ�
		p_tmp_value = NULL;
	}
}

void BinarySymbolTable::Put(int key, int value)		//�����ֵ�ԣ����keyԭ���У������value
{
	Check();
	for (int i = 0; i < this->m_length; i++)
	{
		if (m_key[i] == key)
		{
			m_value[i] = value;
			cout << "�ü��Ѵ��ڣ������ظ����룬�Ѹ�����ֵ��" << endl;
			return;
		}
	}
	//����ѭ������û���ҵ�ƥ���key������Ҫ����һ���µļ�ֵ��
	for (int i = 0; i < m_length; i++)				//������������
	{
		if (key < this->m_key[i])						//Ҫ�����key�͵�ǰ���������е�key�Ƚ�
		{
			for (int j = m_length - 1; j >= i; j--)		//��key���뵽�����е�һ��������������key֮ǰ
			{											//���Խ������������key��valueһ�κ���һ����λ
				m_key[j + 1] = m_key[j];
				m_value[j + 1] = m_value[j];
			}
			this->m_key[i] = key;					//�����µ�key��value
			this->m_value[i] = value;
			this->m_length++;
			return;
		}
	}
	//�����ѭ������ζ�ŵ�ǰ������û�б�Ҫ�����key�����key���ǾͰ��µ�key���뵽��󣬼�m_length��
	this->m_key[m_length] = key;
	this->m_value[m_length] = value;
	this->m_length++;
}

bool BinarySymbolTable::BinarySearch(int* arr, int k, int left, int right)//���ֲ���
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return false;
}

void BinarySymbolTable::Get(int key)			//���ݼ�ֵ��value,ͨ�����ֲ���
{
	bool ret = BinarySearch(this->m_key, key, 0, m_length - 1);
	if (ret == false)
	{
		cout << "û���ҵ��ü���Ӧ�ļ�ֵ��" << endl;
	}
	else
	{
		cout << "���ҵ��ü�����Ӧ��ֵ��" << '\t' << "key:" << this->m_key[ret]
			 << '\t' << "value:" << this->m_value[ret] << endl;
		return;
	}
}
  
void BinarySymbolTable::Delete(int key)		//ɾ��key�ļ�ֵ��
{
	for(int i = 0; i < this->m_length; i++)
	{
		if (m_key[i] == key)
		{
			for (int j = i; j < this->m_length - 1; j++)
			{
				m_key[j] = m_key[j + 1];
				m_value[j] = m_value[j + 1];
			}
			cout << "��ɾ��keyΪ" << key << "�ļ�ֵ��" << endl;
			this->m_length--;
			return;
		}
	}
	cout << "û���ҵ��ü���Ӧ�ļ�ֵ��!" << endl;	
}

void BinarySymbolTable::Length()			//�󳤶�
{
	cout << "��ǰ��ֵ�Եĳ���Ϊ:" << this->m_length << endl;
	cout << "��ǰ��ֵ�Ե�����Ϊ:" << this->m_capacity << endl;
}

void BinarySymbolTable::Print()			//��ӡ���м�ֵ��
{
	if (this->m_length == 0)
	{
		cout << "��ǰ��ֵ��Ϊ�գ�" << endl;
	}
	else
	{
		for(int i = 0; i < this->m_length; i++)
		{
			cout << "��ֵ�ԣ�" << "key��" << this->m_key[i] << '\t' 
				 << "value��" << this->m_value[i] << '\t' << endl;
		}
	}
}