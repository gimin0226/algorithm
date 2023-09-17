#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int arr[64][64];
void recursion(int n, int x1, int x2, int y1, int y2);

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	recursion(n, 0, n, 0, n);
	return 0;
}

void recursion(int n,int x1,int x2,int y1,int y2)
{
	
	int k = arr[y1][x1];
	int ptr = 0;
	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			if (arr[i][j] != k)
			{
				ptr++;
				break;
			}
			if (i == y2 - 1 && j == x2 - 1)
			{
				printf("%d", k);
				return;
			}
		}
		if (ptr == 1)
		{
			break;
		}
	}
	int N = n / 2;
	printf("(");
	recursion(N, x1 + 0, x1 + N, y1 + 0, y1 + N);
	recursion(N, x1 + N, x1 + 2*N, y1 + 0, y1 + N);
	recursion(N, x1 + 0, x1 + N, y1 + N, y1 + 2*N);
	recursion(N, x1 + N, x1 + 2*N, y1 + N, y1 +2*N);
	printf(")");


}