#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int add[11][11];
int arr[11][11];
vector<int> ar[11][11];
queue<pair<int, int>> que; //번식하는 나무 저장 (5의 배수인 나무)
vector<int> vec[11][11];

//나이 , x, y
queue<tuple<int, int, int>> die;//죽은 나무 저장 나이 ,x, y
int sum[11][11];
int dx[]{ -1,-1,-1,0,0,1,1,1 };
int dy[]{ -1,0,1,-1,1,-1,0,1 };
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> add[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x>>y >> age;
		vec[x][y].push_back(age);
	}
	for (int t = 0; t < k; t++) {
		int sum[11][11] = { 0 };
		//봄
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (vec[i][j].size() == 0)continue;
				sort(vec[i][j].begin(), vec[i][j].end());

				int p = vec[i][j].size();
				for (int t = 0; t < vec[i][j].size(); ) {
					int age = vec[i][j][t];
					if (age <= arr[i][j]) {
						arr[i][j] -= age;
						vec[i][j][t]+=1;
						t++;
						if ((age + 1) % 5 == 0) {
							que.push({ i,j });
						}
	
					}
					else {
						sum[i][j] += age / 2;
						vec[i][j].erase(vec[i][j].begin()+t);
						
					}
				}
			}
		}
		

		//여름

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] += sum[i][j];
			}
		}
		//가을

		int p = que.size();
		for (int i = 0; i < p; i++) {
			int x, y;
			tie( x, y) = que.front();
			que.pop();
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx<1 || ny<1 || nx>n  || ny>n )continue;
				vec[nx][ny].push_back(1);
		//		printf("%d %d\n", nx, ny);
			}
		}

		//겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] += add[i][j];
			}
		}
	}
	int summ = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vec[i][j].size() == 0)continue;
			summ += vec[i][j].size();
		}
	}
	cout << summ;
}