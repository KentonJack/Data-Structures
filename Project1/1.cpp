// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct Good
{
	char name[20];//商品名称
	int price;//商品价格
	int sell;//商品销量
}Good;
typedef struct LNode
{
	int max;//所有店铺数量
	int number;//店铺编号
	char name[20];//店铺名称
	int trust;//店铺信誉
	int gnum;//店铺商品数量
	Good g[6];//店铺商品，静态数组存储
	struct LNode *next;//单向链表next指针
}LNode, *LinkList;
typedef struct DNode
{
	int max;//所有店铺数量
	int number;//店铺编号
	char name[20];//店铺名称
	int trust;//店铺信誉
	int gnum;//店铺商品数量
	Good g[6];//店铺商品，静态数组存储
	struct DNode *prior;//双向循环链表prior指针
	struct DNode *next;//双向循环链表next指针
}DListNode, *DLinkList;
void CreateList(LinkList &L, char filename[])
{
	int gnum;
	int number;
	int trust;
	int price;
	int price2;
	int price3;
	int price4;
	int price5;
	int price6;
	int sell;
	int sell2;
	int sell3;
	int sell4;
	int sell5;
	int sell6;
	char name[20] = " ";
	char gname[20] = " ";
	char gname2[20] = " ";
	char gname3[20] = " ";
	char gname4[20] = " ";
	char gname5[20] = " ";
	char gname6[20] = " ";
	FILE *fp;
	LNode *p;
	LNode *q;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("File Open Error!\n");
		exit(0);
	}
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	q = L;
	L->max = 0;
	L->gnum = 1;
	while (!feof(fp))//读取文件信息建立单向链表
	{
		fscanf(fp, "%d ", &gnum);
		p = (LNode*)malloc(sizeof(LNode));
		p->gnum = gnum;
		if (p->gnum == 1)
		{
			fscanf(fp, "%d %s %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			L->max++;
			q->next = p;
			q = p;
		}
		else if (p->gnum == 2)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			strcpy(p->g[1].name, gname2);
			p->g[1].price = price2;
			p->g[1].sell = sell2;
			L->max++;
			q->next = p;
			q = p;
		}
		else if (p->gnum == 3)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			strcpy(p->g[1].name, gname2);
			p->g[1].price = price2;
			p->g[1].sell = sell2;
			strcpy(p->g[2].name, gname3);
			p->g[2].price = price3;
			p->g[2].sell = sell3;
			L->max++;
			q->next = p;
			q = p;
		}
		else if (p->gnum == 4)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			strcpy(p->g[1].name, gname2);
			p->g[1].price = price2;
			p->g[1].sell = sell2;
			strcpy(p->g[2].name, gname3);
			p->g[2].price = price3;
			p->g[2].sell = sell3;
			strcpy(p->g[3].name, gname4);
			p->g[3].price = price4;
			p->g[3].sell = sell4;
			L->max++;
			q->next = p;
			q = p;
		}
		else if (p->gnum == 5)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4, &gname5, &price5, &sell5);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			strcpy(p->g[1].name, gname2);
			p->g[1].price = price2;
			p->g[1].sell = sell2;
			strcpy(p->g[2].name, gname3);
			p->g[2].price = price3;
			p->g[2].sell = sell3;
			strcpy(p->g[3].name, gname4);
			p->g[3].price = price4;
			p->g[3].sell = sell4;
			strcpy(p->g[4].name, gname5);
			p->g[4].price = price5;
			p->g[4].sell = sell5;
			L->max++;
			q->next = p;
			q = p;
		}
		else if (p->gnum == 6)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4, &gname5, &price5, &sell5, &gname6, &price6, &sell6);
			p->number = number;
			p->trust = trust;
			strcpy(p->name, name);
			strcpy(p->g[0].name, gname);
			p->g[0].price = price;
			p->g[0].sell = sell;
			strcpy(p->g[1].name, gname2);
			p->g[1].price = price2;
			p->g[1].sell = sell2;
			strcpy(p->g[2].name, gname3);
			p->g[2].price = price3;
			p->g[2].sell = sell3;
			strcpy(p->g[3].name, gname4);
			p->g[3].price = price4;
			p->g[3].sell = sell4;
			strcpy(p->g[4].name, gname5);
			p->g[4].price = price5;
			p->g[4].sell = sell5;
			strcpy(p->g[5].name, gname6);
			p->g[5].price = price6;
			p->g[5].sell = sell6;
			L->max++;
			q->next = p;
			q = p;
		}
		else
		{
			printf("Error\n");
			exit(0);
		}
	}
	q->next = NULL;
	fclose(fp);
}
void Show(LinkList L)
{
	LNode *p;
	if (L == NULL)
		exit(0);
	p = L->next;
	while (p)//根据商品种数显示商铺信息
	{
		if (p->gnum == 1)
		{
			printf("Shop: %d %s %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
			p = p->next;
		}
		else if (p->gnum == 2)
		{
			printf("Shop: %d %s %d %s %d %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
			p = p->next;
		}
		else if (p->gnum == 3)
		{
			printf("Shop: %d %s %d %s %d %d %s %d %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
			p = p->next;
		}
		else if (p->gnum == 4)
		{
			printf("Shop: %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
			p = p->next;
		}
		else if (p->gnum == 5)
		{
			printf("Shop: %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
			p = p->next;
		}
		else if (p->gnum == 6)
		{
			printf("Shop: %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
			p = p->next;
		}
		else
		{
			printf("Error\n");
			exit(0);
		}
	}
	printf("\n");
}
void CreateDList(DLinkList &D, char filename[])
{
	int gnum;
	int number;
	int trust;
	int price;
	int price2;
	int price3;
	int price4;
	int price5;
	int price6;
	int sell;
	int sell2;
	int sell3;
	int sell4;
	int sell5;
	int sell6;
	char name[20] = " ";
	char gname[20] = " ";
	char gname2[20] = " ";
	char gname3[20] = " ";
	char gname4[20] = " ";
	char gname5[20] = " ";
	char gname6[20] = " ";
	DListNode *p;
	DListNode *q;
	FILE *fp;
	char find[20] = " ";
	cout << "Input the good name:";
	cin >> find;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("File Open Error!\n");
		exit(0);
	}
	D = (DLinkList)malloc(sizeof(DListNode));
	if (!D)
	{
		printf("Error\n");
		exit(0);
	}
	D->next = D;
	D->prior = D;
	q = D;
	D->max = 0;
	D->gnum = 1;
	while (!feof(fp))//读取文件信息建立双向循环链表
	{
		fscanf(fp, "%d ", &gnum);
		p = (DListNode*)malloc(sizeof(DListNode));
		p->gnum = gnum;
		if (p->gnum == 1)
		{
			fscanf(fp, "%d %s %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell);
			if (strcmp(gname,find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else if (p->gnum == 2)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2);
			if (strcmp(gname, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname2, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname2);
				p->g[0].price = price2;
				p->g[0].sell = sell2;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else if (p->gnum == 3)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3);
			if (strcmp(gname, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname2, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname2);
				p->g[0].price = price2;
				p->g[0].sell = sell2;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname3, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname3);
				p->g[0].price = price3;
				p->g[0].sell = sell3;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else if (p->gnum == 4)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4);
			if (strcmp(gname, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname2, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname2);
				p->g[0].price = price2;
				p->g[0].sell = sell2;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname3, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname3);
				p->g[0].price = price3;
				p->g[0].sell = sell3;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname4, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname4);
				p->g[0].price = price4;
				p->g[0].sell = sell4;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else if (p->gnum == 5)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4, &gname5, &price5, &sell5);
			if (strcmp(gname, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname2, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname2);
				p->g[0].price = price2;
				p->g[0].sell = sell2;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname3, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname3);
				p->g[0].price = price3;
				p->g[0].sell = sell3;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname4, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname4);
				p->g[0].price = price4;
				p->g[0].sell = sell4;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname5, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname5);
				p->g[0].price = price5;
				p->g[0].sell = sell5;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else if (p->gnum == 6)
		{
			fscanf(fp, "%d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", &number, &name, &trust, &gname, &price, &sell, &gname2, &price2, &sell2, &gname3, &price3, &sell3, &gname4, &price4, &sell4, &gname5, &price5, &sell5, &gname6, &price6, &sell6);
			if (strcmp(gname, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname);
				p->g[0].price = price;
				p->g[0].sell = sell;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname2, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname2);
				p->g[0].price = price2;
				p->g[0].sell = sell2;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname3, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname3);
				p->g[0].price = price3;
				p->g[0].sell = sell3;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname4, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname4);
				p->g[0].price = price4;
				p->g[0].sell = sell4;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname5, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname5);
				p->g[0].price = price5;
				p->g[0].sell = sell5;
				D->max++;
				q->next = p;
				q = p;
			}
			else if (strcmp(gname6, find) == 0)
			{
				p->number = number;
				p->trust = trust;
				strcpy(p->name, name);
				strcpy(p->g[0].name, gname6);
				p->g[0].price = price6;
				p->g[0].sell = sell6;
				D->max++;
				q->next = p;
				q = p;
			}
			else
			{
				continue;
			}
		}
		else
		{
			printf("Error\n");
			exit(0);
		}
	}
	q->next = NULL;
	fclose(fp);
}
void DShow(DLinkList D)
{
	DLinkList D1, D2, D3;
	for (D3 = D, D2 = D->next; D2 != NULL;)
	{
		D1 = D;
		for (; D1 != D2; D1 = D1->next)//链表插入排序
		{
			if (D1->next->g[0].sell < D2->g[0].sell)
			{
				D3->next = D2->next;
				D2->next = D1->next;
				D1->next = D2;
				D2 = D3->next;
				break;
			}
		}
		if (D1 == D2)
		{
			D2 = D2->next;
			D3 = D3->next;
		}
	}
	D1 = D->next;
	while (D1 != NULL)
	{
		printf("Shop: %d %s %d %s %d %d\n", D1->number, D1->name, D1->trust, D1->g[0].name, D1->g[0].price, D1->g[0].sell);
		D1 = D1->next;
	}
}
void AddShop(LinkList &L, char filename[])//增加商铺
{
	L->max++;
	int trust;
	int price;
	int price2;
	int price3;
	int price4;
	int price5;
	int price6;
	int sell;
	int sell2;
	int sell3;
	int sell4;
	int sell5;
	int sell6;
	int gnum;
	char name[20] = " ";
	char gname[20] = " ";
	char gname2[20] = " ";
	char gname3[20] = " ";
	char gname4[20] = " ";
	char gname5[20] = " ";
	char gname6[20] = " ";
	FILE *fp;
	LNode *p, *q;
	fp = fopen(filename, "a");
	if (fp == NULL)
	{
		printf("File Open Error!\n");
		exit(0);
	}
	q = L;
	cout << "Input the good number:";
	cin >> gnum;
	cout << "Input the shop name:";
	cin >> name;
	cout << "Input the shop trust:";
	cin >> trust;
	if (gnum == 1)//根据商品种数写入修改后的信息
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		fprintf(fp, "\n%d %d %s %d %s %d %d", gnum, L->max, name, trust, gname, price, sell);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
	}
	else if (gnum == 2)
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		cout << "Input the good name:";
		cin >> gname2;
		cout << "Input the price:";
		cin >> price2;
		cout << "Input the sell number:";
		cin >> sell2;
		fprintf(fp, "\n%d %d %s %d %s %d %d %s %d %d", gnum, L->max, name, trust, gname, price, sell, gname2, price2, sell2);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
		strcpy(p->g[1].name, gname2);
		p->g[1].price = price2;
		p->g[1].sell = sell2;
	}
	else if (gnum == 3)
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		cout << "Input the good name:";
		cin >> gname2;
		cout << "Input the price:";
		cin >> price2;
		cout << "Input the sell number:";
		cin >> sell2;
		cout << "Input the good name:";
		cin >> gname3;
		cout << "Input the price:";
		cin >> price3;
		cout << "Input the sell number:";
		cin >> sell3;
		fprintf(fp, "\n%d %d %s %d %s %d %d %s %d %d %s %d %d", gnum, L->max, name, trust, gname, price, sell, gname2, price2, sell2, gname3, price3, sell3);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
		strcpy(p->g[1].name, gname2);
		p->g[1].price = price2;
		p->g[1].sell = sell2;
		strcpy(p->g[2].name, gname3);
		p->g[2].price = price3;
		p->g[2].sell = sell3;
	}
	else if (gnum == 4)
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		cout << "Input the good name:";
		cin >> gname2;
		cout << "Input the price:";
		cin >> price2;
		cout << "Input the sell number:";
		cin >> sell2;
		cout << "Input the good name:";
		cin >> gname3;
		cout << "Input the price:";
		cin >> price3;
		cout << "Input the sell number:";
		cin >> sell3;
		cout << "Input the good name:";
		cin >> gname4;
		cout << "Input the price:";
		cin >> price4;
		cout << "Input the sell number:";
		cin >> sell4;
		fprintf(fp, "\n%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", gnum, L->max, name, trust, gname, price, sell, gname2, price2, sell2, gname3, price3, sell3, gname4, price4, sell4);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
		strcpy(p->g[1].name, gname2);
		p->g[1].price = price2;
		p->g[1].sell = sell2;
		strcpy(p->g[2].name, gname3);
		p->g[2].price = price3;
		p->g[2].sell = sell3;
		strcpy(p->g[3].name, gname4);
		p->g[3].price = price4;
		p->g[3].sell = sell4;
	}
	else if (gnum == 5)
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		cout << "Input the good name:";
		cin >> gname2;
		cout << "Input the price:";
		cin >> price2;
		cout << "Input the sell number:";
		cin >> sell2;
		cout << "Input the good name:";
		cin >> gname3;
		cout << "Input the price:";
		cin >> price3;
		cout << "Input the sell number:";
		cin >> sell3;
		cout << "Input the good name:";
		cin >> gname4;
		cout << "Input the price:";
		cin >> price4;
		cout << "Input the sell number:";
		cin >> sell4;
		cout << "Input the good name:";
		cin >> gname5;
		cout << "Input the price:";
		cin >> price5;
		cout << "Input the sell number:";
		cin >> sell5;
		fprintf(fp, "\n%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", gnum, L->max, name, trust, gname, price, sell, gname2, price2, sell2, gname3, price3, sell3, gname4, price4, sell4, gname5, price5, sell5);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
		strcpy(p->g[1].name, gname2);
		p->g[1].price = price2;
		p->g[1].sell = sell2;
		strcpy(p->g[2].name, gname3);
		p->g[2].price = price3;
		p->g[2].sell = sell3;
		strcpy(p->g[3].name, gname4);
		p->g[3].price = price4;
		p->g[3].sell = sell4;
		strcpy(p->g[4].name, gname5);
		p->g[4].price = price5;
		p->g[4].sell = sell5;
	}
	else if (gnum == 6)
	{
		cout << "Input the good name:";
		cin >> gname;
		cout << "Input the price:";
		cin >> price;
		cout << "Input the sell number:";
		cin >> sell;
		cout << "Input the good name:";
		cin >> gname2;
		cout << "Input the price:";
		cin >> price2;
		cout << "Input the sell number:";
		cin >> sell2;
		cout << "Input the good name:";
		cin >> gname3;
		cout << "Input the price:";
		cin >> price3;
		cout << "Input the sell number:";
		cin >> sell3;
		cout << "Input the good name:";
		cin >> gname4;
		cout << "Input the price:";
		cin >> price4;
		cout << "Input the sell number:";
		cin >> sell4;
		cout << "Input the good name:";
		cin >> gname5;
		cout << "Input the price:";
		cin >> price5;
		cout << "Input the sell number:";
		cin >> sell5;
		cout << "Input the good name:";
		cin >> gname6;
		cout << "Input the price:";
		cin >> price6;
		cout << "Input the sell number:";
		cin >> sell6;
		fprintf(fp, "\n%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", gnum, L->max, name, trust, gname, price, sell, gname2, price2, sell2, gname3, price3, sell3, gname4, price4, sell4, gname5, price5, sell5, gname6, price6, sell6);
		p = (LNode*)malloc(sizeof(LNode));
		p->number = L->max;
		p->gnum = gnum;
		p->trust = trust;
		strcpy(p->name, name);
		strcpy(p->g[0].name, gname);
		p->g[0].price = price;
		p->g[0].sell = sell;
		strcpy(p->g[1].name, gname2);
		p->g[1].price = price2;
		p->g[1].sell = sell2;
		strcpy(p->g[2].name, gname3);
		p->g[2].price = price3;
		p->g[2].sell = sell3;
		strcpy(p->g[3].name, gname4);
		p->g[3].price = price4;
		p->g[3].sell = sell4;
		strcpy(p->g[4].name, gname5);
		p->g[4].price = price5;
		p->g[4].sell = sell5;
		strcpy(p->g[5].name, gname6);
		p->g[5].price = price6;
		p->g[5].sell = sell6;
	}
	else
	{
		printf("Error\n");
		exit(0);
	}
	q->next = p;
	q = p;
	q->next = NULL;
	free(q);
	q = NULL;
	fclose(fp);
}
void DeleteShop(LinkList &L, char filename[])//删除商铺
{
	int in;
	LNode *p, *q ,*r;
	cout << "Input the shop number:";
	cin >> in;
	p = L;
	q = NULL;
	if (!p)
	{
		printf("Error\n");
		exit(0);
	}
	while (p)
	{
		q = p;
		q = q->next;
		if (q->number == in)//删除链表节点
		{
			r = q->next;
			while (r)
			{
				r->number--;
				r = r->next;
			}
			p->next = q->next;
			free(q);
			L->max--;
			break;
		}
		p = p->next;
	}
	p = L->next;
	FILE *fp;
	fp = fopen(filename, "w");
	while (p)//写入修改后的信息
	{
		if (p->next)
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
	}
}
void AddGood(LinkList &L, char filename[])//增加商品
{
	LNode *p;
	int in;
	int i;
	int price = 0;
	int sell = 0;
	char gname[20] = " ";
	cout << "Input the shop number:";
	cin >> in;
	cout << "Input the good name:";
	cin >> gname;
	cout << "Input the price:";
	cin >> price;
	cout << "Input the sell number:";
	cin >> sell;
	p = L->next;
	for (i = 1; i < L->max; i++)//搜索要增加商品的店铺
	{
		if (p->number == in)
		{
			if (p->gnum == 6)//判断是否商品种数达到上限
			{
				printf("Maximum good number");
				exit(0);
			}
			p->gnum++;//增加商品
			strcpy(p->g[p->gnum-1].name, gname);
			p->g[p->gnum-1].price = price;
			p->g[p->gnum-1].sell = sell;
			break;
		}
		p = p->next;
	}
	p = L->next;
	FILE *fp;
	fp = fopen(filename, "w");
	while (p)//写入修改后的信息
	{
		if (p->next)
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
	}
}
void DeleteGood(LinkList &L, char filename[])//删除商品
{
	LNode *p;
	int in;
	int i;
	int j;
	int flag;
	char gname[20];
	cout << "Input the shop number:";
	cin >> in;
	cout << "Input the good name:";
	cin >> gname;
	p = L->next;
	for (i = 0; i < L->max; i++)//搜索商铺商品
	{
		if (p->number == in)
		{
			for (j = 0; j < p->gnum; j++)
			{
				if (strcmp(gname, p->g[j].name) == 0)
				{
					if (p->gnum == 1)//判断是否商品只有1种
					{
						printf("Minimum good");
						exit(0);
					}
					flag = j;
					for (j = flag; j < p->gnum; j++)//将选定的商品信息覆盖
					{
						p->g[j] = p->g[j + 1];
					}
					p->gnum--;
					break;
				}
			}
			break;
		}
		p = p->next;
	}
	p = L->next;
	FILE *fp;
	fp = fopen(filename, "w");
	while (p)//写入修改后的信息
	{
		if (p->next)
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
	}
}
void ChangePrice(LinkList &L, char filename[])//修改价格
{
	LNode *p;
	int in;
	int i;
	int j;
	int price;
	char name[20] = " ";
	cout << "Input the shop number:";
	cin >> in;
	cout << "Input the good name:";
	cin >> name;
	cout << "Input the price:";
	cin >> price;
	p = L;
	for (i = 1; i < L->max; i++)//搜索要改的商铺商品价格
	{
		if (p->number == in)
		{
			for (j = 0; j < p->gnum; j++)
			{
				if (strcmp(name, p->g[j].name) == 0)
				{
					p->g[j].price = price;
					break;
				}
			}
			break;
		}
		p = p->next;
	}
	p = L->next;
	FILE *fp;
	fp = fopen(filename, "w");
	while (p)//写入修改后的信息
	{
		if (p->next)
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
	}
}
void Buy(LinkList &L, char filename[])//购买商品
{
	int in;
	int i;
	int j;
	char gname[20];
	LinkList p;
	cout << "Input the shop number:";
	cin >> in;
	cout << "Input the good name:";
	cin >> gname;
	p = L->next;
	for (i = 1; i <= L->max; i++)//搜索要买的商铺商品
	{
		if (p->number == in)
		{
			for (j = 0; j < p->gnum; j++)
			{
				if (strcmp(p->g[j].name, gname) == 0)
				{
					p->g[j].sell++;
					break;
				}
			}
			break;
		}
		p = p->next;
	}
	p = L->next;
	FILE *fp;
	fp = fopen(filename, "w");
	while (p)//写入修改后的链表信息
	{
		if (p->next)
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d\n", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (p->gnum == 1)
			{
				fprintf(fp, "%d %d %s %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell);
				p = p->next;
			}
			else if (p->gnum == 2)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell);
				p = p->next;
			}
			else if (p->gnum == 3)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell);
				p = p->next;
			}
			else if (p->gnum == 4)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell);
				p = p->next;
			}
			else if (p->gnum == 5)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell);
				p = p->next;
			}
			else if (p->gnum == 6)
			{
				fprintf(fp, "%d %d %s %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d %s %d %d", p->gnum, p->number, p->name, p->trust, p->g[0].name, p->g[0].price, p->g[0].sell, p->g[1].name, p->g[1].price, p->g[1].sell, p->g[2].name, p->g[2].price, p->g[2].sell, p->g[3].name, p->g[3].price, p->g[3].sell, p->g[4].name, p->g[4].price, p->g[4].sell, p->g[5].name, p->g[5].price, p->g[5].sell);
				p = p->next;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
	}
}
void DestroyList(LinkList &L)//销毁链表
{
	free(L);
	L = NULL;
}
void DestroyDList(DLinkList &D)//销毁双向链表
{
	free(D);
	D = NULL;
}
int main()
{
	char i;
	LinkList L;
	CreateList(L, "example.txt");//首次使用创建商铺信息链表
	DLinkList D;
	while (true)
	{
		cout << "0 to quit" << endl;
		cout << "1 to add shop" << endl;
		cout << "2 to delete shop" << endl;
		cout << "3 to add good" << endl;
		cout << "4 to delete good" << endl;
		cout << "5 to change price" << endl;
		cout << "6 to buy" << endl;
		cout << "7 to search" << endl;
		cout << "8 to show" << endl;
		cout << "9 to recreate the list" << endl;
		cout << "Input the order:";
		cin >> i;
		switch (i)
		{
			case'0':
				exit(0);
			case'1':
			{
				AddShop(L, "example.txt");
				break;
			}
			case'2':
			{
				DeleteShop(L, "example.txt");
				break;
			}
			case'3':
			{
				AddGood(L, "example.txt");
				break;
			}
			case'4':
			{
				DeleteGood(L, "example.txt");
				break;
			}
			case'5':
			{
				ChangePrice(L, "example.txt");
				break;
			}
			case'6':
			{
				Buy(L, "example.txt");
				break;
			}
			case'7':
			{
				CreateDList(D, "example.txt");
				DShow(D);
				break;
			}
			case'8':
			{
				Show(L);
				break;
			}
			case'9':
			{
				CreateList(L, "example.txt");
				break;
			}
			default:
				break;
		}
	}
	DestroyList(L);
	DestroyDList(D);
	system("pause");
	return 0;
}
