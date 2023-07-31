#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		unsigned long long A=a, B=b;
		unsigned long long x;
		int n = 0;
		
		while (1)
		{
			unsigned long long gcd2;
			unsigned long long a3, b3;
			a3 = A;
			b3 = B;
			while (1)
			{
				
				if (a3 == 0)
				{
					gcd2 = b3;
					break;
				}
				unsigned long long p = b3;
				b3 = a3;
				a3 = p % a3;
			}
			B = B / gcd2;
			A = A / gcd2;
			if (A == 1)
			{
				printf("%llu\n", B);
				break;
			}
			
			x = B / A + 1;
			
			unsigned long long b1 = B;
			unsigned long long b2 = x;
			unsigned long long gcd;
			if (b1 >= b2)
			{
				while (1)
				{
					if (b2 == 0)
					{
						gcd = b1;
						break;
					}
					unsigned long long p = b1;
					b1 = b2;
					b2 = p % b2;
					

				}
			}
			else if (b1 < b2)
			{
				while (1)
				{
					if (b1 == 0)
					{
						gcd = b2;
						break;
					}
					unsigned long long p = b2;
					b2 = b1;
					b1 = p % b1;
				}
			}
			
			unsigned long long lcm = gcd * (B / gcd) * (x / gcd);
			
			A = A*(lcm/B) - 1 * (lcm/x);
			
			B = lcm;
			
		
			if (A == 1)
			{
				printf("%llu\n", B);
				break;
			}
			
			
			n++;

		}
	}
}