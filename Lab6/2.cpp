// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#define infinity 10000
typedef struct
{
	int weight;//权值
	int parent, lchild, rchild;//父节点，左右孩子节点
}HTNode, *HuffmanTree;
typedef char *HuffmanCode[100];
int Min(HuffmanTree t, int n)//求最小权值节点
{
	int i, flag, f = infinity;
	for (i = 1; i <= n; i++)
	{
		if (t[i].weight < f&&t[i].parent == 0)
		{
			f = t[i].weight;
			flag = i;
		}		
	}
	t[flag].parent = 1;
	return flag;
}
void Select(HuffmanTree *t, int n, int *s1, int *s2)//选择权值最小的两个节点
{
	int x;
	*s1 = Min(*t, n);
	*s2 = Min(*t, n);
	if ((*t)[*s1].weight > (*t)[*s2].weight)
	{
		x = *s1;
		*s1 = *s2;
		*s2 = x;
	}
}
void HuffmanCoding(HuffmanTree*HT, HuffmanCode *HC, int *w, int n)//构造哈夫曼树，编码存放在HC中
{
	int m, i, s1, s2, start, c, f;
	HuffmanTree p;
	char *cd;
	if (n <= 1)
		exit(0);
	m = 2 * n - 1;
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = *HT + 1, i = 1; i <= n; i++, p++, w++)//初始化叶子
	{
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; i++, p++)
		(*p).parent = 0;
	for (i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, &s1, &s2);
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)//从叶子节点到根节点求编码
		{
			if ((*HT)[f].lchild == c)
			{
				--start;
				cd[start] = '0';
			}
			else
			{
				--start;
				cd[start] = '1';
			}
		}
		(*HC)[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy((*HC)[i], &cd[start]);
	}
	free(cd);
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n, i;
	printf("Input number of leaf nodes:");
	scanf("%d", &n);
	w = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		printf("Input weight of node No.%d:", i + 1);
		scanf("%d", &w[i]);
	}
	HuffmanCoding(&HT, &HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("Code of No.%d:", w[i - 1]);
		printf("%s\n", HC[i]);
	}
	for (i = 1; i <= n; i++)
		free(HC[i]);
	free(HC);
	free(HT);
	system("pause");
    return 0;
}

