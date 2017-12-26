// 1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
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
void ClearStack(Stack &S)
{
	if (!S.base)
		exit(0);
	S.base = (int *)realloc(S.base, STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		exit(0);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
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
int StackLength(Stack S)
{
	if (!S.base)
		exit(0);
	return S.stacksize;
}
int GetTop(Stack S, int &e)
{
	if (S.top == S.base)
		exit(0);
	e = *(S.top - 1);
	return e;
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
bool visit(Stack &S)
{
	for (int i = 0; i < S.stacksize; i++)
	{
		printf("%d", *(S.base + i));
	}
	return true;
}
void StackTraverse(Stack S)
{
	if (!S.base)
		exit(0);
	visit(S);
	if (!(visit(S)))
		exit(0);
	else
		printf("Success");
}
int main()
{
	system("pause");
	return 0;
}