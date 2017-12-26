// 3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMEaNT 10
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;
void CreateList(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i >0; --i)
	{
		LNode *p = (LinkList)malloc(sizeof(LNode));
		printf("Input the data:");
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}
void InsertSort(LinkList &L)
{
	LinkList p, q, r, s;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		r = L;
		q = L->next;
		while (q != NULL&&q->data <= p->data)
		{
			r = q;
			q = q->next;
		}
		s = p->next;
		p->next = r->next;
		r->next = p;
		p = s;
	}
}
void show(LinkList &L)
{
	LinkList ptr = L->next;
	while(ptr != NULL)
	{
		printf("%d", ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	LNode *a;
	int n;
	printf("Input the length:");
	scanf_s("%d", &n);
	CreateList(a, n);
	InsertSort(a);
	show(a);
	system("pause");
	return 0;
}