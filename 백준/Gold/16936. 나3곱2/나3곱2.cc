#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void)
{
	int N;
	scanf("%d", &N);
	long long a[101][3] = { 0 };
	long long b[101];
	long long c[101]={0};
	for (int i = 0; i < N; i++)
		scanf("%lld", &b[i]);
	
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			a[i][1] = b[i];
			if (a[i][1] / 3 == b[j]&&a[i][1]%3==0)
			{
				a[i][2] = b[j];
			}
			if (a[i][1] * 3 == b[j])
			{
				a[i][0] = b[j];
			}
			if (a[i][1] * 2 == b[j])
			{
				a[i][2] = b[j];
			}
			if (a[i][1] / 2 == b[j]&&a[i][1]%2==0)
			{
				a[i][0] = b[j];
			}

		}
		if (a[i][0] == 0)
		{
			c[0] = a[i][1];
			c[1] = a[i][2];
		}

		if (a[i][2] == 0)
		{
			c[N - 1] = a[i][1];
			c[N - 2] = a[i][0];
		}
	}
	
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++)
		printf("%d ", c[i]);
	printf("\n");
	*/


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (c[i] == a[j][0] && c[i + 1] == a[j][1])
			{
				c[i + 2] = a[j][2];
			}
			
		
		}
		
	}


	for (int i = 0; i < N; i++)
		printf("%lld ", c[i]);


	return 0;

}