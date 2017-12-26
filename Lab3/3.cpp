// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#define MAXQSIZE 100
typedef struct
{
	int *base;
	int front;
	int rear;
	int size;
}Queue;
void InitQueue(Queue &Q, int k)
{
	Q.base = (int *)malloc(k * sizeof(int));
	if (!Q.base)
		exit(0);
	Q.front = 0;
	Q.rear = 0;
	Q.size = k;
}
int QueueLength(Queue Q)
{
	return (Q.rear - Q.front + Q.size) % Q.size;
}
void EnQueue(Queue &Q, int e)
{
	if ((Q.rear + 1) % Q.size == Q.front)
	{
		Q.base = (int *)realloc(Q.base, Q.size * sizeof(int));
		if (!Q.base)
			exit(0);
		Q.front = 0;
		Q.rear = 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.size;
}
int DeQueue(Queue &Q)
{
	if (Q.front == Q.rear)
		exit(0);
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.size;
	return e;
}
int fib(Queue &Q, int max, int k)
{
	int result = 0, i, temp = 0;
	InitQueue(Q, k);
	for (i = 0; i < k - 2; ++i)
		EnQueue(Q, 0);
	for (i = k - 1; i < k; ++i)
		EnQueue(Q, 1);
	for (i = k + 1; temp < max; ++i)
	{
		temp = 2 * Q.base[Q.rear] - Q.base[Q.front];
		DeQueue(Q);
		EnQueue(Q, temp);
	}
	result = Q.base[Q.rear - 1];
	return result;
}
int main()
{
	Queue Q;
	int max, k, f;
	printf("Input max:");
	scanf_s("%d", &max);
	printf("Input k:");
	scanf_s("%d", &k);
	if (k < 2)
	{
		printf("k ERROR");
		exit(0);
	}
	f = fib(Q, max, k);
	printf("f(n)=%d\n", f);
	system("pause");
    return 0;
}
