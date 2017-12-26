// 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
#include "time.h"
using namespace std;
void insert(int a[], int n)//直接插入排序
{
	int x = clock();
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void shell_insert(int a[], int n, int add)//希尔插入操作
{
	int i, j, temp;
	for (i = add; i < n; i++)
	{
		if (a[i] < a[i - add])
		{
			temp = a[i];
			for (j = i - add; j >= 0 && temp < a[j]; j = j - add)
				a[j + add] = a[j];
			a[j + add] = temp;
		}
	}
}
void shell_sort(int a[], int n, int b[], int m)//希尔排序
{
	int x = clock();
	int i;
	for (i = 0; i < m; i++)
		shell_insert(a, n, b[i]);
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void exchange(int a[], int n)//冒泡排序
{
	int x = clock();
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
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void select(int a[], int n)//简单选择排序
{
	int x = clock();
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
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void _merge_array(int* a1, int len1, int* a2, int len2)
{
	int* list = (int*)malloc((len1 + len2) * sizeof(int));
	int i = 0, j = 0, k = 0;
	while (i < len1 && j < len2)
		list[k++] = (a1[i] < a2[j]) ? a1[i++] : a2[j++];
	while (i < len1)
		list[k++] = a1[i++];
	while (j < len2)
		list[k++] = a2[j++];
	for (i = 0; i < k; i++)
		a1[i] = list[i];
	free(list);
}
void _merge_sort(int a[], int len)
{
	int x = clock();
	if (len > 1)
	{
		int* a1 = a;
		int len1 = len / 2;
		int* a2 = a + len / 2;
		int len2 = len - len1;
		_merge_sort(a1, len1);
		_merge_sort(a2, len2);
		_merge_array(a1, len1, a2, len2);
	}
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void copy(int s[], int d[], int len, int start)//数组复制
{
	int i, j = start;
	for (i = 0; i < len; i++, j++)
		d[j] = s[i];
}
void merge(int a[], int l, int r)//归并操作
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
void merge_sort(int a[], int l, int r)//归并排序
{
	int x = clock();
	int i;
	if (l < r)
	{
		i = (l + r) / 2;
		merge_sort(a, l, i);
		merge_sort(a, i + 1, r);
		merge(a, l, r);
	}
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void create(int a[], int n)//创建数组
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Input No." << i + 1 << ":";
		cin >> a[i];
	}
}
void display(int a[], int n)//显示排序完成的数据
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "The sorted array No." << i + 1 << ":";
		cout << a[i] << endl;
	}
}
int partition(int a[], int low, int high)//调整数组使选定元素前的数据都小于它，后面的数据都大于它
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
void q_sort(int a[], int n, int low, int high)//递归对数组中的元素排序
{
	int pivot;
	if (low < high)
	{
		pivot = partition(a, low, high);
		q_sort(a, n, low, pivot - 1);
		q_sort(a, n, pivot + 1, high);
	}
}
void quick_sort(int a[], int n)//快速排序
{
	int x = clock();
	q_sort(a, n, 0, n - 1);
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
void adjust_heap(int a[], int s, int m)//调整堆
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
void create_heap(int a[], int n)//创建堆
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		adjust_heap(a, i, n - 1);
}
void heap_sort(int a[], int n)//堆排序
{
	int x = clock();
	int i, t;
	create_heap(a, n);
	for (i = n - 1; i > 0; i--)
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust_heap(a, 0, i - 1);
	}
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
int maxbit(int a[], int n)//求数据的位数
{
	int d = 1;
	int p = 10;
	int i;
	for (i = 0; i < n; ++i)
	{
		while (a[i] >= p)
		{
			p *= 10;
			d++;
		}
	}
	return d;
}
void radixsort(int a[], int n)//基数排序
{
	int x = clock();
	int d = maxbit(a, n);
	int *tmp = new int[n];
	int *count = new int[10];
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];
		for (j = n - 1; j >= 0; j--)
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < n; j++)
			a[j] = tmp[j];
		radix = radix * 10;
	}
	delete [] tmp;
	delete [] count;
	int y = clock();
	int z = y - x;
	printf("Time is %d ms\n", z);
}
int* Input(int exp[])//读取文件创建数组
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_2(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example2.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_3(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example3.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_4(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example4.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_5(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example5.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_6(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example6.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_7(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example7.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int* Input_8(int exp[])
{
	FILE *ptr;
	int i = 0;
	ptr = fopen("example8.txt", "r");
	if (!ptr)
	{
		printf("Error opening file\n");
		exit(0);
	}
	while (!feof(ptr))
	{
		fscanf(ptr, "%d\n", &exp[i]);
		i++;
	}
	return exp;
}
int main()
{
	char i;
	char j;
	int exp[20000];
	cout << "1 for example1" << endl;
	cout << "2 for example2" << endl;
	cout << "3 for example3" << endl;
	cout << "4 for example4" << endl;
	cout << "5 for example5" << endl;
	cout << "6 for example6" << endl;
	cout << "7 for example7" << endl;
	cout << "8 for example8" << endl;
	cin >> j;
	switch (j)
	{
		case'1':
		{
			Input(exp);
			break;
		}
		case'2':
		{
			Input_2(exp);
			break;
		}
		case'3':
		{
			Input_3(exp);
			break;
		}
		case'4':
		{
			Input_4(exp);
			break;
		}
		case'5':
		{
			Input_5(exp);
			break;
		}
		case'6':
		{
			Input_6(exp);
			break;
		}
		case'7':
		{
			Input_7(exp);
			break;
		}
		case'8':
		{
			Input_8(exp);
			break;
		}
		default:
		{
			cout << "Error" << endl;
			break;
		}
	}
	while (true)
	{
		cout << "0 to quit" << endl;
		cout << "1 to insert sort" << endl;
		cout << "2 to shell sort" << endl;
		cout << "3 to bubble sort" << endl;
		cout << "4 to quick sort" << endl;
		cout << "5 to select sort" << endl;
		cout << "6 to heap sort" << endl;
		cout << "7 to radix sort" << endl;
		cout << "8 to display" << endl;
		cout << "9 to merge sort" << endl;
		cout << "10 to _merge sort" << endl;
		cout << "Input the order:";
		cin >> i;
		switch (i)
		{
		case'0':
			exit(0);
		case'1':
		{
			insert(exp, 20000);
			break;
		}
		case'2':
		{
			int b[] = { 4,2,1 };
			shell_sort(exp, 20000, b, 3);
			break;
		}
		case'3':
		{
			exchange(exp, 20000);
			break;
		}
		case'4':
		{
			quick_sort(exp, 20000);
			break;
		}
		case'5':
		{
			select(exp, 20000);
			break;
		}
		case'6':
		{
			heap_sort(exp, 20000);
			break;
		}
		case'7':
		{
			radixsort(exp, 20000);
			break;
		}
		case'8':
		{
			display(exp, 20000);
			break;
		}
		case'9':
		{
			merge_sort(exp, 0, 20000);
			break;
		}
		case'10':
		{
			_merge_sort(exp, 20000);
			break;
		}
		default:
			break;
		}
	}
	system("pause");
    return 0;
}

