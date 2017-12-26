// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct
{
	char element[100];//������
	int top;//ջ��
}Sign;
typedef struct
{
	float element[100];//������
	int top;//ջ��
}Number;
Sign *Init()//��ʼ��������ջ
{
	Sign *s;
	s = (Sign *)malloc(sizeof(Sign));
	s->top = -1;
	return s;
}
int Empty(Sign *s)//�п�
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int Push(Sign *s, char x)//��ջ
{
	if (s->top == 99)
		return 0;
	else
	{
		s->top++;
		s->element[s->top] = x;
		if (x == '#')
			return 1;
		else
		{
			printf("%c push\n", x);
			return 1;
		}
	}
}
char Pop(Sign *s)//��ջ
{
	int x;
	if (Empty(s))
		return 0;
	x = s->element[s->top];
	s->top--;
	printf("%d pop\n", x);
	return x;
}
char GetTop(Sign *s)//ȡջ��Ԫ��
{
	if (Empty(s))
		return 0;
	else
		return (s->element[s->top]);
}
Number *InitStack()//��ʼ��������ջ
{
	Number *t;
	t = (Number *)malloc(sizeof(Number));
	t->top = -1;
	return t;
}
int EmptyStack(Number *t)//�п�
{
	if (t->top == -1)
		return 1;
	else
		return 0;
}
int PushStack(Number *t, float y)//��ջ
{
	if (t->top == 99)
		return 0;
	else
	{
		t->top++;
		t->element[t->top] = y;
		printf("%f push\n", y);
		return 1;
	}
}
float PopStack(Number *t)//��ջ
{
	float y;
	if (EmptyStack(t))
		return 0;
	y = t->element[t->top];
	t->top--;
	printf("%f pop\n", y);
	return y;
}
float GetTopStack(Number *t)//ȡջ��Ԫ��
{
	if (EmptyStack(t))
		return 0;
	else
		return (t->element[t->top]);
}
int Rank(char op)//�ж���������ȼ�
{
	int x;
	switch (op)
	{
		case '#':
		{
			x = 0;
			break;
		}
		case '(':
		{
			x = 1;
			break;
		}
		case '+':
		case '-':
		{
			x = 2;
			break;
		}
		case '*':
		case '/':
		{
			x = 3;
			break;
		}
	}
	return x;
}
float Compute(float a, float b, char op)//������
{
	float c;
	switch (op)
	{
		case '+':
		{	
			c = a + b;
			break;
		}
		case '-':
		{
			c = a - b;
			break;
		}
		case '*':
		{
			c = a * b;
			break;
		}
		case '/':
		{
			if (b == 0)//�жϷ�ĸ�Ƿ�Ϊ0
			{
				printf("Denominator 0\n");
				system("pause");
				exit(0);
			}
			else
				c = a / b;
			break;
		}
		default://������������������
		{
			printf("Illegal character\n");
			break;
		}
	}
	return c;
}
void Convert(char str[])//�ַ���תΪ���ʽ�ͽ��
{
	Sign *sign = Init();
	Number *number = InitStack();
	int i, j;
	float f, a, b;
	char d[100];
	char op;
	Push(sign, '#');
	for (i = 0; str[i]; i++)
	{
		switch (str[i]) 
		{
			case '+':
			case '-':
			{
				if (GetTop(sign) == '#' || GetTop(sign) == '(')//��������������������ջ
					Push(sign, str[i]);
				else//�������������ٽ������������ջ
				{
					a = PopStack(number);
					b = PopStack(number);
					op = Pop(sign);
					PushStack(number, Compute(b, a, op));
					Push(sign, str[i]);
				}
				break;
			}
			case '*':
			case '/':
			{
				if (Rank(str[i]) > Rank(GetTop(sign)) || GetTop(sign) == '(')//������㼶�߻������������������ջ
					Push(sign, str[i]);
				else//�������������ٽ������������ջ
				{
					a = PopStack(number);
					b = PopStack(number);
					op = Pop(sign);
					PushStack(number, Compute(b, a, op));
					Push(sign, str[i]);
				}
				break;
			}
			case '('://��������ջ
			{
				Push(sign, str[i]);
				break;
			}
			case ')'://����������������������
			{
				while (GetTop(sign) != '(')
				{
					a = PopStack(number);
					b = PopStack(number);
					op = Pop(sign);
					PushStack(number, Compute(b, a, op));
				}
				if (GetTop(sign) == '(')//�ж��Ƿ�Ƿ�
				{
					printf("Wrong input\n");
					system("pause");
					exit(0);
				}
				Pop(sign);
				break;
			}
			case'#':
			{
				str[i] = ' ';
				break;
			}
			default:
			{
				j = 0;
				while (str[i] >= '0' && str[i] <= '9' || str[i] == '.')//��������תΪ��������������ջ
				{
					d[j++] = str[i];
					i++;
				}
				d[j] = '\0';
				i--;
				f = float(atof(d));
				PushStack(number, f);
				break;
			}
		}
	}
	while (GetTop(sign) != '#')
	{
		a = PopStack(number);
		b = PopStack(number);
		op = Pop(sign);
		PushStack(number, Compute(b, a, op));
	}
	printf("%s = %g\n", str, GetTopStack(number));
}
int main()
{
	char str[100];
	printf("Input the expression:");
	scanf("%s", str);
	Convert(str);
	system("pause");
	return 0;
}