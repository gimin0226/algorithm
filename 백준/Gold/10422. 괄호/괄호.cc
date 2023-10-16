#include <iostream>

#define MOD	1000000007

using namespace std;

long long arr[5001];

void init()
{
	int i, j;

	arr[0] = 1;
	for (i = 2; i <= 5000; i += 2)
	{
		for (j = 2; j <= i; j += 2)
		{
			arr[i] +=arr[i - j]*arr[j - 2];
			arr[i] %= MOD;
		}
	}
}

int main()
{
	int t, T, L;

	init();
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> L;
		cout << arr[L] << endl;
	}
	return 0;
}