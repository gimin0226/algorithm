#include<bits/stdc++.h>

using namespace std;

int n, h, d;
char arr[501][501];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int visited[501][501] = { 0 };
int sta[2];
int en[2];
vector<pair<int, int>> v;
void bfs() {
	queue<tuple<int, int, int, int, int>> que; //x  y  life ulife num
	que.push({ sta[0],sta[1],h,0,0 });
	visited[sta[0]][sta[1]] = h;
	arr[sta[0]][sta[1]] = '.';
	while (!que.empty()) {
		int x, y, life, ulife, num;
		tie(x, y, life, ulife, num) = que.front();
		que.pop();
			//printf("x:%d y:%d life:%d ulife:%d num:%d\n", x, y, life, ulife, num);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_ulife, next_life;
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)continue;
			if (life == 1 && ulife == 0 && arr[nx][ny] == '.') continue;

			if (arr[nx][ny] == 'U') {
				next_life = life;
				next_ulife = d - 1;
			}
			else if (arr[nx][ny] == 'E') {
				cout << num + 1;
				return;
			}
			else if (arr[nx][ny] == '.') {
				if (ulife > 0) {
					next_life = life;
					next_ulife = ulife - 1;
				}
				else {
					next_life = life - 1;
					next_ulife = ulife;
				}
			}
			if (visited[nx][ny] >= next_life + next_ulife)continue;
			que.push({ nx,ny,next_life,next_ulife,num + 1 });
			visited[nx][ny] = next_life + next_ulife;


		}
	}
	cout << "-1";
	return;
}



int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> h >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sta[0] = i; sta[1] = j;
			}
			else if (arr[i][j] == 'E') {
				en[0] = i; en[1] = j;
			}
			else if (arr[i][j] == 'U') {
				v.push_back({ i,j });
			}
		}
	}
	bfs();


}