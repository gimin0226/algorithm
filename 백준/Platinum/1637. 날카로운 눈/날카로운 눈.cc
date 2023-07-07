#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	long long* a = (long long*)malloc(sizeof(long long) * n);
	long long* b = (long long*)malloc(sizeof(long long) * n);
	long long* c = (long long*)malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld %lld", &a[i], &c[i], &b[i]);
	long long max = c[0];
	for (int i = 0; i < n; i++)
	{
		if (max < c[i])
		{
			max = c[i];
		}
	}

	long long low, mid, high;
	low = 0;
	high = max;
	long long num = 0;
	long long left = 0;
	long long right = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (c[i] - a[i]) / b[i] + 1;
		//printf("sum:%d\n", sum);
	}
	//printf("sum:%d\n", sum);
	//printf("%d", sum);
	if (sum % 2 == 0)
	{
		printf("NOTHING");
		return 0;
	}
	
	while (1)
	{
		if (low > high)
		{
			printf("NOTHING");
			return 0;
		}
		num = 0;
		left = 0;
		right = 0;
		mid = (low + high) / 2;
		
		for (int i = 0; i < n; i++)
		{
			
			if (mid <= c[i] && mid>=a[i]&&(mid - a[i]) % b[i] == 0)
			{
				num++;
				//printf("%d %d %d", a[i], c[i], b[i]);
			}
			
			if (mid < a[i])
			{
				left += 0;
			}
			else if (mid > c[i])
			{
				left += (c[i] - a[i]) / b[i] + 1;
			}
			else 
			{
				if ((mid - a[i]) % b[i] != 0)
				{
					left += (mid - a[i]) / b[i] + 1;
				//	printf("%d ", left);
				}
				if ((mid - a[i]) % b[i] == 0)
				{
					left += (mid - a[i]) / b[i];
				//	printf("%d ", left);
				}
			}
		}
		right = sum - left;
		//printf("mid:%d num:%d sum:%d left:%d right:%d\n", mid, num,sum, left, right);
		if (num % 2 == 1)
		{
			printf("%lld %lld", mid, num);
			return 0;
		}
		else if (num % 2 == 0)
		{
			if (left % 2 == 1)
			{
				high = mid - 1;
			}
			else if (right % 2 == 1)
			{
				low = mid + 1;
			}
		}
	}

}