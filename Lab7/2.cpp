// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#define MAX_VERTEX_NUM 20
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	char *info;
}ArcNode;
typedef struct VNode
{
	int data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}Stack;
void InitStack(Stack &S)
{
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		exit(0);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void DestroyStack(Stack &S)
{
	if (!S.base)
		exit(0);
	free(S.base);
}
bool StackEmpty(Stack S)
{
	if (!S.base)
		exit(0);
	int i;
	if (S.top == S.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(Stack &S, int e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
}
int pop(Stack &S, int e)
{
	if (S.base == S.top)
		exit(0);
	e = *(S.top - 1);
	--S.top;
	return e;
}
void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM])
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			if (p->adjvex = i)
				indegree[i]++;
			p = p->nextarc;
		}
	}
}
void TopologicalSort(ALGraph &G)
{
	Stack S;
	ArcNode *p;
	int i, k, count = 0;
	int indegree[MAX_VERTEX_NUM] = { 0 };
	FindInDegree(G, indegree);
	InitStack(S);
	for (i = 0; i < G.vexnum; ++i)
	{
		if (!indegree[i])
			push(S, i);
	}
	while (!StackEmpty(S))
	{
		pop(S, i);
		printf("%d:%d", i, G.vertices[i].data);
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (!(--indegree[k]))
				push(S, k);
		}
	}
	if (count < G.vexnum)
		exit(0);
	DestroyStack(S);
}
int main()
{
	ALGraph G;
	TopologicalSort(G);
	system("pause");
    return 0;
}