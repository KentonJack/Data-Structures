// 1.cpp : Defines the enttry point for the console application.
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
	for (int i = n; i >0 ; --i)
	{
		LNode *p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",p->data);
		p->next = L->next;
		L->next = p;
	}
}
void DestroyList(LinkList &L)
{
	if (!L)
		exit(0);
	free(L);
}
void ClearList(LinkList &L)
{
	if (!L)
		exit(0);
	free(L->next);
}
bool ListEmpty(LinkList L)
{
	if (!L)
		exit(0);
	if (L->next == NULL)
		return true;
	else
		return false;
}
int ListLength(LinkList L)
{
	if (!L)
		exit(0);
	int i;
	for (i = 0; L->next != NULL; i++)
	{
		L = L->next;
	}
	return i;
}
int GetElem(LinkList L, int i, int &e)
{
	LNode *p = L->next;
	int j = 1;
	while (p && j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return 0;
	e = p->data;
	return e;
}
int compare(int i, int j)
{
	if (i == j)
		return 1;
	else
		return 0;
}
int LocateElem(LinkList L, int e)
{
	if (!L)
		exit(0);
	LNode *p = L->next;
	for (int i = 0; p->next != NULL; i++)
	{
		p = p->next;
		if (compare(e, p->data) == 1)
			return i;
	}
}
int PriorElem(LinkList &L, int cur_e, int &pre_e)
{
	LNode *p = L->next;
	LNode *pre = L;
	if (!p || !pre)
		exit(0);
	for (; p->next != NULL;)
	{
		if (p->data == cur_e)
			pre_e = pre->data;
		p = p->next;
		pre = pre->next;
	}
	return pre_e;
}
int NextElem(LinkList &L, int cur_e, int &next_e)
{
	LNode *p = L->next;
	LNode *aft = p->next;
	if (!p || !aft)
		exit(0);
	for (; aft->next != NULL;)
	{
		if (p->data == cur_e)
			next_e = aft->data;
		p = p->next;
		aft = aft->next;
	}
	return next_e;
}
void ListInsert(LinkList &L, int i, int e)
{
	LNode *p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		exit(0);
	LNode *s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void ListDelete(LinkList &L, int i, int &e)
{
	LNode *p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		exit(0);
	LNode *q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}
bool visit(LinkList &L)
{
	LNode *p = L->next;
	for (; p->next != NULL; p = p->next)
		;
	return true;
}
void ListTraverse(LinkList L)
{
	if (!L)
		exit(0);
	visit(L);
	if (!(visit(L)))
		exit(0);
	else
		printf("Success");
}
int main()
{
	system("pause");
	return 0;
}

