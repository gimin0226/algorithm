#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node* next;
}; typedef struct node node;

struct queue
{
	int count;
	node* front;
	node* rear;
}; typedef struct queue queue;
int enqueue(int data, queue* que);
int dequeue(queue* que);

int main(void)
{
	int n, k;
	scanf("%d %d", &n,&k);
	char** arr;
	arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * 21);
	}
	for (int i = 0; i < n; i ++ )
		scanf("%s", arr[i]);

	int* length=(int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		length[i] = strlen(arr[i]);
	}
	//for (int i = 0; i < n; i++)printf("%d ", length[i]);
	queue que;
	que.count = 0;
	
	long long b[21] = { 0 };
	long long num = 0;
	for (int i = 0; i < n; i++)
	{
		

		int t = enqueue(length[i],&que);

		if (b[t] == 0)
		{
			b[t]++;
		}
		else if(b[t] > 0)
		{
			num += b[t];
			b[t]++;
		}
		if (i != 0)
		{
			node* ptr2 = que.front;
	/*	for (int i = 0; i < que.count; i++)
			{
				printf("%d ", ptr2->data);
				ptr2 = ptr2->next;
			}*/
		}
	//	printf("t:%d b[t]:%lld num:%lld\n",t,b[t], num);
		if (que.count == k+1)
		{
			//printf("나");
			t = dequeue(&que);
			b[t]--;
		}
	}
	printf("%lld", num);
}

int enqueue(int data, queue* que)
{

	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
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
	return que->rear->data;
}

int dequeue(queue* que)
{
	node* ptr;
	int x = que->front->data;
	ptr = que->front->next;
	que->front = ptr;
	que->count--;
	return x;
}