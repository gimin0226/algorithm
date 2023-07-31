#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct link_list
{
	int data;
	struct link_list* back;
	struct link_list* next;
};

typedef struct link_list list;

struct list_pointer {
	list* a;
	int t;
};
struct list_pointer point[1000001];

int main(void)
{

	int n, m;
	scanf("%d %d", &n, &m);
	int k;
	list* ptr;
	list* current;
	list* head;
	scanf("%d", &k);
	ptr = (list*)malloc(sizeof(list));
	ptr->data = k;
	point[k].a = ptr;
	point[k].t = 1;
	current = ptr;
	head = ptr;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d", &k);
		ptr = (list*)malloc(sizeof(list));
		point[k].a = ptr;
		point[k].t = 1;
		ptr->data = k;
	current->next = ptr;
	ptr->back = current;
	current = ptr;
	}
	ptr->next = head;
	head->back = ptr;
	current = head;
	ptr = head;
	char x[3];
	int y, z;
	list* current2;
	int num = n;
	list* current3;

	for (int j = 0; j < m; j++)
	{
		scanf("%s", x);scanf("%d", &y);
	//	printf("%s ", x); printf("%d ", y);
		if (strcmp(x, "BN") == 0 || strcmp(x, "BP")== 0)
		{
			scanf("%d",&z);
		//	printf("%d ", z);
		}
	//	printf("\n");
		if (strcmp(x, "BN") == 0)
		{
			current = point[y].a;
			current2 = current->next;
			
			if (num == 1)
			{
				printf("%d", current->data);
			}
			else
				printf("%d\n", current->next->data); 
			if (point[z].t==1)
			{
				continue;
			}
			
			ptr = (list*)malloc(sizeof(list));
			point[z].a = ptr;
			point[z].t = 1;
			ptr->data = z;
			current->next = ptr;
			ptr->back = current;
			current2->back = ptr;
			ptr->next = current2;
			num++;
	//		for (int i = 0; i < num; i++) { printf("%d ", head->data); head = head->next; }
		}
		else if (strcmp(x, "BP") == 0)
		{
			current = point[y].a;
			current2 = current->back;
			if (num == 1)
			{
				printf("%d", current->data);
			}
			else
				printf("%d\n", current2->data);
			if (point[z].t == 1)
			{
				continue;
			}
			
			ptr = (list*)malloc(sizeof(list));
			point[z].a = ptr;
			point[z].t = 1;
			ptr->data = z;
			current->back = ptr;
			ptr->next = current;
			current2->next = ptr;
			ptr->back = current2;
			num++;
	//		for (int i = 0; i < num; i++) { printf("%d ", head->data); head = head->next; }

		}
		else if (strcmp(x, "CN") == 0)
		{
			current = point[y].a;
			current2 = current->next;
			if (num <2)
				continue;
			printf("%d\n", current2->data);
			current3 = current->next->next;
			current->next = current3;
			current3->back = current;
			point[current2->data].t=0;
			num--;
		//for (int i = 0; i < num; i++) { printf("%d ", head->data); head = head->next; }


		}
		else if (strcmp(x, "CP") == 0)
		{
			current = point[y].a;
			current2 = current->back;
			if (num < 2)
			{
			
				continue;
			}
			printf("%d\n", current2->data);
			current3 = current->back->back;
			current->back = current3;
			current3->next = current;
			point[current2->data].t = 0;
			num--;
			//for (int i = 0; i < num; i++) { printf("%d ", head->data); head = head->next; }

		}
		

	}
	
	return 0;
}