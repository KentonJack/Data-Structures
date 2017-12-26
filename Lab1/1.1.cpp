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
void InitList(List &L)
{
	L.ptr = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.ptr)
		exit(0);
	L.length = 0;
	L.listsize = 0;
}
void DestroyList(List &L)
{
	if (!L.ptr)
		exit(0);
	free(L.ptr);
}
void ClearList(List &L)
{
	if (!L.ptr)
		exit(0);
	L.ptr = (int *)realloc(L.ptr, LIST_INIT_SIZE * sizeof(int));
	if (!L.ptr)
		exit(0);
	L.length = 0;
	L.listsize = 0;
}
bool ListEmpty(List L)
{
	if (!L.ptr)
		exit(0);
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (!L.ptr[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int ListLength(List L)
{
	if (!L.ptr)
		exit(0);
	return L.length;
}
int GetElem(List L, int i, int &e)
{
	if (!L.ptr || i<1 || i>L.length)
		exit(0);
	e = L.ptr[i];
	return e;
}
int compare(int i, int j)
{
	if (i == j)
		return 1;
	else
		return 0;
}
void LocateElem(List L, int e)
{
	if (!L.ptr)
		exit(0);
	int i;
	for (int i = 0; i < L.length; i++)
	{
		if (compare(L.ptr[i], e) == 1)
		{
			exit(1);
		}
		else
		{
			exit(0);
		}
	}
}
int PriorElem(List &L, int cur_e, int &pre_e)
{
	if (!L.ptr)
		exit(0);
	for (int i = 1; i < L.length; i++)
	{
		if (L.ptr[i] == cur_e)
		{
			pre_e = L.ptr[i - 1];
			return pre_e;
		}
		else
			exit(0);
	}
}
int NextElem(List &L, int cur_e, int &next_e)
{
	if (!L.ptr)
		exit(0);
	for (int i = 0; i < L.length - 1; i++)
	{
		if (L.ptr[i] == cur_e)
		{
			next_e = L.ptr[i + 1];
			return next_e;
		}
		else
			exit(0);
	}
}
void ListInsert(List &L, int i, int e)
{
	if (!L.ptr || i<1 || i>L.length + 1)
		exit(0);
	for (int j = L.length; j > i; j--)
	{
		L.ptr[j + 1] = L.ptr[j];
	}
	L.length++;
	L.ptr[i] = e;
}
int ListDelete(List &L, int i, int &e)
{
	if (!L.ptr || i<1 || i>L.length)
		exit(0);
	e = L.ptr[i];
	for (int j = i; j < L.length; j++)
	{
		L.ptr[j] = L.ptr[j + 1];
	}
	L.length--;
	return e;
}
bool visit(List &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d", L.ptr[i]);
	}
	return true;
}
void ListTraverse(List L)
{
	if (!L.ptr)
		exit(0);
	visit(L);
	if (!(visit(L)))
		exit(0);
	else
		printf("Success");
}
int main()
{
	List a;
	InitList(a);
	system("pause");
	return 0;
}



