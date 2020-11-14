#include"graph.h"

ALGraph::ALGraph()		//����һ������v�����㵫�������ߵ�ͼ
{
	this->E = 0;
	this->V = 0;
	this->in_degree = new int[MaxVertexNum]();
	this->AdjList = new VNode[MaxVertexNum];	//����һ����������飬���������洢����
	for (int i = 0; i < MaxVertexNum; i++)		//��ʼ���ڽӱ�
	{
		this->AdjList[i].data = '#';			//��#��ʾ��ǰ���������û�нڵ�
		this->AdjList[i].first = NULL;
	}
}

void ALGraph::GetV()										//���ͼ�ж��������
{
	cout << "��ǰͼ���������Ϊ��" << V << endl;
}

void ALGraph::GetE()									//���ͼ�бߵ�����
{
	cout << "��ǰͼ�ߵ�����Ϊ��" << E << endl;
}

void ALGraph::Print()								//��ӡ
{
	if (this->V == 0)
	{
		cout << "��ǰͼ��û�ж��㣡" << endl;
		return;
	}
	for (int i = 0; i < MaxVertexNum; i++)
	{
		if (AdjList[i].data != '#')
		{
			cout << i << "  " << AdjList[i].data;
			if (AdjList[i].first != NULL)
			{
				cout << "->";
				cout << AdjList[i].first->adjvex;
				ArcNode* p = AdjList[i].first;
				while (p->next != NULL)
				{
					cout << "->";
					cout << p->next->adjvex;
					p = p->next;
				}
			}
			cout << endl;
		}
	}
}

void ALGraph::InsertVertex(elemtype x)					//��ͼ�в��붥��x
{
	if (this->V >= MaxVertexNum)
	{
		cout << "��ǰ������������޷��ٲ��붥�㣡" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < MaxVertexNum; i++)
		{
			if (AdjList[i].data == '#')
			{
				AdjList[i].data = x;
				this->V++;
				cout << "����ɹ���" << endl;
				break;
			}
		}
	}
}

void ALGraph::DeleteVertex(elemtype x)					//��ͼ��ɾ������x
{	
	for (int i = 0; i < MaxVertexNum; i++)			//��Ϊ������ܲ��������ģ�����Ҫ���������������飬������V������
	{
		int count = 0;		//ͳ��ɾ�������м�������
		if (AdjList[i].data == x)
		{
			if (AdjList[i].first != NULL)
			{
				count++;					//++����Ϊ��һ��first���
				ArcNode* pE = AdjList[i].first;
				while (pE->next != NULL)
				{
					count++;
					pE = pE->next;
				}	
			}
			AdjList[i].data = '#';
			AdjList[i].first = NULL;
			this->E = E - count;

			for (int j = 0; j < MaxVertexNum; j++)			//�������ж��㣬��ָ��ɾ������ı߶�Ҫ���
			{
				if (AdjList[j].first == NULL)			//û�����ڵĵ�һ������
				{
					continue;			//������һ��ѭ�����ж���һ������
				}
				else if (AdjList[j].first != NULL)		//�����ڵĵ�һ������
				{
					if (AdjList[j].first->adjvex == i)				//��j���ڵĵ�һ������Ϊi
					{
						AdjList[j].first = AdjList[j].first->next;	//ɾ����һ�����㣬��firstָ��ڶ������ڵĶ���
						this->E--;
						continue;
					}
					if (AdjList[j].first->next != NULL)		//�ڽӱ�������x�ĵڶ������㲻Ϊ��
					{
						ArcNode* pre = AdjList[j].first;			//����һ��ָ��ָ��j�ĵ�һ������
						while (pre->next != NULL)
						{
							if (pre->next->adjvex == i)
							{
								pre->next = pre->next->next;		//�����ɾ��
								this->E--;
								continue;
							}
							pre = pre->next;					//���Ǽ���ѭ����һ��
						}
					}
				}
			}
			this->V--;
			cout << "ɾ���ɹ���" << endl;
			return;
		}
	}
	cout << "δ�ҵ����㣺" << x << endl;
}

void ALGraph::AddEdge(elemtype x, elemtype y)			//�������<x, y>�����ڣ���ͼ����Ӹñ�
{
	int head = -1;								//��ʼ��Ϊ-1
	int tail = -1;								//��ʼ��Ϊ-1
	for (int i = 0; i < MaxVertexNum; i++)		//�������������
	{
		if (AdjList[i].data == x)			//����� i ��data == x
		{
			head = i;					//��¼���x���±�
		}
		if (AdjList[i].data == y)		//����� i �� data == y
		{
			tail = i;					//��¼�յ�y���±�
		}
	}

	if (head == -1 || tail == -1)				//���ѭ������head��tail��ֵû�иı䣬��˵��û���ҵ�����Ԫ��
	{
		cout << "��������" << endl;
	}
	else                                        //���������㣬�����
	{
		if (AdjList[head].first == NULL)		//û�����ڵĵ�һ������
		{
			AdjList[head].first = new ArcNode;
			AdjList[head].first->adjvex = tail;
			AdjList[head].first->next = NULL;
		}
		else
		{
			ArcNode* cur = AdjList[head].first;			//����һ��ָ��ָ������x�ĵ�һ������
			while (cur->next != NULL)
			{
				if (cur->adjvex == tail)			//����Ѿ����ڱ���
				{
					cout << "�ñ��Ѵ��ڣ�" << endl;
					return;
				}
				cur = cur->next;
			}
			if (cur->adjvex == tail)	//��Ϊwhileѭ��û�м�����һ��Ԫ�ؾ��˳��ˣ����Գ�����Ҫ�ټ��һ��
			{
				cout << "�ñ��Ѵ��ڣ�" << endl;
				return;
			}
			cur->next = new ArcNode;
			cur->next->adjvex = tail;
			cur->next->next = NULL;
		}
		cout << "��ӳɹ���" << endl;
		this->E++;
	}
	return;
}

