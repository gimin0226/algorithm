#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>

struct intstack {
	int top;
	int* a;
};
typedef struct intstack intstack;
int compare(intstack* stack, int b);
int push(intstack* stack, int b);
int pop(intstack* stack, int b);
int main(void)
{
	intstack stack;
	int n;
	scanf("%d", &n);
	stack.a = (int*)malloc(sizeof(int) * (n + 1));
	stack.top = -1;
	int* b = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int* c = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = n - 1;i >= 0; i--)
	{
		while (1)
		{
			if (stack.top == -1)
			{
				push(&stack, b[i]);
				c[i] = -1;
				break;
			}
			if (compare(&stack, b[i]) == 0)
			{

				pop(&stack, b[i]);
			}
			else
			{
				c[i]=push(&stack, b[i]);
				
				break;
			}

		}

	}
	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);

}
int pop(intstack* stack, int b)
{
	stack->a[stack->top] = NULL;
	stack->top--;
	return 0;
}
int compare(intstack* stack, int b)
{
	if (stack->a[stack->top]<=b)
		return 0;
	else
		return 1;
}
int push(intstack* stack, int b)
{
	stack->top++;
	stack->a[stack->top] = b;
	return stack->a[stack->top - 1];
}
