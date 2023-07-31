#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int a[21][2];
int n;
int num = 0;
int num2 = 0;
int recursion(int x, int y, int z);
int main(void)
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	scanf("%d", &n);
	int q, w, e;
	for (int i = n-1; i >=0; i--)
	{
		scanf("%d %d", &q, &w);
		e = 1;
		for (int j = 0; j < q; j++)
			e *= 2;
		a[i][0] = e;
		a[i][1] = w;
		num += a[i][1];
	
	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %d\n", a[i][0], a[i][1]);
//	}
//	printf("num:%d\n", num);
	
	recursion(x, y, z);
	printf("%d", num2);
	return 0;
}

int recursion(int x, int y, int z)
{
	int t;
//	printf("x:%d y:%d z:%d num2:%d\n", x, y , z,num2);

	for (int i = 0; i < n; i++)
	{
		if (a[i][1] != 0 && a[i][0] <= x && a[i][0] <= y && a[i][0] <= z)
		{
			t = a[i][0];
		//	printf("t:%d\n", t);
			a[i][1]--;
			break;
		}
		if (i == n - 1)
		{
			printf("-1");
			exit(0);
		}
	}
	num2++;
	if (y - t >0)
	{
		//printf("가");
		recursion(t, y - t, z);
	}
	if (x - t > 0)
	{
		//printf("나");
	
		recursion(x - t, t, z);
	}
	if (x - t >0 && y - t > 0)
	{
		//printf("다");
	
		recursion(x - t, y - t, z);
	}
	if (z-t>= 0)
	{
		//printf("라");
	
		if (z - t == 0)
		{
			//printf("끝");
			return 0;
		}
		recursion(t, t, z - t);
	}
	return 0;

}
	