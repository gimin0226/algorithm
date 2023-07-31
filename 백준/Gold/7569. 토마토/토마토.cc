#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node {
	int x, y, z;
	struct node* next;
	int level;
}; typedef struct node node;

struct queue {
	node* front;
	node* rear;
	int count;
}; typedef struct queue queue;
void enqueue(queue* que, int x, int y, int z, int lev);
node* dequeue(queue* que);

int arr[100][100][100];
int arr2[100][100][100] = { 0 };

int main(void)
{
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	int lev = 0;
	queue que;
	que.count = 0;
	int num = 0;
	int num2 = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 1)
				{
					enqueue(&que, i, j, k, lev);
			//		printf("x:%d y:%d z:%d lev:%d\n", i, j, k, lev);
					arr2[i][j][k] = 1;
					num++;
					num2++;
				}
				if (arr[i][j][k] == 0)
				{
					num++;
				}
			}
		}
	}
	/*printf("\n");
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("num:%d\n", num);
	*/
	lev;
	int lev2 = 0;
	int x, y, z;
	while (1)
	{
		if (que.count == 0)
		{
			if (num2 == num)
			{
				printf("%d", lev);
				return 0;
			}
			else if (num2 != num)
			{
				printf("-1");
				return 0;
			}
		}
		node* ptr = dequeue(&que);
		x = ptr->x; y = ptr->y; z = ptr->z; lev2 = ptr->level;
		if (lev2 > lev)
		{
			lev++;
		}
	//	printf("dequeue x:%d y:%d z:%d lev:%d\n", x, y, z, lev2);
		if (z != 0)
		{
			if (arr[x][y][z - 1] == 0 && arr2[x][y][z - 1] == 0)
			{
				enqueue(&que, x, y, z - 1, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x, y, z-1, lev,num2+1);
				arr2[x][y][z - 1] = 1;
				num2++;
			}
		}
		if (z != n-1)
		{
			if (arr[x][y][z + 1] == 0 && arr2[x][y][z + 1] == 0)
			{
				enqueue(&que, x, y, z + 1, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x, y, z + 1, lev, num2 + 1);
				arr2[x][y][z + 1] = 1;
				num2++;

			}
		}
		if (y != 0)
		{
			if (arr[x][y-1][z] == 0 && arr2[x][y-1][z] == 0)
			{
				enqueue(&que, x, y-1, z, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x, y-1, z, lev, num2 + 1);
				arr2[x][y-1][z] = 1;
				num2++;

			}
		}
		if (y != m-1)
		{
			if (arr[x][y+1][z] == 0 && arr2[x][y+1][z] == 0)
			{
				enqueue(&que, x, y+1, z, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x, y+1, z, lev, num2 + 1);
				arr2[x][y+1][z] = 1;
				num2++;

			}
		}
		if (x != 0)
		{
			if (arr[x-1][y][z] == 0 && arr2[x-1][y][z] == 0)
			{
				enqueue(&que, x-1, y, z, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x-1, y, z, lev, num2 + 1);
				arr2[x-1][y][z] = 1;
				num2++;
			}

		}
		if (x != h-1)
		{
			if (arr[x+1][y][z] == 0 && arr2[x+1][y][z] == 0)
			{
				enqueue(&que, x+1, y, z, lev+1);
			//	printf("x:%d y:%d z:%d lev:%d num2:%d\n", x+1, y, z, lev, num2 + 1);
				arr2[x+1][y][z] = 1;
				num2++;
			}
		}
		
	}

}

void enqueue(queue* que, int x, int y, int z, int lev)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->x = x; newnode->y = y; newnode->z = z;
	newnode->level = lev;
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
