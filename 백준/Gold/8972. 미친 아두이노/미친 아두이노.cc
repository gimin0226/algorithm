#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int n, m;
char arr[101][101];
int dx[]{0, 1,1,1,0,0,0,-1,-1,-1 };
int dy[]{0, -1,0,1,-1,0,1,-1,0,1 };
vector<int> v;
pair<int,int> ard;
queue<pair<int, int>> que;
queue<pair<int, int>> ex;
int che[101][101] = { 0 };
int f(int x, int y, int nx, int ny) {
	int x2, y2;
	if (x == nx) {
		x2 = x;
		if (y > ny) y2 = y - 1;
		else if (y < ny) y2 = y + 1;
	}
	else if (x > nx) {
		x2 = x - 1;
		if (y > ny) y2 = y - 1;
		else if (y == ny) y2 = y;
		else if (y < ny) y2 = y + 1;
	}
	else if (x < nx) {
		x2 = x + 1;
		if (y > ny) y2 = y - 1;
		else if (y == ny) y2 = y;
		else if (y < ny) y2 = y + 1;
	}
	//printf("x:%d y:%d x2:%d y2:%d\n", x, y, x2, y2);
	if (arr[x2][y2] == 'I') {
		return -1;
	}
	che[x][y]--;
	che[x2][y2]++;
	return 0;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'I') {
				ard.first= i;
				ard.second = j;
				che[i][j] = -1;
			}
			else if (arr[i][j] == 'R') {
				que.push({ i,j });
				che[i][j]++;
			}
		}
	}
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str[i] - '0');
	}

	for (int t = 0; t < v.size(); t++) {

		int nx = ard.first + dx[v[t]];
		int ny = ard.second + dy[v[t]];
		if (arr[nx][ny] == 'R') {
			cout << "kraj " << t + 1 << endl;
			return 0;
		}
		else {
			arr[ard.first][ard.second] = '.';
			che[ard.first][ard.second] = 0;
			che[nx][ny] = -1;
			arr[nx][ny] = 'I';
			ard.first = nx; ard.second = ny;
		}

		int que_size= que.size();
		for (int i = 0; i < que_size; i++) {
			int x, y;
			tie(x, y) = que.front();
			que.pop();
			int q=f(x, y, nx, ny);
			if (q == -1) {
				cout << "kraj " << t + 1 << endl;
				return 0;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (che[i][j] == 0)arr[i][j] = '.';
				else if (che[i][j] == 1) {
					arr[i][j] = 'R';
					que.push({ i,j });
				}
				else if (che[i][j] > 1) {
					arr[i][j] = '.';
					che[i][j] = 0;
				}
			}
		}
		
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j];
			}cout << endl;
		}
		cout << endl;*/
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}cout << endl;
	}

}