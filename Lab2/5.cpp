// 5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
typedef struct DuLNode
{
	int data;
	int freq = 0;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;
void CreateList(DuLinkList &L, int n)
{
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->next = NULL;
	for (int i = n; i >0; --i)
	{
		DuLNode *p = (DuLinkList)malloc(sizeof(DuLNode));
		printf("Input the data:");
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}
void FreqSort(DuLinkList &L)
{
	DuLinkList p, q, r, s;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		r = L;
		q = L->next;
		while (q != NULL&&q->freq >= p->freq)
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
void LOCATE(DuLinkList L, int x)
{
	DuLinkList ptr = L->next;
	int i = 0;
	while (ptr != NULL)
	{
		if (ptr->data == x)
		{
			printf("第%d个结点", i);
			ptr->freq++;
		}
		i++;
		ptr = ptr->next;
	}
	FreqSort(L);
}
void Show(DuLinkList &L)
{
	DuLinkList ptr = L->next;
	while (ptr != NULL)
	{
		printf("%d", ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	DuLinkList a;
	int i, n;
	char flag;
	printf("Input the length:");
	scanf_s("%d", &n);
	CreateList(a, n);
	while (1)
	{
		printf("Input the number:");
		scanf_s("%d", &i);
		LOCATE(a, i);
		printf("Continue?(Y/N)");
		scanf_s("%c", &flag);
		if (flag == 'N')
			break;
	}
	Show(a);
	system("pause");
    return 0;
}
