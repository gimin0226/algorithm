#include<bits/stdc++.h>	

using namespace std;

static int INF = INT_MAX;
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int main(void) {
	int n, m;
	cin >> m >> n;
	int arr[101][101];

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			arr[i][j]=str[j] - '0';
		}
	}
	

	deque<tuple<int,int, int>> dq;

	dq.push_front({ 0,0,0 });

	int dist[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
	while (true) {
		int x, y,idx;
		tie(x, y,idx) = dq.front();
		dq.pop_front();

		//printf("x:%d y:%d idx:%d dist[x][y]:%d\n", x, y, idx, dist[x][y]);
		if (x == n - 1 && y == m - 1) {
			cout << dist[n-1][m-1];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 && nx>n - 1 && ny<0 && ny>m - 1)continue;

			if (arr[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dq.push_back({ nx,ny,1 });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
			else if (arr[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dq.push_front({ nx,ny,0 });
					dist[nx][ny] = dist[x][y];
				}
			}
		}
	}
}