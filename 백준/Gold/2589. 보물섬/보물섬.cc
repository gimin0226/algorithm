#include<bits/stdc++.h>

using namespace std;

char arr[51][51];
vector<pair<int, int>> vec;
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

int main(void) {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			arr[i][j] = t;
			if (t == 'L') {
				vec.push_back({i,j});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		queue<tuple<int, int, int>> que;
		que.push({ vec[i].first,vec[i].second,0 });
		int visited[51][51] = { false };
		visited[vec[i].first][vec[i].second] = true;
		while (true) {
			if (que.empty()) {
				break;
			}
			int x, y, time;
			tie(x, y, time) = que.front(); que.pop();
			ans = max(ans, time);

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
				if (visited[nx][ny] == true)continue;
				visited[nx][ny] = true;

				if (arr[nx][ny] == 'L') {
					que.push({nx,ny,time + 1 });
				}
			}
		}
	}

	cout << ans;
	


	return 0;
	
}
