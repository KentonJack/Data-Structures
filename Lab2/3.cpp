// 1.cpp : Defines the entry point for the console application.
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
void CreateList(List *L, int n)
{
	InitList(L);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Input:");
		scanf_s("%d", &L->ptr[i]);
		L->length++;
	}
}
void InsertSort(List *L)
{
	int i, j, temp;
	for (i = 1; i < L->length; i++)
	{
		temp = L->ptr[i];
		j = i - 1;
		while ((j >= 0) && (L->ptr[j]>temp))
		{
			L->ptr[j + 1] = L->ptr[j];
			j--;
		}
		if (j != i - 1)
		{
			L->ptr[j + 1] = temp;
		}
	}
}
void MergeList(List LA, List LB, List &LC)
{
	int *pa, *pb, *pc, *pa_last, *pb_last;
	pa = LA.ptr;
	pb = LB.ptr;
	LC.length = LA.length + LB.length;
	LC.ptr = new int[LC.length];
	pc = LC.ptr;
	if (!pc)
		exit(0);
	pa_last = LA.ptr + LA.length - 1;
	pb_last = LB.ptr + LB.length - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa_last<*pb_last)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
	for (int i = 0; i < LC.length; i++)
	{
		if (LC.ptr[i] == LC.ptr[i + 1])
		{
			for (int j = i; j < LC.length; j++)
			{
				LC.ptr[j] = LC.ptr[j + 1];
			}
			LC.length--;
		}
	}
}
void show(List *L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d", L->ptr[i]);
	}
}
int main()
{
	List a, b, c;
	InitList(&c);
	printf("Input the length of a:");
	int n;
	scanf_s("%d", &n);
	CreateList(&a, n);
	printf("Input the length of b:");
	int m;
	scanf_s("%d", &m);
	CreateList(&b, m);
	MergeList(a, b, c);
	show(&c);
	system("pause");
	return 0;
}
