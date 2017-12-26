// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#define MAXSIZE 12500
typedef struct
{
	int i, j;
	int e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;
void CreateSMatrix(TSMatrix* M)
{
	int mu, nu, tu, i, row, col, temp;
	printf("Input mu:");
	scanf("%d", &mu);
	printf("Input nu:");
	scanf("%d", &nu);
	printf("Input tu:");
	scanf("%d", &tu);
	if (mu<1 || nu <1 || tu<1 || tu> mu*nu)
		exit(1);
	M->mu = mu;
	M->nu = nu;
	M->tu = tu;
}
void TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	int p, q, col;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		q = 1;
		for (col = 1; col <= M.nu; ++col)
		{
			for (p = 1; p <= M.tu; ++p)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
}
void FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	int num[500], cpot[500];
	int t, p, q, col;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		for (col = 1; col <= M.nu; ++col)
			num[col] = 0;
		for (t = 1; t <= M.tu; ++t)
			++num[M.data[t].j];
		cpot[1] = 1;
		for (col = 2; col <= M.nu; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (p = 1; p <= M.tu; ++p)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			++cpot[col];
		}
	}
}
int main()
{
	TSMatrix M, T;
	CreateSMatrix(&M);
	CreateSMatrix(&T);
	TransposeSMatrix(M, T);
	FastTransposeSMatrix(M, T);
	system("pause");
    return 0;
}

