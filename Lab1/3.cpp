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
		scanf_s("%d", p->data);
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	LNode *a;
	int n;
	printf("Input the length:");
	scanf_s("%d", &n);
	CreateList(a, n);
	system("pause");
    return 0;
}

