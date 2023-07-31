#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int b[1000000][2];

struct node {
	int x;
	int y;
	int level;
	struct node* next;
}; typedef struct node node;

struct queue {
	node* rear;
	node* front;
	int count;
}; typedef struct queue queue;

void enqueue(queue* que, int x, int y, int level);
node* dequeue(queue* que);

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int** arr = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	int num = 0;
	int num2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				b[num][0] = i;
				b[num][1] = j;
				num++;
			}
			if (arr[i][j] == 0)
				num2++;
		}
		getchar();
	}
	if (num2 == 0)
	{
		printf("0");
		return 0;
	}
	queue que;
	que.count = 0;
	int level = 0;
	for (int i = 0; i < num; i++)
	{
		enqueue(&que, b[i][0], b[i][1], level);
	//	printf("enqueue_x:%d y:%d level:%d\n", b[i][0], b[i][1], level);

	}
	
	int x, y;
	node* ptr;
	int level2;
	int num3 = 0;
	while (1)
	{
		
		if (que.count == 0)
		{
			num3 = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == 0)
					{
						num3++;
					}

				}
			}
			if (num3 == 0)
			{
				printf("%d", level);
				return 0;
			}
			else if (num3 != 0)
			{
				printf("-1");
				return 0;
			}
		}
		ptr = dequeue(&que);
		x = ptr->x;
		y = ptr->y;
		level2 = ptr->level;
		if (level2 == level + 1)
		{
			level++;
		}
	//	printf("dequeue_x:%d y:%d level:%d\n", x, y, level2);
		if (x != 0 && arr[x - 1][y] == 0)
		{
			enqueue(&que, x - 1, y, level + 1);
			arr[x - 1][y] = 1;
		//	printf("가enqueue_x:%d y:%d level:%d\n", x-1, y, level+1);
		}
		if (x != m - 1 && arr[x + 1][y] == 0)
		{
			enqueue(&que, x + 1, y, level + 1);
			arr[x + 1][y] = 1;
		//	printf("나enqueue_x:%d y:%d level:%d\n", x+1, y, level+1);
		}
		if (y != 0 && arr[x][y - 1] == 0)
		{
			enqueue(&que, x, y - 1, level + 1);
			arr[x][y - 1] = 1;
			//printf("다enqueue_x:%d y:%d level:%d\n", x, y - 1, level+1);
		}
		if (y != n - 1 && arr[x][y + 1] == 0)
		{
			enqueue(&que, x, y + 1, level + 1);
			arr[x][y + 1] = 1;
		//	printf("라enqueue_x:%d y:%d level:%d\n", x, y+1, level+1);
		}
	}
	
	

}

void enqueue(queue* que, int x, int y, int level)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->x = x;
	newnode->y = y;
	newnode->level = level;
	if (que->count == 0)
		que->front = newnode;
	else
		que->rear->next = newnode;
	que->rear = newnode;
	que->count++;
}

node* dequeue(queue* que)
{
	node* ptr = que->front;
	if (que->count == 1)
	{
		que->front == NULL;
	}
	else
		que->front = ptr->next;
	que->count--;
	return ptr;
}