// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "iomanip"
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
using namespace std;
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
typedef enum { DG, DN, UDG, UDN }GraphKind;
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
typedef struct ArcCell
{
	VRType adj;
	InfoPtr *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vex[MAX_VERTEX_NUM];
	AdjMatrix arc;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;
void InitQueue(LinkQueue &Q)
{
	Q.front = (QueuePtr)malloc(sizeof(QNode));
	Q.rear = Q.front;
	if (!Q.front)
		exit(0);
	Q.front->next = NULL;
}
void EnQueue(LinkQueue &Q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(0);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
int DeQueue(LinkQueue &Q, int e)
{
	if (Q.front == Q.rear)
		return 0;
	else
	{
		QueuePtr p = Q.front->next;
		e = p->data;
		Q.front->next = p->next;
		if (Q.rear == p)
			Q.rear = Q.front;
		free(p);
		return e;
	}
}
int LocateVex(MGraph N, VertexType v)
{
	int i;
	for (i = 0; i < N.vexnum; ++i)
	{
		if (strcmp(N.vex[i], v) == 0)
			return i;
	}
	return -1;
}
void CreateGraph(MGraph *N)
{
	int i, j, k, w;
	VertexType v1, v2;
	printf("Input vex number:");
	cin>>(*N).vexnum;
	printf("Input arc number:");
	cin>>(*N).arcnum;
	printf("Input vex value:");
	for (i = 0; i < N->vexnum; i++)
		cin>>N->vex[i];
	for (i = 0; i < N->vexnum; i++)
	{
		for (j = 0; j < N->vexnum; j++)
		{
			N->arc[i][j].adj = INFINITY;
			N->arc[i][j].info = NULL;
		}
		printf("Input terminal, head and weight:");
		for (k = 0; k < N->vexnum; k++)
		{
			cin >> v1 >> v2 >> w;
			i = LocateVex(*N, v1);
			j = LocateVex(*N, v2);  
			N->arc[i][j].adj = w;
		}
		N->kind = DN;
	}
}
void DestroyGraph(MGraph *N)
{
	int i, j;
	for (i = 0; i < N->vexnum; i++)
	{
		for (j = 0; j < N->vexnum; j++)
		{
			if (N->arc[i][j].adj != INFINITY)
			{
				if (N->arc[i][j].info != NULL)
				{
					free(N->arc[i][j].info);
					N->arc[i][j].info = NULL;
				}
			}
		}
	}
	N->arcnum = 0;
	N->vexnum = 0;
}
int GetVex(MGraph G, VertexType v)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(G.vex[i], v) == 0)
			return i;
	}
}
void PutVex(MGraph &G, VertexType v, int value)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(G.vex[i], v) == 0)
		{
			i = value;
			exit(0);
		}
	}
}
int FirstAdjvex(MGraph G, VertexType v)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(G.vex[i], v) == 0)
			return i + 1;
	}
	return NULL;
}
int NextAdjvex(MGraph G, VertexType v, VertexType w)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(G.vex[i], v) == 0)
			return i + 2;
	}
	return NULL;
}
void InsertVex(MGraph &G, VertexType v)
{
	G.vexnum++;
	strcpy(G.vex[G.vexnum], v);
}
void DeleteVex(MGraph *G, VertexType v)
{
	int i;
	for (i = 0; i < G->vexnum; ++i)
	{
		if (strcmp(G->vex[i], v) == 0)
		{
			strcpy(G->vex[i], "");
			int j, temp;
			for (temp = i; temp < G->vexnum; temp++)
			{
				for (j = 0; j < G->vexnum; j++)
				{
					if (G->arc[temp][j].adj != INFINITY)
					{
						if (G->arc[temp][j].info != NULL)
						{
							free(G->arc[temp][j].info);
							G->arc[temp][j].info = NULL;
						}
					}
				}
			}
		}
	}
}
void InsertArc(MGraph *N, VertexType v, VertexType w)
{
	int i, j;
	i = LocateVex(*N, v);
	j = LocateVex(*N, w);
	N->arc[i][j].adj = 1;
	N->arcnum++;
}
void DeleteArc(MGraph *N, VertexType v, VertexType w)
{
	int i, j;
	for (i = 0; i < N->vexnum; i++)
	{
		for (j = 0; j < N->vexnum; j++)
		{
			if (strcmp(N->vex[i], v) == 0)
			{
				if (strcmp(N->vex[j], v) == 0)
				{
					free(N->arc[i][j].info);
					N->arc[i][j].info = NULL;
				}
			}
		}
	}
	N->arcnum--;
}
bool visit(MGraph G, VertexType v)
{
	int i;
	i = LocateVex(G, v);
	if (i == -1)
		return false;
	printf("No.%d visited\n", i);
	return true;
}
void DFSTraverse(MGraph G, VertexType v)
{
	int visited[MAX_VERTEX_NUM], i, num, j;
	num = LocateVex(G, v);
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	visited[num] = 1;
	visit(G, v);
	for (j = FirstAdjvex(G, G.vex[num]); j >= 0&& visit(G, G.vex[j]); j = NextAdjvex(G, G.vex[num], G.vex[j]))
		if (!visited[j])
		{
			DFSTraverse(G, G.vex[j]);
			visit(G, G.vex[j]);
		}
}
void BFSTraverse(MGraph G, VertexType v)
{
	int visited[MAX_VERTEX_NUM], i, num, j, flag = 0, w;
	num = LocateVex(G, v);
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	visited[num] = 1;
	visit(G, v);
	LinkQueue Q;
	InitQueue(Q);
	for (j = FirstAdjvex(G, G.vex[num]); j >= 0 && visit(G, G.vex[j]); j = NextAdjvex(G, G.vex[num], G.vex[j]))
	{
		if (!visited[j])
		{
			visited[j] = 1;
			visit(G, G.vex[j]);
			EnQueue(Q, j);
			while(!QueueEmpty(Q))
			{
				DeQueue(Q, flag);
				for (w = FirstAdjvex(G, G.vex[flag]); w >= 0; w = NextAdjvex(G, G.vex[flag], G.vex[w]))
				{
					if (!visited[w])
					{
						visited[w] = 1;
						visit(G, G.vex[w]);
						EnQueue(Q, w);
					}
				}
			}
		}
	}
}
int main()
{
	MGraph G;
	CreateGraph(&G);
	DestroyGraph(&G);
	system("pause");
    return 0;
}

