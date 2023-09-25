#include <bits/stdc++.h>
using namespace std;
int dx[]{ 0,0,1,1,2,2 };
int dy[]{ 1,2,0,2,0,1 };
int arr[1001][3];


const int INF = INT_MAX;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	int a, b, c;
	int minn=INF ;
	for (int t = 0; t < 6; t++) {
		int dp[1001][3];
		int x = dx[t];
		int y = dy[t];
		for (int i = 0; i < 3; i++) {
			if (i == x) dp[0][i] = arr[0][i];
			else dp[0][i] = 1001;

			if (i == y)dp[n - 1][i] = arr[n - 1][i];
			else dp[n - 1][i] = 1001;

		}

		for (int i = 1; i < n-1; i++) {
			
			dp[i][0] = arr[i][0]+min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		switch (y) {
		case 1:
			dp[n - 1][1] = arr[n - 1][1] + min(dp[n - 2][0], dp[n - 2][2]);
			break;
		case 2:
			dp[n - 1][2] = arr[n - 1][2] + min(dp[n - 2][0], dp[n - 2][1]);
			break;
		case 0:
			dp[n - 1][0] = arr[n - 1][0] + min(dp[n - 2][1], dp[n - 2][2]);
			break;
		}
		/*
		for (int i = 0; i < n; i++) {
			printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
		}cout << endl;
		*/
		minn = min(minn, dp[n-1][y]);

	}

	cout << minn;
}
