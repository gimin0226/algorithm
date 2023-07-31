#define _CRT_SECURE_NO_WARNINGS
#define example 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue {
	int a[65][2];
	int count;
	int front;
	int rear;
}; typedef struct queue queue;
int num[262144] = { 0 };
int t = 0;
void enqueue(int data1, int data2, queue* que);
void dequeue(queue* que, int* x, int* y);

int main(void)
{
	queue que;
	que.count = -1;
	que.front = 0; que.rear = -1;

	queue que2;
	int n, m;
	scanf("%d %d", &n, &m);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * m);
	}
	
	int** x = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * m);
	}
	const int num1 = n * m; //전체의 개수
	int numt = 0; //2의 개수
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				numt++;
			}
			if (arr[i][j] == 2)
			{
				enqueue(i, j, &que);
		//		printf("enqueue x:%d y:%d\n", i, j);

				numt++;
			}
		}
	}
	const int num2 = numt;
	if (num1 -  num2 == 3)
	{
		printf("0");
		return 0;
	}
	memcpy(&que2,&que,sizeof(queue));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j]=arr[i][j];
		}
	}
	
	
	for (int a = 0; a < n; a++)
	{
		
		for (int b = 0; b < m; b++)
		{
			if (arr[a][b] != 0)
			{
			//	printf("(%d,%d)\n", a, b);
				continue;
			}
			for (int c = 0; c < n; c++)
			{
				for (int d = 0; d < m; d++)
				{
				
					if (a == c && b >= d)
						continue;
					if (arr[c][d] != 0)
					{
				//		printf("(%d,%d),(%d,%d)\n", a, b, c, d);
						continue;
					}
					for (int e = 0; e < n; e++)
					{
						for (int f =0; f < m; f++)
						{
							
							if (a == e && b >= f)
								continue;
							
							if (c == e && d == f)
								continue;
						
							if (arr[e][f] != 0)
							{
								
							//	printf("zx(%d,%d),(%d,%d),(%d,%d)\n", a, b, c, d, e, f);
								continue;
							}
			
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
								{
									x[i][j] = arr[i][j];
								}
							}
							memcpy(&que2, &que, sizeof(queue));
							x[a][b] = 1;
							x[c][d] = 1;
							x[e][f] = 1;
							int ptr1, ptr2;
							
						//	printf("(%d,%d),(%d,%d),(%d,%d)\n", a, b, c, d, e, f);
							
							while (1)
							{
								if (que2.front > que2.rear)
								{
									num[t] = num1 - num2 - num[t]-3;
							//		printf("num[%d]:%d\n", t, num[t]);
									t++;
									break;
								}
								dequeue(&que2, &ptr1, &ptr2);
							//	printf("que.front:%d que.rear:%d ", que2.front, que2.rear);
							//	printf("dequeue x:%d y:%d\n", ptr1, ptr2);
								if (ptr1 != 0)
								{
									if (x[ptr1 - 1][ptr2] == 0)
									{
										x[ptr1 - 1][ptr2] = 1;
										enqueue(ptr1 - 1, ptr2, &que2);
										num[t]++;
									//	printf("가enqueue x:%d y:%d num[%d]:%d\n", ptr1 - 1, ptr2,t,num[t]);
										
									}
								}
								if (ptr1 != n-1)
								{
									if (x[ptr1 +1][ptr2] == 0)
									{
										x[ptr1 + 1][ptr2] = 1;
										enqueue(ptr1 + 1, ptr2, &que2);
										num[t]++;
									//	printf("나enqueue x:%d y:%d num[%d]:%d\n", ptr1 + 1, ptr2,t,num[t]);
									}
								}
								if (ptr2 != 0)
								{
									if (x[ptr1][ptr2-1] == 0)
									{
										x[ptr1][ptr2 - 1] = 1;
										enqueue(ptr1, ptr2-1, &que2);
										num[t]++;

									//	printf("다enqueue x:%d y:%d num[%d]:%d\n", ptr1, ptr2-1,t,num[t]);
									}
								}
								if (ptr2 != m-1)
								{
									if (x[ptr1][ptr2+1] == 0)
									{
										x[ptr1][ptr2 + 1] = 1;
										enqueue(ptr1, ptr2+1, &que2);
										num[t]++;

									//	printf("라enqueue x:%d y:%d num[%d]:%d\n", ptr1, ptr2+1,t,num[t]);
									}
								}

							}
							
						}
					}
				}
			}
		}
	}
	int max = num[0];
	for (int i = 0; i < t; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
	}
	printf("%d", max);
}

void enqueue(int data1, int data2, queue* que)
{
	que->rear++;
	que->a[que->rear][0] = data1;
	que->a[que->rear][1] = data2;
	
}

void dequeue(queue* que,int* x,int* y)
{
	*x = que->a[que->front][0];
	*y = que->a[que->front][1];
	que->front++;
}