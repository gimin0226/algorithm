#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a[29];

void recursion(int r, int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	int r = 0;
	a[0] = 3;
	r++;
	while (1)
	{
		a[r] = a[r - 1] + 1 + r + 2 + a[r - 1];
		r++;
		if (a[r - 1] >= n)
		{
			break;
		}
	}
//	printf("r:%d\n", r);
//	for (int i = 0; i < r; i++)
//		printf(" a[%d]:%d ", i,a[i]);
//	printf("\n");
//	printf("r:%d n:%d\n", r-1, n - 1);
	recursion(r-1, n-1);
}

void recursion(int r, int n)
{
	if (r == 0)
	{
		if (n == 0)
		{
			printf("m");
			return;
		}
		else if (n == 1||n==2)
		{
			printf("o");
			return;
		}
	}
	else
	{
		//printf("ㅋㅊㅌㅍ");
		if (0 <= n && n < a[r - 1])
		{
		//	printf("가r:%d n:%d\n", r - 1, n);
			recursion(r - 1, n);
		}
		else if (n == a[r - 1])
		{
			printf("m");
			return;
		}
		else if (a[r - 1] + 1 <= n && n < a[r - 1] + 1 + r + 2)
		{
			printf("o");
			return;
		}
		else if (a[r - 1] + 1 + r + 2 <= n && n < a[r])
		{
		//	printf("나r:%d n:%d\n", r - 1, n - a[r - 1] - r - 3);
			recursion(r - 1, n - a[r - 1] - r - 3);
		}
	}
	
}