#include"PTNode.h"

class PTree
{
public:
	PTree();
	void AddNode(elemtype data, int partent);//���ӽ��
	PTNode node[MAXSIZE];		//�ڵ�����
	int root_pos;		//����λ��
	int node_num;		//�������
};	
