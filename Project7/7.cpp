// 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"
using namespace std;
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNode, HT[200];
typedef struct
{
	int weight;
	char a;
	int length;
}WNode, WN[100];
void leaf(char ch[], WN l, int s, int p)
{
	int i;
	int j;
	int k;
	int tag;
	p = 0;
	for (i = 0; ch[i] != '\0'; i++)
	{
		tag = 1;
		for (j = 0; j < i; j++)
		{
			if (ch[i] == ch[j])
			{
				tag = 0;
				break;
			}
		}
		if (tag)
		{
			p++;
			l[p].a = ch[i];
			l[p].weight = 1;
			for (k = i + 1; ch[k] != '\0'; k++)
			{
				if (ch[i] == ch[k])
					l[p].weight++;
			}
		}
	}
	s = i;
}
void Tree(HT h, WN l, int n)
{
	int i;
	int j;
	int s1;
	int s2;
	for (i = 1; i <= n; i++)
	{
		h[i].weight = l[i].weight;
		h[i].parent = 0;
		h[i].lchild = 0;
		h[i].rchild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		h[i].weight = 0;
		h[i].parent = 0;
		h[i].lchild = 0;
		h[i].rchild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			if (!h[j].parent)
				break;
		}
		s1 = j;
		for (; j <= i - 1; j++)
		{
			if (!h[j].parent && (h[s1].weight > h[j].weight))
					s1 = j;
		}
		h[s1].parent = i;
		h[i].lchild = s1;
		for (j = 1; j <= i - 1; j++)
		{
			if (!h[j].parent)
				break;
		}
		s2 = j;
		for (; j <= i - 1; j++)
		{
			if (!h[j].parent && (h[s2].weight > h[j].weight))
				s2 = j;
		}
		h[s2].parent = i;
		h[i].rchild = s2;
		h[i].weight = h[s1].weight + h[s2].weight;
	}
}
int main()
{
	system("pause");
    return 0;
}

