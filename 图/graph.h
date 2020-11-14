#pragma once

#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 10           //图中顶点数目的最大值
typedef char elemtype;				//元素类型
typedef int weighttype;				//权值类型

class ArcNode					 //边表结点
{
public:
	int adjvex;                    //该弧指向的顶点的位置
	ArcNode* next;				  //指向下一条弧的指针
	//InfoType info;              //权值
};

class VNode							//顶点表结点
{
public:
	elemtype data;                 //顶点信息
	ArcNode* first;                //指向第一条依附该顶点的弧的指针
};

class ALGraph				//以邻接表存储的图
{
public:
	ALGraph();					 					//构造函数
	void GetV();										//获得图中顶点的数量
	void GetE();										//获得图中边的数量
	void InsertVertex(elemtype x);					//在图中插入顶点x
	void DeleteVertex(elemtype x);					//在图中删除顶点x
	void AddEdge(elemtype x, elemtype y);			//若有向边<x, y>不存在，在图中添加该边
	void RemoveEdge(elemtype x, elemtype y);			//若有向边<x, y>存在，从图中删除该边
	void Print();										//打印
	bool FirstNeighbor(elemtype x);					//求图中顶点x的第一个邻接点，若有则返回顶点号，否则返回false
	void DFS();						//DFS
	void BFS();				//BFS
	void DFSTraverse(int i);			//	深度优先遍历过程
	void BFSTraverse(int v);			//  广度优先遍历过程	

public:
	int V;				//顶点数量
	int E;				//边的数量
	int *in_degree;		//入度,为了拓扑排序
	VNode* AdjList;		//邻接表
};