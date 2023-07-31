#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void recursion(char* a, int num, int t);
char b[6562][6562];

int j = 0;
int n;
int main(void)
{
	scanf("%d", &n);
//	printf("%d", n);
	char ptr[2] = "*";
	recursion(ptr,1,1);
	//printf("sdf");
	for (int i = 1; i <= n; i++)
		printf("%s\n", b[i]);
}


 void recursion(char *a,int num,int t)
{
	// printf("dsf");
	 if (num == n)
	 {
		 strcpy(b[t], a);
		 return;
	 }
//	 printf("%s\n", a);
	 char ptr[6562];
	// printf("%d\n", sizeof(ptr));
	 strcpy(ptr, a);
	// printf("%s\n", ptr);
	 strcat(ptr, a);
	 strcat(ptr, a);
	// printf("%s\n", ptr);
	 if (num == 1)
		 recursion(ptr, num * 3, 1);
	 else
		recursion(ptr, num * 3,t);
	 strcpy(ptr, a);
	 for (int i = 0; i < num; i++)
		 strcat(ptr, " ");
	 strcat(ptr, a);
	// printf("%s\n",ptr);
	 if (num == 1)
		 recursion(ptr, num * 3, 2);
	 else
		 recursion(ptr, num * 3, t + num);
	 strcpy(ptr, a);
	 strcat(ptr, a);
	 strcat(ptr, a);
	// printf("%s\n", ptr);
	 if (num == 1)
		 recursion(ptr, num * 3, 3);
	 recursion(ptr, num * 3,t+2*num);


}