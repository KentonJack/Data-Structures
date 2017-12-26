// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
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
void InitQueue(LinkQueue &Q)
{
	Q.front = (QueuePtr)malloc(sizeof(QNode));
	Q.rear = Q.front;
	if (!Q.front)
		exit(0);
	Q.front->next = NULL;
}
void DestroyQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}
void ClearQueue(LinkQueue &Q)
{
	Q.front = (QueuePtr)realloc(Q.front, sizeof(QNode));
	Q.rear = Q.front;
	if (!Q.front)
		exit(0);
	Q.front->next = NULL;
}
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
int QueueLength(LinkQueue Q)
{
	int length = 0;
	if (!Q.front)
		exit(0);
	QueuePtr p = Q.front->next;
	while (p->next != Q.rear)
	{
		length++;
		p = p->next;
	}
	return length;
}
int GetHead(LinkQueue Q, int e)
{
	if (Q.front == Q.rear)
		return 0;
	else
	{
		QueuePtr p = Q.front->next;
		e = p->data;
		return e;
	}
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
bool visit(LinkQueue Q)
{
	if (!Q.front)
		return false;
	else
	{
		QueuePtr p = Q.front;
		while (p != Q.rear)
		{
			p = p->next;
		}
		return true;
	}
}
void QueueTraverse(LinkQueue Q)
{
	visit(Q);
	if (!visit(Q))
		exit(0);
}
int main()
{
	system("pause");
    return 0;
}

