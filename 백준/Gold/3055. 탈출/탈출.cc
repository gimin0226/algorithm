#include<bits/stdc++.h>	

using namespace std;
char arr[51][51];

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
bool check[51][51] = { false };
bool check2[51][51] = { false };
int main(void) {
	int n, m;
	cin >> n >> m;

	queue<tuple<int, int,int>> start;
	int end[2];
	queue<pair<int, int>> water;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			arr[i][j] = t;

			if (t == 'D') {
				end[0] = i;
				end[1] = j;
				check[i][j] = true;
			}
			else if (t == 'S') {
				start.push({ i,j,0 });
				check2[i][j] = true;
			}
			else if (t == '*') {
				water.push({ i,j });
				check[i][j] = true;
			}
		}
	}

	while (true) {
		if (start.empty()) {
			cout << "KAKTUS";
			return 0;
		}
		int water_size = water.size();
		for (int i = 0; i < water_size; i++) {
			int x, y;
			tie(x, y) = water.front(); water.pop();
		//	printf("water x:%d y:%d\n", x, y);
			
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1)continue;

				if (check[nx][ny]) continue;
				check[nx][ny] = true;

				if (arr[nx][ny] == '.' || arr[nx][ny] == 'S') {
					arr[nx][ny] = '*';
					water.push({ nx,ny });
				//	printf("nx:%d ny:%d\n", nx, ny);
				}
			}
		}
		
		int s_size = start.size();
		for (int i = 0; i < s_size; i++) {
			int x, y, time;
			tie(x, y, time) = start.front(); start.pop();
		//	printf("start x:%d y:%d time:%d\n", x, y,time);
			
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1)continue;

				if (check2[nx][ny]) continue;
				check2[nx][ny] = true;

				if (arr[nx][ny] == '.') {
					start.push({ nx,ny ,time+1});
				}
				else if (arr[nx][ny] == 'D') {
					cout << time+1;
					return 0;
				}
			}

		}


	 }

}