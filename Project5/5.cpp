// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct
{
	long long num;//���֤��
	char name[20];//����
	char addr[5];//��ַ
}Record;
typedef struct HashNode
{
	long long data;//��������
	struct HashNode *next;//��������next�ڵ�
}Hash, *HashLink;
void search(long long number)//˳�����
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
	for (i = 0; i < 50; i++)//�ļ��ж�ȡ�����Ϣ
	{
		fscanf(fp, "%lld %s %s\n", &r[i].num, &r[i].name, &r[i].addr);
	}
	fclose(fp);
	for (i = 0; i < 50; i++)//������浽data������
	{
		data[i] = r[i].num;
	}
	HashLink add[51] = {};
	HashLink p, q;
	for (i = 0; i<50; i++)//�Ժ����51ȡ����Ϊ�ؼ��ֽ�������ַ
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

