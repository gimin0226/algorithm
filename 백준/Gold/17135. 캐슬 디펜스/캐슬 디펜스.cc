#include<bits/stdc++.h>
using namespace std;
int arr[17][16];

int dx[]{ 0,-1,0 };
int dy[]{ -1,0,1 };
int n, m, d;
deque<int> dq;
bool che[16];

int maxx = 0;
int start = n;
int num = 0;
bool bfs() {
	vector<int> vec;
	int ch = 0;

	for (int i = 0; i < start; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				ch = 1;
				break;


			}
			if (i == start - 1 && j == m - 1) {
				return 0;
			}
		}
		if (ch)break;
	}
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
		vec.push_back(*it);
	}



	queue<pair<int, int>> que2;
	for (int c = 0; c < vec.size(); c++) {
		queue<pair<int, int>> que;
		que.push({ start,vec[c] });
		int check[17][16] = { 0 };
		for (int i = 0; i < m; i++) {
			check[start][i] = 1;
		}
		int ch = 0;
		while (!que.empty()) {
			int x, y;
			tie(x, y) = que.front();
			que.pop();
			for (int i = 0; i < 3; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				//if (x == 4 && y == 2)cout << nx << " " << ny << " " << check[nx][ny] << endl;
				if (nx<0 || ny<0 || nx>start - 1 || ny>m - 1)continue;
				if (check[nx][ny])continue;
				check[nx][ny] = 1;

				if (arr[nx][ny] == 1) {
					int t = abs(nx - start) + abs(ny - vec[c]);
					if (t <= d) {
						que2.push({ nx,ny });
					//	cout << start << " " << vec[c] << " " << nx << " " << ny << endl;
						ch++;
						break;
					}
				}
				else if (arr[nx][ny] == 0) {
					int t = abs(nx - start) + abs(ny - vec[c]);
					if (t == d) {
						continue;
					}if (t <= d) {
						que.push({ nx,ny });
					}
				}
			}
			if (ch == 1)break;
		}
	}

	while (!que2.empty()) {
		int x, y;
		tie(x, y) = que2.front();
		que2.pop();
		if (arr[x][y] == 1) {
			arr[x][y] = 0;
			num++;
		}

	}
	start--;
	return 1;
}


void BackTracking(int x) {
	if (x == 3) {
	//	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
	//		cout << *it << " ";
	//	}
		//cout << "dswfafsdafsadfsaa" << endl;
		num = 0;
		start = n;
		int arr2[17][16];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr2[i][j] = arr[i][j];
			}
		}
		while (true) {
			if (!bfs()) break;
			if (start == 0)break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = arr2[i][j];
			}
		}
		maxx = max(num, maxx);
		//	cout << num << endl;
		return;
	}
	for (int i = 0; i < m; i++) {
		if (che[i])continue;
		dq.push_back(i);
		che[i] = true;
		BackTracking(x + 1);
		dq.pop_back();
		che[i] = false;

	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	BackTracking(0);
	cout << maxx;
}