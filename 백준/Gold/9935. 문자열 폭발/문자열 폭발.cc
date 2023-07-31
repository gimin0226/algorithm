#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	
#include<string.h>

struct stack {
	int top;
	char a[1000001];
};
typedef struct stack stack;

void push(stack* sta, char k);
void pop(stack* sta);
char x[1000001];

int main(void)
{
	stack sta;
	sta.top = -1;
	scanf("%s", x);
	char y[37];
	scanf("%s", y);
	int k = strlen(x);
	int t = strlen(y);
	for (int i = 0; i < k; i++)
	{
		push(&sta, x[i]);
		if (x[i] == y[t - 1])
		{
			int p = sta.top;
			for (int j = t - 1; j >= 0; j--)
			{
				if (y[j] != sta.a[p])
				{
					break;
				}
				if (j == 0)
				{
					sta.top = p - 1;
					break;
				}
				p--;
			}
		}
	}
	if (sta.top == -1)
		printf("FRULA");
	else
	{
		for (int i = 0; i <= sta.top; i++)
			printf("%c", sta.a[i]);
	}
}

void push(stack* sta, char k)
{
	sta->top++;
	sta->a[sta->top] = k;
}

void pop(stack* sta)
{
	sta->a[sta->top--] = NULL;
}