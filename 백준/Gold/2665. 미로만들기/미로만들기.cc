#include <bits/stdc++.h>

using namespace std;

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

int main(void) {
	int n; cin >> n;
	int arr[51][51];
	int visited[51][51] = { 0 };
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	deque<tuple<int, int, int>> dq;
	dq.push_back({ 0, 0,0 });

	while (true) {
		int x, y, idx;
		tie(x, y, idx) = dq.front();
		dq.pop_front();
		//printf("x:%d y:%d idx:%d\n", x, y, idx);
		if (x == n - 1 && y == n - 1) {
			cout << idx;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1)continue;

			if (visited[nx][ny] == 1)continue;
			visited[nx][ny] = 1;

			if (arr[nx][ny] == 0) {
				dq.push_back({ nx,ny,idx + 1 });
			}
			else if (arr[nx][ny] == 1) {
				dq.push_front({ nx,ny,idx });
			}
		}
	}
}