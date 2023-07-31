#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct node {
	int data;
	struct node* next;
	struct node* under;
	struct node* up;
	struct node* left;
}; typedef struct node node;

node tree[51];
int num1 = 0;
int num2 = 0;
int recursion(int n);
int recursion2(int n);
int main(void)
{
	int n;
	scanf("%d", &n);
	int k;
	for (int i = 0; i < 52; i++)
	{
		tree[i].under = NULL;
		tree[i].next = NULL;
		tree[i].up = NULL;
		tree[i].left = NULL;
		tree[i].data = i;
	}
	node* head=NULL;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if (k == -1)
		{
			head = &tree[i];
		}
		else if (tree[k].under == NULL)
		{
			tree[k].under = &tree[i];
			tree[i].up = &tree[k];
		}
		else
		{
			node* ptr = tree[k].under;
		
			while (1)
			{
				if (ptr->next == NULL)
				{
					break;
				}
				else
				{
					ptr = ptr->next;
				}
			}
			ptr->next = &tree[i];
			tree[i].left = ptr;
		}
	}
	int m;
	scanf("%d", &m);
	if (m == head->data)
	{
		printf("0");
		return 0;
	}
//	printf("%d\n", head->under->next->next->under->under->next->data);
	recursion(head->data);
	//printf("%d\n", num1);
	recursion2(m);
	//printf("%d\n", num2);
	if (tree[m].left == NULL && tree[m].next == NULL)
	{
		printf("%d", num1 - num2 + 1);
	}
	else
		printf("%d", num1 - num2);
	return 0;
}

int recursion(int n)
{
	//printf("%d\n", n);
	node* ptr=&tree[n];
	if (ptr->under == NULL)
	{
		//printf("꿱%d\n", ptr->data);
		num1++;
		return 0;
	}
	else
	{
		//printf("%d\n", ptr->data);
		ptr = ptr->under;
	}
	while (1)
	{
		if (ptr->next == NULL)
		{
		//	printf("%d\n", ptr->next);
			recursion(ptr->data);
			return 0;
		}
		else
		{
			recursion(ptr->data);
			ptr = ptr->next;

		}
		
	}
}

int recursion2(int n)
{
//	printf("%d\n", n);
	node* ptr = &tree[n];
	if (ptr->under == NULL)
	{
		//printf("꿱%d\n", ptr->data);
		num2++;
		return 0;
	}
	else
	{
		//printf("%d\n", ptr->data);
		ptr = ptr->under;
	}
	while (1)
	{
		if (ptr->next == NULL)
		{
			//	printf("%d\n", ptr->next);
			recursion2(ptr->data);
			return 0;
		}
		else
		{
			recursion2(ptr->data);
			ptr = ptr->next;

		}

	}
}
