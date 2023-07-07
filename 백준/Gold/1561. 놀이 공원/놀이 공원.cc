#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	
int b[10000];
int main(void)
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	int* a;
	a = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);

	long long max = a[0];
	for (int i = 0; i < m; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	long long low, mid, high;
	high =(long long) n * max;
	low = 0;
	long long num=0;
	long long sum=0;

	int j = 0;
	while (1)
	{
		
		j = 0;
		if (low > high)
		{
			break;
		}
		mid = (low + high) / 2;
		sum = 0;
		num = 0;
	//	printf("%d %d %d", low, mid, high);
		for (int i = 0; i < m; i++)
		{
			if (mid % a[i] == 0)
			{
				num++;
				b[j] = i+1;
		//		printf("b[%d]:%d", j, b[j]);
				j++;
				sum += mid / a[i];
			}
			else if (mid % a[i] != 0)
			{
				sum += mid / a[i] + 1;
			}
		}
	//	printf(" %d %d\n", sum, m);
		if (num >= 1)
		{
			if (sum < n && n <= sum + num)
			{
				int t =j-( sum + num - n)-1;
			//	printf("%d ", t);
				printf("%d", b[t]);
				return 0;
			}
		}
		if (sum >= n)
		{
			high = mid - 1;
		}
		else if (sum < n)
		{
			low = mid + 1;
		}
	
	}
}