#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int dp[51][51][51] = { 0 };
int w(int a, int b, int c) {
	//cout << a << " " << b << " " << c << " " << dp[a][b][c] << "\n";
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (dp[a][b][c] != 0)return dp[a][b][c];
	
	if (a > 20 || b > 20 || c > 20)return dp[a][b][c] = w(20,20,20);
	else if (a < b && b < c)return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return dp[a][b][c]=w(a - 1, b, c) +w(a-1,b-1,c)+ w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	//ios::sync_with_stdio(false);
	
	while (true) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				for (int t = 0; t < 51; t++) {
					dp[i][j][t] = 0;
				}
			}
		}
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	
}
