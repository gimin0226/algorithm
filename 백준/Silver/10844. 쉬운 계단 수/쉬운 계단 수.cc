#include<bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long arr[101][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				arr[i][j] =(arr[i][j]+ arr[i - 1][j - 1])% 1000000000;
			}
			if (j + 1 <= 9) {
				arr[i][j]=(arr[i][j]+ arr[i - 1][j + 1]) % 1000000000;
			}
		}
	}
/*
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}cout << endl;
	}
	*/
	long long sum = 0;
	for (int i = 1; i < 10; i++) {
		sum = (sum+arr[n][i])%1000000000;
	}
	cout << sum;
	return 0;
}