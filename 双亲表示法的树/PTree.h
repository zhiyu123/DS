#include"PTNode.h"

class PTree
{
public:
	PTree();
	void AddNode(elemtype data, int partent);//增加结点
	PTNode node[MAXSIZE];		//节点数组
	int root_pos;		//根的位置
	int node_num;		//结点数量
};	
