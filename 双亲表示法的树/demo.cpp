#include"PTree.h"

int main()
{
	PTree T;
	T.AddNode('A', -1);		//根节点，双亲为-1
	T.AddNode('B', 0);	
	T.AddNode('C', 0);
	T.AddNode('D', 0);
	T.AddNode('E', 1);
	T.AddNode('F', 1);
	T.AddNode('G', 2);
	T.AddNode('H', 3);
	T.AddNode('I', 3);
	T.AddNode('J', 3);
	for (int i = 0; i < T.node_num; i++)
	{
		cout << T.node[i].m_data << ' ' << T.node[i].m_parent << endl;
	}
	return 0;
}