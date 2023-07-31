#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct _stack {
	int top;
	int *a;
};

typedef struct _stack _stack;
int compare(_stack* stack, int* b, int i);
int push(_stack* stack, int* b, int i);
int pop(_stack* stack, int* b, int i);
int main(void)
{
	_stack stack;
	stack.top = -1;
	int n;
	scanf("%d", &n);
	stack.a = (int*)malloc(sizeof(int) * (n + 1));
	int* b = (int*)malloc(sizeof(int) * (n + 1));
	int* c = (int*)malloc(sizeof(int) * (n + 1));


	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < n; i++)
	{
		
		while (1)
		{
			if (stack.top == -1)
			{
				push(&stack, b,i);
				c[i] = 0;
				break;
			}
			
			if (compare(&stack, b,i) == 0)
			{
				
				pop(&stack, b,i);
			}
			else
			{
				c[i]=push(&stack, b,i)+1;
				break;
			}

		}
		printf("%d ", c[i]);
	}

}
int pop(_stack* stack, int* b, int i)
{
	stack->a[stack->top] = NULL;
	stack->top--;
	return 0;
}
int compare(_stack* stack, int *b,int i)
{
	if (b[stack->a[stack->top]] <b[i])
		return 0;
	else
		return 1;
}
int push(_stack* stack, int *b,int i)
{
	stack->top++;
	stack->a[stack->top] = i;
	return stack->a[stack->top - 1];
}
