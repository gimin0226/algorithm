#include<bits/stdc++.h>

using namespace std;
int t;
int n, m;
int dp[31][201][201] = { 0 };
int arr[201][201];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int dx2[]{ -1, -2,-2,-1,1,2,2,1 };
int dy2[]{ -2, -1,1,2,-2,-1,1,2 };
void bfs() {
	queue<tuple<int, int, int>> que;//x,y,t사용 횟수, 이동 횟수, 이동하면서 건너뛰기 씀?
	que.push({ 0,0,0 });
	while (!que.empty()) {
		int x, y, num;
		tie(x, y, num) = que.front();
		que.pop();
	//	printf("x:%d y:%d num:%d dp[num][x][y]:%d\n", x, y, num, dp[num][x][y]);
	/*	if (x == n - 1 && y == m - 1) {
			cout << dp[num][x][y];
			return;
		}*/
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == n - 1 && ny == m - 1) {
				cout << dp[num][x][y]+1;
				return;
			}
			if (nx < 0 || ny < 0 || nx>n - 1 || ny>m - 1)continue;
			if (dp[num][nx][ny] != 0)continue;
			if (arr[nx][ny] == 0) {
				que.push({ nx,ny,num });
				dp[num][nx][ny] = dp[num][x][y] + 1;
			}
		}
		if (num <t) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx2[i];
				int ny = y + dy2[i];
				if (nx == n - 1 && ny == m - 1) {
					cout << dp[num][x][y]+1;
					return;
				}
				if (nx < 0 || ny < 0 || nx>n  - 1 || ny>m - 1)continue;
				if (dp[num + 1][nx][ny] != 0)continue;
				if (arr[nx][ny] == 0) {
					dp[num + 1][nx][ny] = dp[num][x][y] + 1;
					que.push({ nx,ny,num + 1 });
				}
			}
		}
	}
	cout << "-1";

}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	cin >>m>>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	if (n == 1 && m == 1) {
		cout << "0";
		return 0;
	}
	bfs();
		

}