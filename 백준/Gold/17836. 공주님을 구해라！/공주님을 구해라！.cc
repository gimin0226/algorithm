#include<bits/stdc++.h>

using namespace std;

bool visited[101][101] = { false };
int arr[101][101];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

int main(void) {
	int n, m, ti;
	cin >> n >> m >> ti;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			arr[i][j] = t;
		}
	}

	queue<tuple<int, int,int>> que;
	que.push({ 0,0,0 });
	visited[0][0] = true;
	int minn = INT_MAX;
	while (true) {
		

		if (que.empty()) {
			break;
		}
		int x, y, time;
		tie(x, y, time) = que.front();
		//cout << x << " " << y << " " << time << endl;
		que.pop();
		if (time > ti) {
			continue;
		}
		if (x == n - 1&& y == m - 1) {
			//cout << "fsaasf";
			//cout << time << endl;
			minn = min(minn, time);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
			if (visited[nx][ny] == true)continue;
			visited[nx][ny] = true;

			if (arr[nx][ny] == 0) {
				que.push({ nx,ny,time+1 });
			}
			else if (arr[nx][ny] == 2) {
				int t = (n - 1 - nx) + (m - 1 - ny);
				if (time +1+ t  > ti)continue;
				minn = min(minn, time+1+t);
				//cout << "fsaasdfsa" <<time<< minn << endl;
			}
		}

	}
	if (minn == INT_MAX) {
		cout << "Fail";
	}
	else {
		cout << minn;
	}
	return 0;
	
}
