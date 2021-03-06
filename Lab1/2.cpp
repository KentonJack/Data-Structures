// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
	int *ptr;
	int length;
	int listsize;
}List;
void InitList(List *L)
{
	L->ptr = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->ptr)
		exit(0);
	L->length = 0;
	L->listsize = 0;
}
void CreateList(List *L,int n)
{
	InitList(L);
	int i;
	for ( i = 0; i < n; i++)
	{
		printf("Input:");
		scanf_s("%d", &L->ptr[i]);
		L->length++;
	}
}
void ReverseList(List *L)
{
	int i;
	int temp;
	int n = L->length;
	for (i = 0; i < n / 2; i++)
	{
		temp = L->ptr[i];
		L->ptr[i] = L->ptr[n - 1 - i];
		L->ptr[n - 1 - i] = temp;
	}
	for ( i = 0; i < L->length; i++)
	{
		printf("%d", L->ptr[i]);
	}
}
int main()
{
	List a;
	printf("Input the length:");
	int n;
	scanf_s("%d", &n);
	CreateList(&a, n);
	ReverseList(&a);
	system("pause");
    return 0;
}

