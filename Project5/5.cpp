// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct
{
	long long num;//身份证号
	char name[20];//名字
	char addr[5];//地址
}Record;
typedef struct HashNode
{
	long long data;//号码数据
	struct HashNode *next;//单向链表next节点
}Hash, *HashLink;
void search(long long number)//顺序查找
{
	int i;
	Record r[50];
	FILE *fp;
	fp = fopen("example.txt", "r");
	if (!fp)
	{
		printf("File Open Error\n");
		exit(0);
	}
	for (i = 0; i < 50; i++)
	{
		fscanf(fp, "%lld %s %s\n", &r[i].num, &r[i].name, &r[i].addr);
	}
	fclose(fp);
	for (i = 0; i < 50; i++)
	{
		if (r[i].num == number)
		{
			cout << "Name:" << r[i].name << endl;
			cout << "Addr:" << r[i].addr << endl;
		}
	}
}
int main()
{
	long long num;
	Record r[50];
	long long data[50], key;
	int i, j;
	FILE *fp;
	fp = fopen("example.txt", "r");
	if (!fp)
	{
		printf("File Open Error\n");
		exit(0);
	}
	for (i = 0; i < 50; i++)//文件中读取身份信息
	{
		fscanf(fp, "%lld %s %s\n", &r[i].num, &r[i].name, &r[i].addr);
	}
	fclose(fp);
	for (i = 0; i < 50; i++)//将号码存到data数组中
	{
		data[i] = r[i].num;
	}
	HashLink add[51] = {};
	HashLink p, q;
	for (i = 0; i<50; i++)//以号码和51取余作为关键字建立链地址
	{
		key = data[i] % 51;
		p = (HashLink)malloc(sizeof(Hash));
		p->data = data[i];
		p->next = NULL;
		if (!add[key]) add[key] = p;
		else
		{
			for (q = add[key]; q->next; q = q->next);
			q->next = p;
		}
	}
	for (j = 0; j<51; j++)
	{
		if (add[j])
		{
			q = add[j];
			while (q)
			{
				printf("%20lld", q->data);
				q = q->next;
			}
			printf("\n");
		}
		else
			printf("NULL\n");
	}
	cout << "ID Number:";
	cin >> num;
	search(num);
	system("pause");
    return 0;
}