void ALGraph::RemoveEdge(elemtype x, elemtype y)			//�������<x, y>���ڣ���ͼ��ɾ���ñ�
{
	int head = -1;								//��ʼ��Ϊ-1
	int tail = -1;								//��ʼ��Ϊ-1
	for (int i = 0; i < MaxVertexNum; i++)		//�������������
	{
		if (AdjList[i].data == x)			//����� i ��data == x
		{
			head = i;					//��¼���x���±�
		}
		if (AdjList[i].data == y)		//����� i �� data == y
		{
			tail = i;					//��¼�յ�y���±�
		}
	}

	if (head == -1 || tail == -1)				//���ѭ������head��tail��ֵû�иı䣬��˵��û���ҵ�����Ԫ��
	{
		cout << "��������" << endl;
		return;
	}
	else                                        //���������㣬������ж�
	{
		if (AdjList[head].first != NULL)		//�����ڵĵ�һ������
		{
			if (AdjList[head].first->adjvex == tail)			//�ڽӱ��е�һ���Ͷ���x���ڵĶ���
			{
				AdjList[head].first = AdjList[head].first->next;	//ɾ����һ�����㣬��firstָ��ڶ������ڵĶ���
				this->E--;
				cout << "ɾ���ɹ���" << endl;
				return;
			}
			else if(AdjList[head].first->next != NULL)				//�ڽӱ�������x�ĵڶ������㲻Ϊ��
			{
				ArcNode* pre = AdjList[head].first;			//����һ��ָ��ָ������x�ĵ�һ������
				while (pre->next != NULL)
				{
					if (pre->next->adjvex == tail)		//�ж���һ�������Ƿ����յ�
					{
						pre->next = pre->next->next;		//�����ɾ��
						this->E--;							//�߼�1
						cout << "ɾ���ɹ���" << endl;
						return;
					}
					pre = pre->next;					//���Ǽ���ѭ����һ��
				}
				cout << "û���ҵ��������������ڵıߣ�" << endl;
				return;
			}
			else              //ֻ��һ��firstָ��Ķ��㣬���һ������ڣ����˳�
			{
				cout << "û���ҵ��������������ڵıߣ�" << endl;
				return;
			}
		}
		else             //û����x���ڵĶ��㣬ֱ���˳�
		{
			cout << "û���ҵ��������������ڵıߣ�" << endl;
			return;
		}	
	}
}

bool ALGraph::FirstNeighbor(elemtype x)		//��ͼ�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ����򷵻�false
{
	for (int i = 0; i < MaxVertexNum; i++)		//�������������
	{
		if (AdjList[i].data == x)			//����� i ��data == x
		{
			if (AdjList[i].first != NULL)
			{
				cout << "�ҵ��ˣ�";
				cout << AdjList[AdjList[i].first->adjvex].data << endl;	//��ӡ��һ���ڽӵ��Ԫ��ֵ
				return true;
			}
			else
			{
				cout << "û���ҵ���һ���ڽӵ㣡" << endl;
				return false;
			}
		}
	}
	cout << "û���ҵ��ö��㣡" << endl;			//��ѭ��˵��û���ҵ�����
	return false;
}

bool visited[MaxVertexNum];						//���ʱ������

void ALGraph::DFS()			//	������ȱ�������
{
	for (int i = 0; i < MaxVertexNum; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < MaxVertexNum; i++)
	{
		if (!visited[i] && AdjList[i].data != '#')
		{
			DFSTraverse(i);
		}
	}
}

void ALGraph::DFSTraverse(int i)		
{
	visited[i] = true;
	cout << AdjList[i].data << " ";
	ArcNode* p;
	p = AdjList[i].first;
	while (p)
	{
		if (!visited[p->adjvex])		//��һ���ڽӵ�û�б�����
		{
			DFSTraverse(p->adjvex);
		}
		p = p->next;			//�ƶ�����ǰ�������һ���ڽӵ�
	}
}

queue<int> q;		//��������

void ALGraph::BFS() 
{											//��ͼ���й�����ȱ���
	for (int i = 0; i < MaxVertexNum; i++) 
	{
		visited[i] = false;                  //���ʱ�������ʼ��
	}                      
	for (int i = 0; i < MaxVertexNum; i++) 
	{											//��0�Ŷ��㿪ʼ����
		if (!visited[i] && AdjList[i].data != '#') 
		{                    //��ÿ����ͨ��������һ��BFS
			BFSTraverse(i);                       //viδ�����ʹ�����vi��ʼBFS
		}
	}
}

void ALGraph::BFSTraverse(int v) 
{                   //�Ӷ���v������������ȱ���ͼ
	visited[v] = true;
	cout << AdjList[v].data << " ";
	q.push(v);			//���
	while (!q.empty()) 
	{
		q.pop();                       //����v������
		ArcNode* tmp = AdjList[v].first;
		while(tmp)
		{
			int w = tmp->adjvex;
			//���v�����ڽӵ�
			if (!visited[w])
			{                //wΪv����δ���ʵ��ڽӶ���
				visited[w] = true;
				cout << AdjList[w].data << " ";           //��w���ѷ��ʱ��
				q.push(w);              //����w�����
			}
			tmp = tmp->next;
		}
	}
}