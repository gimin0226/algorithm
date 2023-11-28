#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int n, win;
int arr[10][10];  //상성표 
int a[3][21]; // 0:지우 1:경희 2:민호 경희 민호가 내는 행동
int che[10] = { 0 };// 지우가 낸 손동작 체크
int winn[3] = { 0 }; //   0:지우 1:경희 2:민호 승 수
int p[3] = { 0 };
int q = 0;
void backTracking(int N,int x,int y, int z) {
	//printf("p[1]:%d p[2]:%d x:%d y:%d z:%d win지우:%d win경희:%d win민호:%d\n", p[1],p[2], x, y, z, winn[0], winn[1], winn[2]);
	if (winn[0] == win) {
		cout << "1";
		exit(0);
	}
	else if (winn[1] == win || winn[2] == win) {
		return;
	}
	
	
	if (x == 0) {
		for (int i = 1; i <= n; i++) {
			if (che[i] == 1)continue;
			che[i] = 1;
			int ny = a[y][p[y]];
			if (arr[i][ny] == 2) {
				winn[x]++;
				p[y]++;
				backTracking(N + 1,x,z,y);
				winn[x]--;
				p[y]--;
			}
			else if (arr[i][ny] == 1|| arr[i][ny] == 0) {
				winn[y]++;
				p[y]++;
				backTracking(N + 1,y,z,x);
				winn[y]--;
				p[y]--;
			}
			che[i] = 0;
		}
	}
	else if (y == 0) {
		for (int i = 1; i <= n; i++) {
			if (che[i] == 1)continue;
			che[i] = 1;
			int nx = a[x][p[x]];
			if (arr[i][nx] == 2) {
				winn[y]++;
				p[x]++;
				backTracking(N + 1, y, z, x);
				winn[y]--;
				p[x]--;
			}
			else if (arr[i][nx] == 1 || arr[i][nx] == 0) {
				winn[x]++;
				p[x]++;
				backTracking(N + 1, x, z, y);
				winn[x]--;
				p[x]--;
			}
			che[i] = 0;
		}
	}
	else {
		if (x == 2 && y == 1) {
			x = 1; y = 2;
		}
		int nx = a[x][p[x]]; int ny = a[y][p[y]];
		if (arr[nx][ny] == 2) {
			winn[x]++;
			p[x]++; p[y]++;
			backTracking(N + 1,x,z,y);
			winn[x]--;
			p[y]--; p[x]--;
		}
		else if (arr[nx][ny] == 1|| arr[nx][ny] == 0) {
			winn[y]++;
			p[y]++; p[x]++;
			backTracking(N + 1,y,z,x);
			winn[y]--;
			p[y]--; p[x]--;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> win;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 20; i++) {
		cin >> a[1][i];
	}
	for (int i = 0; i < 20; i++) {
		cin >> a[2][i];
	}
	backTracking(0,0,1,2);
	cout << 0;
}

