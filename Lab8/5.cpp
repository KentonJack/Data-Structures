// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
void adjust_heap(int a[], int s, int m)
{
	int i, t;
	t = a[s];
	for (i = 2 * s + 1; i <= m; i *= 2 + 1)
	{
		if (i < m&&a[i] < a[i + 1])
			i++;
		if (t > a[i])
			break;
		a[s] = a[i];
		s = i;
	}
	a[s] = t;
}
void create_heap(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		adjust_heap(a, i, n - 1);
}
void heap_sort(int a[], int n)
{
	int i, t;
	create_heap(a, n);
	for (i = n - 1; i > 0; i--)
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust_heap(a, 0, i - 1);
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
	heap_sort(a, n);
	display(a, n);
	system("pause");
    return 0;
}

