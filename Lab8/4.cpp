// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
int partition(int a[], int low, int high)
{
	int t, pivot;
	pivot = a[low];
	t = a[low];
	while (low < high)
	{
		while (low < high&&a[high] >= pivot)
			high--;
		if (low < high)
		{
			a[low] = a[high];
			low++;
		}
		while (low < high&&a[low] <= pivot)
			low++;
		if (low < high)
		{
			a[high] = a[low];
			high--;
		}
		a[low] = t;
	}
	return low;
}
void q_sort(int a[], int n, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(a, low, high);
		q_sort(a, n, low, pivot - 1);
		q_sort(a, n, pivot + 1, high);
	}
}
void quick_sort(int a[], int n)
{
	q_sort(a, n, 0, n - 1);
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
	quick_sort(a, n);
	display(a, n);
	system("pause");
    return 0;
}

