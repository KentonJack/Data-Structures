// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
using namespace std;
void exchange(int a[], int n)
{
	int i, j, temp, flag;
	for (i = 1; i < n; i++)
	{
		flag = 1;
		for (j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;
			}
			if (flag == 1)
				break;
		}
	}
}
void select(int a[], int n)
{
	int i, j, min, k, temp;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				k = j;
			}
		}
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}
void copy(int s[], int d[], int len, int start)
{
	int i, j = start;
	for (i = 0; i < len; i++, j++)
		d[j] = s[i];
}
void merge(int a[], int l, int r)
{
	int b1, b2, mid, len, k = 0, *b;
	b1 = l;
	mid = (l + r) / 2;
	b2 = mid + 1;
	len = r - l + 1;
	b = (int *)malloc(len * sizeof(int));
	while (b1 <= mid&&b2 <= r)
	{
		if (a[b1] <= a[b2])
			b[k++] = a[b1++];
		else
			b[k++] = a[b2++];
	}
	while (b1 <= mid)
		b[k++] = a[b1++];
	while (b2 <= r)
		b[k++] = a[b2++];
	copy(b, a, len, l);
	free(b);
}
void merge_sort(int a[], int l, int r)
{
	int i;
	if (l < r)
	{
		i = (l + r) / 2;
		merge_sort(a, l, i);
		merge_sort(a, i + 1, r);
		merge(a, l, r);
	}
}
void create(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Input No." << i + 1 << ":";
		cin >> a[i];
	}
}
void display(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "The sorted array No." << i + 1 << ":";
		cout << a[i] << endl;
	}
}
int main()
{
	int a[100];
	int i, n, num;
	cout << "Input the length of the array:";
	cin >> n;
	create(a, n);
	cout << "1 for exchange, 2 for select, 3 for merge" << endl;
	cout << "Input i to choose the way:";
	cin >> i;
	switch (i)
	{
		case 1:
		{
			exchange(a, n);
			break;
		}
		case 2:
		{
			select(a, n);
			break;
		}
		case 3:
		{
			merge_sort(a, 0, n - 1);
			break;
		}
		default:
		{
			break;
		}
	}
	display(a, n);
	system("pause");
}

