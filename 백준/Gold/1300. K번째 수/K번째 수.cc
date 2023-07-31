#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	

int main(void)
{
	unsigned long long n;
	unsigned long long m;
	scanf("%llu", &n);
	scanf("%llu", &m);

	unsigned long long low, mid;
	unsigned long long high = n * n;
	low = 0;
	unsigned long long sum = 0;
	unsigned long long num;
	
//	printf("%llu %lld\n", high, low);
	while (1)
	{
		if (low > high)
		{
			break;
		}
		sum = 0;
		num = 0;
		mid = (low + high) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (i * n < mid)
			{
				sum +=  n;
			}
			else
			{
				if (mid % i == 0)
				{
					sum += mid / i - 1;
					num++;
				}
				else if (mid % i != 0)
				{
					sum += mid / i;
				}
			}
		}
		//printf("%lld %lld %lld ", low, mid, high);
		//printf("%lld\n", sum);
		if (num >= 1)
		{
			for (int i = 1; i <= num; i++)
			{
				if (sum + i == m)
				{
					printf("%lld", mid);
					return 0;
				}
			}
			sum += 1;
		}
		if (sum >= m)
		{
			high = mid - 1;
		}
		
		else if (sum < m)
		{
			low = mid + 1;
		}


	}
}