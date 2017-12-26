// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
typedef struct
{
	char element[100];//操作符
	int top;//栈顶
}Sign;
typedef struct
{
	float element[100];//运算数
	int top;//栈顶
}Number;
Sign *Init()//初始化操作符栈
{
	Sign *s;
	s = (Sign *)malloc(sizeof(Sign));
	s->top = -1;
	return s;
}
int Empty(Sign *s)//判空
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int Push(Sign *s, char x)//入栈
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
char Pop(Sign *s)//出栈
{
	int x;
	if (Empty(s))
		return 0;
	x = s->element[s->top];
	s->top--;
	printf("%d pop\n", x);
	return x;
}
char GetTop(Sign *s)//取栈顶元素
{
	if (Empty(s))
		return 0;
	else
		return (s->element[s->top]);
}
Number *InitStack()//初始化运算数栈
{
	Number *t;
	t = (Number *)malloc(sizeof(Number));
	t->top = -1;
	return t;
}
int EmptyStack(Number *t)//判空
{
	if (t->top == -1)
		return 1;
	else
		return 0;
}
int PushStack(Number *t, float y)//入栈
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
float PopStack(Number *t)//出栈
{
	float y;
	if (EmptyStack(t))
		return 0;
	y = t->element[t->top];
	t->top--;
	printf("%f pop\n", y);
	return y;
}
float GetTopStack(Number *t)//取栈顶元素
{
	if (EmptyStack(t))
		return 0;
	else
		return (t->element[t->top]);
}
int Rank(char op)//判断运算符优先级
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
float Compute(float a, float b, char op)//计算结果
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
			if (b == 0)//判断分母是否为0
			{
				printf("Denominator 0\n");
				system("pause");
				exit(0);
			}
			else
				c = a / b;
			break;
		}
		default://如果不是运算符则跳出
		{
			printf("Illegal character\n");
			break;
		}
	}
	return c;
}
void Convert(char str[])//字符型转为表达式和结果
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
				if (GetTop(sign) == '#' || GetTop(sign) == '(')//如果有左括号则入运算符栈
					Push(sign, str[i]);
				else//否则运算结果，再将结果入运算数栈
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
				if (Rank(str[i]) > Rank(GetTop(sign)) || GetTop(sign) == '(')//如果运算级高或有左括号则入运算符栈
					Push(sign, str[i]);
				else//否则运算结果，再将结果入运算数栈
				{
					a = PopStack(number);
					b = PopStack(number);
					op = Pop(sign);
					PushStack(number, Compute(b, a, op));
					Push(sign, str[i]);
				}
				break;
			}
			case '('://左括号入栈
			{
				Push(sign, str[i]);
				break;
			}
			case ')'://遇右括号运算括号内数据
			{
				while (GetTop(sign) != '(')
				{
					a = PopStack(number);
					b = PopStack(number);
					op = Pop(sign);
					PushStack(number, Compute(b, a, op));
				}
				if (GetTop(sign) == '(')//判断是否非法
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
				while (str[i] >= '0' && str[i] <= '9' || str[i] == '.')//将运算数转为浮点数入运算数栈
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