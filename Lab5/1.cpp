// 1.cpp : Defines the entry point for the console application.
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
void ClearBiTree(BiTree &T)
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
bool BiTreeEmpty(BiTree T)
{
	if (T == NULL)
		return true;
	else
		return false;
}
int BiTreeDepth(BiTree T)
{
	int ldepth, rdepth;
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild)
		return 1;
	else {
		ldepth = BiTreeDepth(T->lchild);
		rdepth = BiTreeDepth(T->rchild);
		return (ldepth > rdepth ? ldepth : rdepth) + 1;
	}
}
bool Visit()
{
	return true;
}
void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		Visit();
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		Visit();
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit();
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
BiTree Root(BiTree T)
{
	return T;
}
int Value(BiTree T, BiTree e)
{
	int value = 0;
	if (!T)
		return 0;
	value = e->data;
	return value;
}
void Assign(BiTree T, BiTree &e, int value)
{
	if (!T)
		exit(0);
	e->data = value;
}
BiTree Parent(BiTree T, BiTree e)
{
	if (!T)
		exit(0);
	if (T == e)
		return NULL;
	if (T->lchild == e || T->rchild == e)
		return T;
	BiTree temp = T;
	while (temp->lchild != e&&temp->rchild != e)
	{
		PreOrderTraverse(temp);
	}
	return temp;
}
BiTree LeftChild(BiTree T, BiTree e)
{
	if (!T)
		exit(0);
	if (!e->lchild)
		return NULL;
	return e->lchild;
}
BiTree RightChild(BiTree T, BiTree e)
{
	if (!T)
		exit(0);
	if (!e->rchild)
		return NULL;
	return e->rchild;
}
BiTree LeftSibling(BiTree T, BiTree e)
{
	if (!T)
		exit(0);
	if (e == T->lchild)
		return NULL;
	BiTree Temp;
	Temp = Parent(T, e);
	return Temp->lchild;
}
BiTree RightSibling(BiTree T, BiTree e)
{
	if (!T)
		exit(0);
	if (e == T->rchild)
		return NULL;
	BiTree Temp;
	Temp = Parent(T, e);
	return Temp->rchild;
}
void InsertChild(BiTree &T, BiTree p, BiTree c)
{
	int LR = 0;
	if (!T)
		exit(0);
	printf("Input LR:");
	scanf_s("%d", &LR);
	if (LR == 0)
	{
		c = p->lchild;
	}
	else if (LR == 1)
	{
		c = p->rchild;
	}
	else
	{
		printf("Error LR\n");
		InsertChild(T, p, c);
	}
}
void DeleteChild(BiTree &T, BiTree p)
{
	int LR = 0;
	if (!T)
		exit(0);
	printf("Input LR:");
	scanf_s("%d", &LR);
	if (LR == 0)
	{
		DestroyBiTree(p->lchild);
	}
	else if (LR == 1)
	{
		DestroyBiTree(p->rchild);
	}
	else
	{
		printf("Error LR\n");
		DeleteChild(T, p);
	}
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	system("pause");
    return 0;
}

