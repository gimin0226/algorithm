#define _CRT_SECURE_NO_WARNINGS	
#include <cstdio>
int main(void)
{
	int n;
	scanf("%d", &n);
	int a[6];
	for (int i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	int max = a[0];
	
	for (int i = 0; i < 6; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	
	if (n == 1)
	{
		printf("%d", a[0] + a[1] + a[2] + a[3] + a[4] + a[5] - max);
		return 0;
	}
	int min1 = a[0];
	for (int i = 0; i < 6; i++)
	{
		if (min1 > a[i])
			min1 = a[i];
	}

	int b[12];
	b[0] = a[0] + a[4]; b[1] = a[1] + a[5]; b[2] = a[1] + a[2];
	b[3] = a[0] + a[3]; b[4] = a[2] + a[5]; b[5] = a[1] + a[3];
	b[6] = a[0] + a[2]; b[7] = a[4] + a[5]; b[8] = a[3] + a[4];
	b[9] = a[0] + a[1]; b[10] = a[3] + a[5]; b[11] = a[2] + a[4];

	int min2 = b[0];
	for (int i = 0; i < 12; i++)
	{
		if (min2 > b[i])
			min2 = b[i];
	}

	int c[8];
	c[0] = a[0] + a[2] + a[4]; c[1] = a[0] + a[2] + a[1];
	c[2] = a[0] + a[1] + a[3]; c[3] = a[0] + a[3] + a[4];
	c[4] = a[1] + a[2] + a[5]; c[5] = a[1] + a[3] + a[5];
	c[6] = a[3] + a[4] + a[5]; c[7] = a[2] + a[4] + a[5];

	int min3 = c[0];
	for (int i = 0; i < 8; i++)
	{
		if (min3 > c[i])
			min3 = c[i];
	}

	if (n == 2)
	{
		printf("%d", 4 * min3 + 4 * min2);
		return 0;
	}

	
	long long one, two, three;
	one =((long long) (n - 2) * (n - 1) * 4 + (long long)(n - 2) * (n - 2) )*min1;
	two = ((long long)(n - 1) * 4 + (n - 2) * 4) * min2;
	three = 4  * min3;
	printf("%lld", one + two + three);
	return 0;
}