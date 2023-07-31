#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
int main(void)
{
	
		int k;
		scanf("%d", &k);
		int t = 0; // 내가 구하려는 수가 몇 자리로 이루어져 있나
		int sum = 0;
		for (int i = 1; i <= k; i++)
		{

			if (sum < k && sum + pow(2, i) >= k)
			{
				t = i;
				break;
			}
			sum += pow(2, i);

		}
		int num = k - sum; //내가 구하려는 수가 t의 자리수에서 몇 번쨰에 해당하는가
		/*
		printf("%d %d\n", t, num);
		*/

		int* c = (int*)malloc(sizeof(int) * t);
		std::fill(c, c + t, 4);
		if (num == 1)
		{
			for (int i = 0; i < t; i++)
				printf("%d", c[i]);
			return 0;
		}
		
		int sum2 = 1;
		int T = 0;
		int P = num;
		while (1) {
			if (P == 1)
			{
				c[t - 1] = 4;
				break;
			}
			else if (P == 2)
			{
				c[t - 1] = 7;
				break;
			}
			for (int i = 0; i < k; i++)
			{
				if (sum2 < P && sum2 + pow(2, i) >= P)
				{
					T = i + 1;
					c[t - T] = 7;
					break;
				}
				sum2 += pow(2, i);
			}
			P = P - sum2;
			
			sum2 = 1;
			
		}
		for (int i = 0; i < t; i++)
			printf("%d", c[i]);

		return 0;
		
		
}