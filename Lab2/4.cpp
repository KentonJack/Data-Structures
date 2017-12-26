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
void MergeList(LinkList &a, LinkList&b, LinkList&c)
{
	LNode *pa, *pb, *pc;
	pa = a->next;
	pb = b->next;
	c = a;
	pc = c;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(b);
	InsertSort(c);
	pc = c;
	LNode *pc_next = pc->next;
	while (pc_next)
	{
		if (pc->data == pc_next->data)
		{
			LNode *q = pc->next;
			pc->next = q->next;
			free(q);
		}
		pc_next = pc_next->next;
		pc = pc->next;
	}
}
void show(LinkList &L)
{
	LinkList ptr = L->next;
	while (ptr != NULL)
	{
		printf("%d", ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	LNode *a, *b, *c;
	int m,n;
	printf("Input the length of a:");
	scanf_s("%d", &m);
	CreateList(a, m);
	printf("Input the length of b:");
	scanf_s("%d", &n);
	CreateList(b, n);
	MergeList(a, b, c);
	show(c);
	system("pause");
	return 0;
}