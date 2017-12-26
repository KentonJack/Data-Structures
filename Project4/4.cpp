// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct
{
	int size;//麦田个数
	int vertex[20];//数组表示图的点
	float arc[20][20];//二维数组表示一条边的权值
}matrix;
int main()
{
	char s[20][20] = {};
	int min[20];
	matrix x;
	int num, arc;
	float sum;
	int i, j, k, l, m, n = 0, d, flag;
	int a[20], b[20], c[20];
	printf("Input vertex and arc number:\n");
	scanf_s("%d %d", &num, &arc);
	x.size = num;
	for (i = 0; i < 20; i++)//矩阵信息初始化
		x.vertex[i] = -1;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
			x.arc[i][j] = 10000;
	}
	printf("Input the info:\n");
	for (i = 0; i < arc; i++)
	{
		scanf_s("%d %d %d", &a[i], &b[i], &c[i]);
	}
	i = 0;
	while (i < x.size)//建立图的邻接矩阵
	{
		j = 0;
		while (j < x.size)
		{
			x.arc[a[i] - 1][b[i] - 1] = c[i];
			x.arc[b[i] - 1][a[i] - 1] = c[i];
			j++;
		}
		printf("\n");
		i++;
	}
	while (n < x.size)//依次以图的各个顶点为起点求出最短距离
	{
		sum = 0;
		j = 0;
		while (j <= x.size)
		{
			x.vertex[j] = -1;
			j++;
		}
		x.vertex[0] = n;
		i = 1;
		while (i < x.size)
		{
			k = 0;
			d = 10000;
			while (k < x.size)
			{
				l = 0;
				flag = 0;
				while (l < i)
				{
					if (x.vertex[l] == k)
					{
						flag = 1;
						break;
					}
					l++;
				}
				if (x.arc[k][int(x.vertex[i - 1])] < d && flag == 0)//加入距离最近的一条边
				{
					j = k;
					d = x.arc[k][int(x.vertex[i - 1])];
				}
				k++;
			}
			x.vertex[i] = j;
			sum += d;
			i++;
		}
		sum = sum + x.arc[n][j];
		m = 0;
		sum -= 10000;
		min[n] = sum;
		while (m < x.size)
		{
			s[n][m] = x.vertex[m] + 1 + '0';
			m++;
		}
		n++;
	}
	flag = 0;
	int minimum = min[0];
	for (i = 1; i < n; i++)//比较各个顶点出发的通路长度选择最优解
	{
		if (min[i] < minimum)
		{
			flag = i;
		}
	}
	printf("%d\n", min[flag]);
	printf("Path:%s\n", s[flag]);
	system("pause");
	return 0;
}


