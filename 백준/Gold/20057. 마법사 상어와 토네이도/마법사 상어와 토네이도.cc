#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int arr[500][500];
int n;
int dx[]{0,1,0,-1};
int dy[]{-1,0,1,0};
int d[][2]{ {0,0}, {0,-2},{-1,-1},{0,-1},{1,-1},{-2,0},{-1,0},{1,0},{2,0},{-1,1},{0,1},{1,1},{0,2} };
int mv[4][13]{ {0,5,10,-1,10,2,7,7,2,1,0,1,0},{0,2,1,7,10,0,0,-1,5,1,7,10,2}, { 0,0,1,0,1,2,7,7,2,10,-1,10,5},{ 0,2,10,7,1,5,-1,0,0,10,7,1,2} };
int sum = 0;
void move_sand(int x, int y, int direct) {
	int t = arr[x][y];
	int che;
	for (int i = 1; i < 13; i++) {
		if (mv[direct][i] == 0)continue;
		else if (mv[direct][i] == -1) {
			che = i;
			continue;
		}
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		int p = arr[x][y] * mv[direct][i] / 100;
		if (nx<0 || ny<0 || nx>n - 1 || ny > n - 1) {
			t -= p;
			sum += p;
		}
		else {
			t -= p;
			arr[nx][ny] += p;
		}
	}
	int nx = x + d[che][0];
	int ny = y + d[che][1];
	if (nx<0 || ny<0 || nx>n - 1 || ny > n - 1) {
		sum += t;
	}
	else {
		arr[nx][ny] += t;
	}
	arr[x][y] = 0;
	
}

void f() {
	int direct = 0;
	int x = n / 2;
	int y = n / 2;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			x = x + dx[direct];
			y = y + dy[direct];
			move_sand(x, y, direct);
			
		}
		direct = (direct + 1) % 4;
		for (int j = 0; j < i; j++) {
			x = x + dx[direct];
			y = y + dy[direct];
			move_sand(x, y, direct);
		}
		direct = (direct + 1) % 4;
	}
	for (int j = 0; j < n-1; j++) {
		x = x + dx[direct];
		y = y + dy[direct];
		move_sand(x, y, direct);
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	f();
	cout << sum;
	
}
