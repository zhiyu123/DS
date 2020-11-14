#include"graph.h"

ALGraph::ALGraph()		//创建一个包含v个顶点但不包含边的图
{
	this->E = 0;
	this->V = 0;
	this->in_degree = new int[MaxVertexNum]();
	this->AdjList = new VNode[MaxVertexNum];	//创建一个顶点表数组，用来后续存储顶点
	for (int i = 0; i < MaxVertexNum; i++)		//初始化邻接表
	{
		this->AdjList[i].data = '#';			//用#表示当前这个索引处没有节点
		this->AdjList[i].first = NULL;
	}
}

void ALGraph::GetV()										//获得图中顶点的数量
{
	cout << "当前图顶点的数量为：" << V << endl;
}

void ALGraph::GetE()									//获得图中边的数量
{
	cout << "当前图边的数量为：" << E << endl;
}

void ALGraph::Print()								//打印
{
	if (this->V == 0)
	{
		cout << "当前图中没有顶点！" << endl;
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

void ALGraph::InsertVertex(elemtype x)					//在图中插入顶点x
{
	if (this->V >= MaxVertexNum)
	{
		cout << "当前顶点表已满，无法再插入顶点！" << endl;
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
				cout << "插入成功！" << endl;
				break;
			}
		}
	}
}

