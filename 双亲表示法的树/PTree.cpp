#include"PTree.h"

PTree::PTree()
{
	this->root_pos = 0;
	this->node_num = 0;
}

void PTree::AddNode(elemtype data, int partent)
{
	node[this->node_num].m_data = data;
	node[this->node_num].m_parent = partent;
	this->node_num++;
}
