#include<bits/stdc++.h>

using namespace std;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
	int n, a, b;
	cin >> n >> a >> b;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			arr[i][j] = t;
		}
	}
	
	int day = 0;
	
	while (true) {
		int open = 0;
		int check[51][51] = { 0 };


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 1) {
					continue;
				}
				queue<pair< int,int>> que;
				que.push({ i,j}); //x y num sum
				vector<pair<int, int>> vec;
				vec.push_back({ i,j });
				check[i][j] = 1;
				int num2 = 1;
				int sum2 =arr[i][j];
				while (true) {
					if (que.empty()) {
						int N = vec.size();
						if (N == 1) {
							break;
						}
						int value = sum2 / N;
						//cout << sum2 << " " << N << endl;
						for (int t = 0; t < N; t++) {
							int x, y;
							tie(x, y) = vec[t];
						//	cout << x << "," << y << " ";
							
							
							arr[x][y] = value;
						}
						break;
					}
					int x, y;
					tie(x, y) = que.front();

					que.pop();
					for (int t = 0; t < 4; t++) {
						int nx = x + dx[t];
						int ny = y + dy[t];

						if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) {
							continue;
						}

						if (check[nx][ny]==0&&abs(arr[nx][ny] - arr[x][y]) >= a && abs(arr[nx][ny] - arr[x][y]) <= b) {
							//cout << nx << " " << ny<<'\n';
							que.push({ nx,ny });
							vec.push_back({ nx,ny });
							check[nx][ny] = 1;
							num2 +=1;
							sum2 += arr[nx][ny];
							open++;
						}
					}
				}
			}
		}

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}cout << endl;
		}cout << endl;*/
		if (open == 0) {

			break;
		}
		day++;
	}
	cout << day;
}