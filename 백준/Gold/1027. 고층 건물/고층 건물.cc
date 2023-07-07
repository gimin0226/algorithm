#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);

	long long y[51];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &y[i]);
	}
	
	int num[51]={0};
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			else if (j == i - 1||j==i+1)
			{
				num[i]++;
				continue;
			}
			else if (j > i)
			{
				for (int k = i+1; k < j; k++)
				{
					if ((y[k] - y[i]) * (j - i) >= (y[j] - y[i]) * (k - i))
					{
						break;
					}
					if (k == j - 1)
					{
						num[i]++;
					}
				}
			}
			else if (j < i)
			{
				for (int k = j + 1; k < i; k++)
				{
					if ((y[k] - y[i]) * (i-j) >= (y[i] - y[j]) * (k - i))
					{
						break;
					}
					if (k == i- 1)
					{
						num[i]++;
					}
				}
			}
		}
	}


	int max = num[0];
	for (int i = 0; i < n; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	printf("%d", max);
	return 0;
}