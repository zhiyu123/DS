#pragma once

#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 10           //ͼ�ж�����Ŀ�����ֵ
typedef char elemtype;				//Ԫ������
typedef int weighttype;				//Ȩֵ����

class ArcNode					 //�߱���
{
public:
	int adjvex;                    //�û�ָ��Ķ����λ��
	ArcNode* next;				  //ָ����һ������ָ��
	//InfoType info;              //Ȩֵ
};

class VNode							//�������
{
public:
	elemtype data;                 //������Ϣ
	ArcNode* first;                //ָ���һ�������ö���Ļ���ָ��
};

class ALGraph				//���ڽӱ�洢��ͼ
{
public:
	ALGraph();					 					//���캯��
	void GetV();										//���ͼ�ж��������
	void GetE();										//���ͼ�бߵ�����
	void InsertVertex(elemtype x);					//��ͼ�в��붥��x
	void DeleteVertex(elemtype x);					//��ͼ��ɾ������x
	void AddEdge(elemtype x, elemtype y);			//�������<x, y>�����ڣ���ͼ����Ӹñ�
	void RemoveEdge(elemtype x, elemtype y);			//�������<x, y>���ڣ���ͼ��ɾ���ñ�
	void Print();										//��ӡ
	bool FirstNeighbor(elemtype x);					//��ͼ�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ����򷵻�false
	void DFS();						//DFS
	void BFS();				//BFS
	void DFSTraverse(int i);			//	������ȱ�������
	void BFSTraverse(int v);			//  ������ȱ�������	

public:
	int V;				//��������
	int E;				//�ߵ�����
	int *in_degree;		//���,Ϊ����������
	VNode* AdjList;		//�ڽӱ�
};