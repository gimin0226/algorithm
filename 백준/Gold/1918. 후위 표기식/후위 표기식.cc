#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct stack {
	int top;
	char a[101];
};

typedef struct stack stack;
void push(stack* st, char x);
char pop(stack* st);

int main(void)
{
	stack st;
	st.top = -1;

	char x[101];
	scanf("%s", x);
	char y[101];

	int k = strlen(x);

	char z[101];

	int i = 0;
	int j = 0;
	while (1)
	{
		if (i >= k)
		{
			while (1)
			{
				if (st.top == -1)
				{
					return 0;	
				}
				z[j] = pop(&st); j++;
				printf("%c", z[j-1]);
			}
		}
		if (j == k + 1)
			return 0;
		if (x[i] == '+' || x[i] == '-')
		{
			if (st.a[st.top] == '+' || st.a[st.top] == '-')
			{
				z[j] = pop(&st); j++;
				printf("%c", z[j-1]);
				push(&st, x[i]); 
			}
			else
				push(&st, x[i]); i++;
		}
		else if (x[i] == '*' || x[i] == '/')
		{
		
			if (st.a[st.top] == '*' || st.a[st.top] == '/')
			{
				z[j] = pop(&st); j++;
				printf("%c", z[j-1]);
			}
			if (x[i + 1] == '(')
			{
				push(&st, x[i]); i++;
			}
			else
			{
				z[j] = x[i + 1];
				printf("%c", z[j]);
				z[j + 1] = x[i];
				printf("%c", z[j + 1]);
				j += 2; i += 2;
			}
		}

		else if (x[i] == '(')
		{
			push(&st, x[i]); i++;
		}
		else if (x[i] == ')')
		{
			if (st.a[st.top] == '(')
			{
				pop(&st);
				if (st.a[st.top] == '*' || st.a[st.top] == '/')
				{
					z[j] = pop(&st); j++;
					printf("%c", z[j - 1]);
				}
				i++;
			}
			else
			{
				z[j] = pop(&st); j++;
				printf("%c", z[j-1]);
				if (st.a[st.top] == '(')
				{
					pop(&st);
				}
				if (st.a[st.top] == '*' || st.a[st.top] == '/')
				{
					z[j] = pop(&st); j++;
					printf("%c", z[j - 1]);
				}
				i++;
			}
		}
	
		
		else  
		{
			z[j] = x[i];
			printf("%c", z[j]);
			j++; i++;
		}
	}
}

void push(stack* st, char x)
{
	st->top++;
	st->a[st->top] = x;
}

char pop(stack* st)
{
	char k = st->a[st->top];
	st->a[st->top--] = '\0';
	return k;
}