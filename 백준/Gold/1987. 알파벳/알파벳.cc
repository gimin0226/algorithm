#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int n, m;
int a[21][21];
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
//a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
int b[27] = { 0 };
int num = 0;
void recursion(int x, int y, int data);
int max=1;

int main(void)
{

	scanf("%d %d", &n, &m);
	char k;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &k);
		//	printf("%c", k);
			a[i][j] = k - 65;
		//	printf("%d\n", a[i][j]);
		}
		getchar();
	}
/*	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}*/
	num++;
	b[a[0][0]] = 1;
	recursion(0, 0, a[0][0]);
	printf("%d", max);
	return 0;
}


void recursion(int x,int y,int data)
{
	int ptrnum = 0;
	b[data] = 1;
	int ptr[26];
	int num2 = num;
	memmove(ptr, b, sizeof(int) * 26);
	if (x != 0)
	{
		if (b[a[x - 1][y]] == 0)
		{
			ptrnum++;
			b[a[x - 1][y]] = 1;
			num++;
		//	printf("가x:%d y:%d a[x][y]:%d\n", x - 1, y, a[x - 1][y]);
			recursion(x - 1, y, a[x - 1][y]);
		}
	}
	memmove(b, ptr, sizeof(int) * 26);
	num = num2;
	if (x != n-1)
	{
		if (b[a[x + 1][y]] == 0)
		{	
			ptrnum++;
			b[a[x + 1][y]] = 1;
			num++;
			//printf("나x:%d y:%d a[x][y]:%d\n", x + 1, y, a[x +1][y]);

			recursion(x + 1, y, a[x + 1][y]);
		}
	}
	memmove(b, ptr, sizeof(int) * 26);
	num = num2;
	if (y != 0)
	{
		if (b[a[x][y-1]] == 0)
		{
			ptrnum++;
			b[a[x][y-1]] = 1;
			num++;
		//	printf("다x:%d y:%d a[x][y]:%d\n", x , y-1, a[x][y-1]);

			recursion(x, y-1, a[x][y-1]);
		}
	}
	memmove(b, ptr, sizeof(int) * 26);
	num = num2;
	if (y!=m-1)
	{
		if (b[a[x ][y+1]] == 0)
		{
			ptrnum++;
			b[a[x][y+1]] = 1;
			num++;
		//	printf("라x:%d y:%d a[x][y]:%d\n", x, y + 1, a[x][y +1]);

			recursion(x, y+1, a[x][y+1]);
		}
	}
	
	if (ptrnum == 0)
	{
		if (max < num)
		{
			max = num;
		//	printf("max:%d\n", max);
			return ;
		}
	}
}