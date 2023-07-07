#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int* x = a;
	int* y = a;
	int sum1 = 0;
	int sum2 = 0;
	int sum = 0;
	int num[100001] = { 0 };
	int j = 2;
	int ptr = 0;
	for (int i = 0;i<n;i++)
	{
		sum1 = *x;
		if(i!=0)
			sum2 -= *x;
		sum = sum1 + sum2;
		j--;
		while (sum<m)
		{
			if (*y==0)
			{
				ptr = 1;
				break;
			}
			y++;
			sum2 += *y;
			sum = sum1 + sum2;
			j++;
			
		}
		if (ptr == 1)
			break;
		num[i] = j;
		x++;
	}
	int min = num[0];
	for (int i = 0; i < n; i++)
	{
		if (num[i] != 0 && min > num[i])
		{
			min = num[i];
		}
	}
	printf("%d", min);
}