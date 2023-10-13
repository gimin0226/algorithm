#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int dp[501][501] = { 0 };
int maxx = 0;
int check[501][501] = { 0 };

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

int n;

int dfs(int x,int y) {
	//cout << x << " " << y << '\n';
	int stop = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny > n - 1)continue;
		
		
		if (arr[nx][ny] > arr[x][y]) {
			if (check[nx][ny] == 0) {
				check[nx][ny] = 1;
				stop = 1;
				int t = dfs(nx, ny);
				dp[x][y] = max(t, dp[x][y]);
			}
			else if (check[nx][ny] == 1) {
				int t = dp[nx][ny]+1;
				dp[x][y] = max(t, dp[x][y]);
			}
		}
	}
	maxx = max(dp[x][y], maxx);
	return dp[x][y]+1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 1)continue;
			check[i][j] = 1;
			int t=dfs(i, j);
		//	dp[i][j] = max(t, dp[i][j]);
			maxx = max(dp[i][j], maxx);
		//	cout <<" afasasd"<< i << " " << j << " " << dp[i][j] << '\n';
		}
	}

/*	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}cout << endl;
	}*/
	cout << maxx;
	return 0;
}