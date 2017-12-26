// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void InitBiTree(BiTree &T)
{
	int i;
	printf("Input the data, '0' represents a null tree:");
	scanf_s("%d", &i);
	if (i == 0)
		BiTree bt = NULL;
	else
	{
		BiTree bt = (BiTree)malloc(sizeof(BiTNode));
		if (!(bt))
			exit(0);
		(bt)->data = i;
		InitBiTree(bt->lchild);
		InitBiTree(bt->rchild);
	}
}
void DestroyBiTree(BiTree &T)
{
	if (T)
	{
		if (T->lchild)
			DestroyBiTree(T->lchild);
		if (T->rchild)
			DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
}
void CreateBiTree(BiTree &T)
{
	InitBiTree(T);
}
bool Visit()
{
	return true;
}
void PreOrderTraverse(BiTree T)
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			Visit();
			stack[top] = p;
			top++;
			p = p->lchild;
		}
		if (top > 0)
		{
			top--;
			p = stack[top];
			p = p->rchild;
		}
	}
}
void InOrderTraverse(BiTree T)
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			stack[top] = p;
			top++;
			p = p->lchild;
			Visit();
		}
		if (top > 0)
		{
			top--;
			p = stack[top];
			p = p->rchild;
		}
	}
}
void PostOrderTraverse(BiTree T)
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			stack[top] = p;
			top++;
			p = p->lchild;
			Visit();
		}
		if (top > 0)
		{
			top--;
			p = stack[top];
			p = p->rchild;
		}
	}
}
void LevelOrderTraverse(BiTree T)
{
	BiTree queue[100];
	BiTNode *p;
	int front = -1, rear = 0;
	queue[rear] = T;
	while (front != rear)
	{
		front = (front + 1) % 100;
		p = queue[front];
		Visit();
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % 100;
			queue[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % 100;
			queue[rear] = p->rchild;
		}
	}
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	InOrderTraverse(T);
	PostOrderTraverse(T);
	LevelOrderTraverse(T);
	system("pause");
    return 0;
}

