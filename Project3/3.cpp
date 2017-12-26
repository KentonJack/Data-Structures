// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct BiTNode
{
	char data;//���ڵ�����
	struct BiTNode *lchild, *rchild;//���Һ��ӽ��
}BiTNode, *BiTree;
typedef struct QNode
{
	BiTNode *data;//���нڵ�����
	struct QNode *next;//����nextָ��
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;//ͷָ��
	QueuePtr rear;//βָ��
}Queue;
int index;
char tree[100];
void InitQueue(Queue &Q)//��ʼ������
{
	Q.front = (QNode *)malloc(sizeof(QNode));
	Q.rear = (QNode *)malloc(sizeof(QNode));
	if (!Q.front)
	{
		printf("Fail Initializing\n");
		exit(0);
	}
	if (!Q.rear)
	{
		printf("Fail Initializing\n");
		exit(0);
	}
	Q.front->next = NULL;
}
int QueueEmpty(Queue Q)//�п�
{
	if (Q.front->next == NULL)
		return 1;
	else
		return 0;
}
void EnQueue(Queue &Q, BiTNode *x)//���
{
	QNode *a;
	a = (QNode *)malloc(sizeof(QNode));
	if (!a)
	{
		printf("Fail\n");
		exit(0);
	}
	a->data = x;
	a->next = NULL;
	Q.rear->next = a;
	Q.rear = a;
}
void DeQueue(Queue &Q, BiTNode **e)//����
{
	QNode *a;
	if (Q.front == Q.rear)
	{
		printf("Queue empty\n");
		exit(0);
	}
	else
	{
		a = Q.front->next;
		*e = a->data;
		Q.front->next = a->next;
		if (Q.rear == a)
			Q.rear = Q.front;
		free(a);
		a = NULL;
	}
}
void ClearQueue(Queue &Q)//���
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}
int Prepare()//���ļ��ж��뽨����Ϣ
{
	FILE  *fp;
	fp = fopen("example.txt", "r");
	if (NULL == fp) 
	{ 
		printf("File Open Error!\n"); 
		return 0; 
	}
	fscanf(fp, "%s\n", tree);
	fclose(fp);
	index = 0;
	return 1;
}
void InitBiTree(BiTree &T)//��ʼ��������
{
	char i;
	i = tree[index++];
	if (i == '#')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!(T))
			exit(0);
		(T)->data = i;
		InitBiTree(T->lchild);
		InitBiTree(T->rchild);
	}
}
void DestroyBiTree(BiTree &T)//���ٶ�����
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
void ClearBiTree(BiTree &T)//���
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
bool BiTreeEmpty(BiTree T)//�п�
{
	if (T == NULL)
		return true;
	else
		return false;
}
int BiTreeDepth(BiTree T)//����
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
bool Visit(BiTree T)
{
	cout << T->data << endl;
	return true;
}
void PreOrderTraverse(BiTree T)//����ݹ�
{
	if (T)
	{
		Visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void _PreOrderTraverse(BiTree T)//����ǵݹ�
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			Visit(p);
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
void InOrderTraverse(BiTree T)//����ݹ�
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		Visit(T);
		InOrderTraverse(T->rchild);
	}
}
void _InOrderTraverse(BiTree T)//����ǵݹ�
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			top++;
			stack[top] = p;
			p = p->lchild;
		}
		if (top > 0)
		{
			p = stack[top];
			Visit(p);
			top--;
			p = p->rchild;
		}
	}
}
void PostOrderTraverse(BiTree T)//����ݹ�
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T);
	}
}
void _PostOrderTraverse(BiTree T)//����ǵݹ�
{
	BiTree stack[100];
	int top = 0;
	BiTNode *p;
	BiTNode *q = NULL;
	top++;
	stack[top] = T;
	while (top > 0)
	{
		p = stack[top];
		if ((!p->lchild && !p->rchild) || (q && (q == p->lchild || q == p->rchild)))
		{
			Visit(p);
			top--;
			q = p;
		}
		else
		{
			if (p->rchild)
			{
				top++;
				stack[top] = p->rchild;
			}
			if (p->lchild)
			{
				top++;
				stack[top] = p->lchild;
			}
		}
	}
}
void LevelOrderTraverse(BiTree T)//���
{
	BiTree queue[100];
	BiTNode *p;
	int front = -1, rear = 0;
	queue[rear] = T;
	while (front != rear)
	{
		front = (front + 1) % 100;
		p = queue[front];
		Visit(p);
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
BiTree Root(BiTree T)//��������
{
	return T;
}
int Value(BiTree T, BiTree e)//���ڵ���ֵ
{
	int value = 0;
	if (!T)
		return 0;
	value = e->data;
	return value;
}
void Assign(BiTree T, BiTree &e, int value)//���ڵ㸳ֵ
{
	if (!T)
		exit(0);
	e->data = value;
}
BiTree Parent(BiTree T, BiTree e)//����˫��
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
BiTree LeftChild(BiTree T, BiTree e)//����
{
	if (!T)
		exit(0);
	if (!e->lchild)
		return NULL;
	return e->lchild;
}
BiTree RightChild(BiTree T, BiTree e)//�Һ���
{
	if (!T)
		exit(0);
	if (!e->rchild)
		return NULL;
	return e->rchild;
}
BiTree LeftSibling(BiTree T, BiTree e)//�����
{
	if (!T)
		exit(0);
	if (e == T->lchild)
		return NULL;
	BiTree Temp;
	Temp = Parent(T, e);
	return Temp->lchild;
}
BiTree RightSibling(BiTree T, BiTree e)//�ұ���
{
	if (!T)
		exit(0);
	if (e == T->rchild)
		return NULL;
	BiTree Temp;
	Temp = Parent(T, e);
	return Temp->rchild;
}
void InsertChild(BiTree &T, BiTree p, BiTree c)//���뺢�ӽڵ�
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
void DeleteChild(BiTree &T, BiTree p)//ɾ�����ӽڵ�
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
void Exchange(BiTree &T)//������������
{
	BiTree temp;
	if (T)
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		Exchange(T->lchild);
		Exchange(T->rchild);
	}
}
int Leave(BiTree T)//����Ҷ��
{
	if (!T)
		return 0;
	else
	{
		if (!T->lchild && !T->rchild)
			return 1;
		else
			return Leave(T->lchild) + Leave(T->rchild);
	}
}
void Complete(BiTree T)//�ж��Ƿ���ȫ
{
	int tag = 0;
	BiTree ptr = T;
	Queue Q;
	if (!ptr)
	{
		printf("Error\n");
		exit(0);
	}
	InitQueue(Q);
	EnQueue(Q, ptr);
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, &ptr);
		if (ptr->lchild && !tag)
			EnQueue(Q, ptr->lchild);
		else if (ptr->rchild)
		{
			printf("Not a complete tree\n");
			exit(0);
		}
		else
			tag = 1;
		if (ptr->rchild && !tag)
			EnQueue(Q, ptr->rchild);
		else if (ptr->rchild)
		{
			printf("Not a complete tree\n");
			exit(0);
		}
		else
			tag = 1;
	}
	ClearQueue(Q);
	printf("A complete tree\n");
}
int main()
{
	char i;
	BiTree T;
	Prepare();
	CreateBiTree(T);
	while (true)
	{
		cout << "0 to quit" << endl;
		cout << "1 to get depth" << endl;
		cout << "2 to exchange left and right" << endl;
		cout << "3 to get leave number" << endl;
		cout << "4 to judge if complete" << endl;
		cout << "5 to pre-order traverse" << endl;
		cout << "6 to in-order traverse" << endl;
		cout << "7 to post-order traverse" << endl;
		cout << "8 to level traverse" << endl;
		cout << "Input the order:";
		cin >> i;
		switch (i)
		{
		case'0':
			exit(0);
		case'1':
		{
			cout << BiTreeDepth(T) <<endl;
			break;
		}
		case'2':
		{
			Exchange(T);
			break;
		}
		case'3':
		{
			cout<< Leave(T) <<endl;
			break;
		}
		case'4':
		{
			Complete(T);
			break;
		}
		case'5':
		{
			cout << "Recursion:" << endl;
			PreOrderTraverse(T);
			cout << "Non-recursion:" << endl;
			_PreOrderTraverse(T);
			break;
		}
		case'6':
		{
			cout << "Recursion:" << endl;
			InOrderTraverse(T);
			cout << "Non-recursion:" << endl;
			_InOrderTraverse(T);
			break;
		}
		case'7':
		{
			cout << "Recursion:" << endl;
			PostOrderTraverse(T);
			cout << "Non-recursion:" << endl;
			_PostOrderTraverse(T);
			break;
		}
		case'8':
		{
			LevelOrderTraverse(T);
			break;
		}
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

