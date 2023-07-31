#define _CRT_SECURE_NO_WARNINGS
#define example	0
#include<stdio.h>
#include<stdlib.h>

struct node {
	int x, y;
	struct node* next;
}; typedef struct node node;

struct queue {
	node* front;
	node* rear;
	int count;
}; typedef struct queue queue;

void enqueue(queue* que, int x, int y);
node* dequeue(queue* que);

int main(void)
{
	int n;
	scanf("%d", &n);
	int** arr1 = (int**)malloc(sizeof(int*) * n);
	int** arr2 = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr1[i] = (int*)malloc(sizeof(int*)*n);  //블루VS레드VS그린
		arr2[i] = (int*)malloc(sizeof(int*) * n);//블루VS(레드,그린)
	}

	int** ptr1 = (int**)calloc(n, sizeof(int*));
	int** ptr2 = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		ptr1[i] = (int*)calloc(n, sizeof(int));
		ptr2[i] = (int*)calloc(n, sizeof(int));
	}
	char q;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &q); //B==0 R==1 G==2
			if (q == 'B')
			{
				arr1[i][j] = 0;
				arr2[i][j] = 0;
			}
			else if (q == 'R')
			{
				arr1[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if (q == 'G')
			{
				arr1[i][j] = 2;
				arr2[i][j] = 1;
			}
		}
		getchar();
	}
	if (example == 1){for (int i = 0; i < n; i++){for (int j = 0; j < n; j++){printf("%d ", arr1[i][j]);	}printf("\n");	}}
	if(example==1)printf("\n");
	if (example == 1) { for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { printf("%d ", arr2[i][j]); }printf("\n"); } }

	int num1 = 0; //색 3개
	int num2 = 0; //색 2개

	queue que1; que1.count = 0;
	queue que2; que2.count = 0;
	int ptrnum;
	node* ptrnode;
	int x, y;

	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ptr2[i][j] == 0)
			{
				ptrnum = arr2[i][j];
				ptr2[i][j] = 1;
				enqueue(&que2, i, j);
				if (example == 1)printf("enqueue x:%d y:%d\n", i, j);

				while (1)
				{
					if (que2.count == 0)
					{
						num2++;
					//	printf("num2:%d\n", num2);
						if (example == 1) { for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { printf("%d ", ptr2[i][j]); }printf("\n"); } }
						break;
					}
					ptrnode=dequeue(&que2);

					x = ptrnode->x;
					y = ptrnode->y;
					if (example == 1)printf("dequeue x:%d y:%d\n", x, y);
					if (x != 0)
					{
						if (arr2[x - 1][y] == ptrnum&&ptr2[x-1][y]==0)
						{
							enqueue(&que2, x - 1, y);
							if (example == 1)printf("enqueue x:%d y:%d\n", x-1, y);
							ptr2[x - 1][y] = 1;
						}
					}
					if (x != n-1)
					{
						if (arr2[x + 1][y] == ptrnum && ptr2[x + 1][y] == 0)
						{
							enqueue(&que2, x + 1, y);
							if (example == 1)printf("enqueue x:%d y:%d\n", x + 1, y);
							ptr2[x + 1][y] = 1;
						}
					}
					if (y != 0)
					{
						if (arr2[x][y-1] == ptrnum && ptr2[x][y-1] == 0)
						{
							enqueue(&que2, x, y-1);
							if (example == 1)printf("enqueue x:%d y:%d\n", x, y-1);
							ptr2[x][y-1] = 1;
						}
					}
					if (y != n-1)
					{
						if (arr2[x][y+1] == ptrnum && ptr2[x][y+1] == 0)
						{
							enqueue(&que2, x , y+1);
							if (example == 1)printf("enqueue x:%d y:%d\n", x, y+1);
							ptr2[x ][y+1] = 1;
						}
					}
				}
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ptr1[i][j] == 0)
			{
				ptrnum = arr1[i][j];
				ptr1[i][j] = 1;
				enqueue(&que1, i, j);
				if (example == 1)printf("enqueue x:%d y:%d\n", i, j);

				while (1)
				{
					if (que1.count == 0)
					{
						num1++;
					//	printf("num2:%d\n", num1);
						if (example == 1) { for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { printf("%d ", ptr1[i][j]); }printf("\n"); } }
						break;
					}
					ptrnode = dequeue(&que1);

					x = ptrnode->x;
					y = ptrnode->y;
					if (example == 1)printf("dequeue x:%d y:%d\n", x, y);
					if (x != 0)
					{
						if (arr1[x - 1][y] == ptrnum && ptr1[x - 1][y] == 0)
						{
							enqueue(&que1, x - 1, y);
							if (example == 1)printf("enqueue x:%d y:%d\n", x - 1, y);
							ptr1[x - 1][y] = 1;
						}
					}
					if (x != n - 1)
					{
						if (arr1[x + 1][y] == ptrnum && ptr1[x + 1][y] == 0)
						{
							enqueue(&que1, x + 1, y);
							if (example == 1)printf("enqueue x:%d y:%d\n", x + 1, y);
							ptr1[x + 1][y] = 1;
						}
					}
					if (y != 0)
					{
						if (arr1[x][y - 1] == ptrnum && ptr1[x][y - 1] == 0)
						{
							enqueue(&que1, x, y - 1);
							if (example == 1)printf("enqueue x:%d y:%d\n", x, y - 1);
							ptr1[x][y - 1] = 1;
						}
					}
					if (y != n - 1)
					{
						if (arr1[x][y + 1] == ptrnum && ptr1[x][y + 1] == 0)
						{
							enqueue(&que1, x, y + 1);
							if (example == 1)printf("enqueue x:%d y:%d\n", x, y + 1);
							ptr1[x][y + 1] = 1;
						}
					}
				}
			}

		}
	}
	printf("%d %d", num1, num2);
}

void enqueue(queue* que, int x, int y)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->x = x;
	newnode->y = y;
	if (que->count == 0)
	{
		que->front = newnode;
	}
	else
	{
		que->rear->next = newnode;
	}
	que->rear = newnode;
	que->count++;
}

node* dequeue(queue* que)
{
	node* ptr = que->front;
	que->front = ptr->next;
	que->count--;
	return ptr;
}