void ALGraph::DeleteVertex(elemtype x)					//在图中删除顶点x
{	
	for (int i = 0; i < MaxVertexNum; i++)			//因为顶点可能不是连续的，所以要遍历整个顶点数组，而不是V的数量
	{
		int count = 0;		//统计删除顶点有几个出度
		if (AdjList[i].data == x)
		{
			if (AdjList[i].first != NULL)
			{
				count++;					//++是因为有一个first结点
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

			for (int j = 0; j < MaxVertexNum; j++)			//遍历所有顶点，将指向删除顶点的边都要清除
			{
				if (AdjList[j].first == NULL)			//没有相邻的第一个顶点
				{
					continue;			//继续下一次循环，判断下一个顶点
				}
				else if (AdjList[j].first != NULL)		//有相邻的第一个顶点
				{
					if (AdjList[j].first->adjvex == i)				//与j相邻的第一个顶点为i
					{
						AdjList[j].first = AdjList[j].first->next;	//删除第一个顶点，将first指向第二个相邻的顶点
						this->E--;
						continue;
					}
					if (AdjList[j].first->next != NULL)		//邻接表中相邻x的第二个顶点不为空
					{
						ArcNode* pre = AdjList[j].first;			//定义一个指针指向j的第一个顶点
						while (pre->next != NULL)
						{
							if (pre->next->adjvex == i)
							{
								pre->next = pre->next->next;		//如果是删除
								this->E--;
								continue;
							}
							pre = pre->next;					//不是继续循环下一个
						}
					}
				}
			}
			this->V--;
			cout << "删除成功！" << endl;
			return;
		}
	}
	cout << "未找到顶点：" << x << endl;
}

void ALGraph::AddEdge(elemtype x, elemtype y)			//若有向边<x, y>不存在，在图中添加该边
{
	int head = -1;								//初始化为-1
	int tail = -1;								//初始化为-1
	for (int i = 0; i < MaxVertexNum; i++)		//遍历整个顶点表
	{
		if (AdjList[i].data == x)			//顶点表 i 的data == x
		{
			head = i;					//记录起点x的下标
		}
		if (AdjList[i].data == y)		//顶点表 i 的 data == y
		{
			tail = i;					//记录终点y的下标
		}
	}

	if (head == -1 || tail == -1)				//如果循环结束head和tail的值没有改变，则说明没有找到两个元素
	{
		cout << "顶点有误！" << endl;
	}
	else                                        //有两个顶点，则继续
	{
		if (AdjList[head].first == NULL)		//没有相邻的第一个顶点
		{
			AdjList[head].first = new ArcNode;
			AdjList[head].first->adjvex = tail;
			AdjList[head].first->next = NULL;
		}
		else
		{
			ArcNode* cur = AdjList[head].first;			//定义一个指针指向相邻x的第一个顶点
			while (cur->next != NULL)
			{
				if (cur->adjvex == tail)			//如果已经存在边了
				{
					cout << "该边已存在！" << endl;
					return;
				}
				cur = cur->next;
			}
			if (cur->adjvex == tail)	//因为while循环没有检测最后一个元素就退出了，所以出来后要再检测一次
			{
				cout << "该边已存在！" << endl;
				return;
			}
			cur->next = new ArcNode;
			cur->next->adjvex = tail;
			cur->next->next = NULL;
		}
		cout << "添加成功！" << endl;
		this->E++;
	}
	return;
}

void ALGraph::RemoveEdge(elemtype x, elemtype y)			//若有向边<x, y>存在，从图中删除该边
{
	int head = -1;								//初始化为-1
	int tail = -1;								//初始化为-1
	for (int i = 0; i < MaxVertexNum; i++)		//遍历整个顶点表
	{
		if (AdjList[i].data == x)			//顶点表 i 的data == x
		{
			head = i;					//记录起点x的下标
		}
		if (AdjList[i].data == y)		//顶点表 i 的 data == y
		{
			tail = i;					//记录终点y的下标
		}
	}

	if (head == -1 || tail == -1)				//如果循环结束head和tail的值没有改变，则说明没有找到两个元素
	{
		cout << "顶点有误！" << endl;
		return;
	}
	else                                        //有两个顶点，则继续判断
	{
		if (AdjList[head].first != NULL)		//有相邻的第一个顶点
		{
			if (AdjList[head].first->adjvex == tail)			//邻接表中第一个和顶点x相邻的顶点
			{
				AdjList[head].first = AdjList[head].first->next;	//删除第一个顶点，将first指向第二个相邻的顶点
				this->E--;
				cout << "删除成功！" << endl;
				return;
			}
			else if(AdjList[head].first->next != NULL)				//邻接表中相邻x的第二个顶点不为空
			{
				ArcNode* pre = AdjList[head].first;			//定义一个指针指向相邻x的第一个顶点
				while (pre->next != NULL)
				{
					if (pre->next->adjvex == tail)		//判断下一个顶点是否是终点
					{
						pre->next = pre->next->next;		//如果是删除
						this->E--;							//边减1
						cout << "删除成功！" << endl;
						return;
					}
					pre = pre->next;					//不是继续循环下一个
				}
				cout << "没有找到两个顶点有相邻的边！" << endl;
				return;
			}
			else              //只有一个first指向的顶点，并且还不相邻，则退出
			{
				cout << "没有找到两个顶点有相邻的边！" << endl;
				return;
			}
		}
		else             //没有与x相邻的顶点，直接退出
		{
			cout << "没有找到两个顶点有相邻的边！" << endl;
			return;
		}	
	}
}

bool ALGraph::FirstNeighbor(elemtype x)		//求图中顶点x的第一个邻接点，若有则返回顶点号，否则返回false
{
	for (int i = 0; i < MaxVertexNum; i++)		//遍历整个顶点表
	{
		if (AdjList[i].data == x)			//顶点表 i 的data == x
		{
			if (AdjList[i].first != NULL)
			{
				cout << "找到了：";
				cout << AdjList[AdjList[i].first->adjvex].data << endl;	//打印第一个邻接点的元素值
				return true;
			}
			else
			{
				cout << "没有找到第一个邻接点！" << endl;
				return false;
			}
		}
	}
	cout << "没有找到该顶点！" << endl;			//出循环说明没有找到顶点
	return false;
}

bool visited[MaxVertexNum];						//访问标记数组

void ALGraph::DFS()			//	深度优先遍历过程
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
		if (!visited[p->adjvex])		//第一个邻接点没有被访问
		{
			DFSTraverse(p->adjvex);
		}
		p = p->next;			//移动到当前顶点的下一个邻接点
	}
}

queue<int> q;		//辅助队列

void ALGraph::BFS() 
{											//对图进行广度优先遍历
	for (int i = 0; i < MaxVertexNum; i++) 
	{
		visited[i] = false;                  //访问标记数组初始化
	}                      
	for (int i = 0; i < MaxVertexNum; i++) 
	{											//从0号顶点开始遍历
		if (!visited[i] && AdjList[i].data != '#') 
		{                    //对每个连通分量调用一次BFS
			BFSTraverse(i);                       //vi未被访问过，从vi开始BFS
		}
	}
}

void ALGraph::BFSTraverse(int v) 
{                   //从顶点v出发，广度优先遍历图
	visited[v] = true;
	cout << AdjList[v].data << " ";
	q.push(v);			//入队
	while (!q.empty()) 
	{
		q.pop();                       //顶点v出队列
		ArcNode* tmp = AdjList[v].first;
		while(tmp)
		{
			int w = tmp->adjvex;
			//检测v所有邻接点
			if (!visited[w])
			{                //w为v的尚未访问的邻接顶点
				visited[w] = true;
				cout << AdjList[w].data << " ";           //对w做已访问标记
				q.push(w);              //顶点w入队列
			}
			tmp = tmp->next;
		}
	}
}