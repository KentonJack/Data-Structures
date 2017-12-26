// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
typedef struct
{
	char *ch;
	int length;
}HString;
void StrAssign(HString &T, char *chars)
{
	int i;
	char *c;
	if (T.ch != NULL)
		free(T.ch);
	for (i = 0, c = chars; *c; ++i, ++c)
		;
	if (!i)
	{
		T.ch = NULL;
		T.length = 0;
	}
	else
	{
		if (!(T.ch = (char *)malloc(i * sizeof(char))))
			exit(0);
		T.ch = chars;
		T.length = i;
	}
}
int main()
{
	FILE *fp;
	char a[100], b[10];
	char *temp = b;
	int i, j, count = 0, flag = 0;
	fp = fopen("test.txt", "r");
	if (fp == NULL)
	{
		printf("Error open file.\n");
		system("pause");
		exit(1);
	}
	printf("Input the word:");
	//HString T;
	//StrAssign(T, b);
	gets_s(b, 10);
	for (i = 0; fgetc(fp) != EOF; i++)
	{
		a[i] = fgetc(fp);
	}
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == *temp)
			temp++;
		else
			temp = b;
		i++;
		if (*temp == '\0')
		{
			count++;
			temp = b;
		}
	}
	printf("%s:%d\n", b, count);
	fclose(fp);
	system("pause");
    return 0;
}
