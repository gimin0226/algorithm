#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c= b / a;
	int k=0;

	if (a == b)
	{
		printf("%d %d", a, a);
		return 0;
	}
	for (int i = 0; i < c; i++)
	{
		if(i*i<=c&&(i+1)*(i+1)>c)
		{
			k = i;
			break;
		}
	}



	int A[10000];
	int B[10000];
	int t = 0;
	for (int i = 1; i <= k; i++)
	{
		if (c % i == 0)
		{
			A[t] = i;
			B[t] = c/ i;
			t++;
		}
	}
	
	for (int i = 0; i <t; i++)
	{
		for (int j = 2; j <= A[i]; j++)
		{
			if (A[i] % j == 0 && B[i] % j == 0)
			{
				A[i] = 0;
				B[i] = 0;
				break;
			}
		}
	}
	
	int C[10000];
	for (int i = 0; i < t; i++)
	{
		C[i] = A[i] + B[i];
	}

	int min = C[0];
	int p= 0;
	for (int i = 0; i < t; i++)
	{
		if (min > C[i]&&C[i]!=0)
		{
			p= i;
			min = C[i];
		}
	}
	printf("%d %d", a*A[p], a*B[p]);
	return 0;
}