#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void)
{
	int t;
	scanf("%d", &t);
	
	int p = 0;
	while (p != t)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int dis = y - x;
		int num = 0;
		long long sum = 0;
		int k = 1;
		for (int i = 1; i < dis; i++)
		{
			sum += i;
			sum += i - 1;
			if (sum <= dis && (sum + 2 * i + 1) > dis)
			{
				k = i;
				num = 2 * i - 1;
				break;
			}
		}
		int newdis = dis - sum;
		if (newdis > k)
			num += 2;
		else if (newdis == 0)
			num += 0;
		else if (newdis <= k)
			num += 1;
		printf("%d\n", num);
		p++;
	}
	return 0;

}