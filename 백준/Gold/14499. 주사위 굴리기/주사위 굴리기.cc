#include <bits/stdc++.h>
using namespace std;
int n;
int arr[21][21];
int N, M, X, Y, K;
int top = 6;
int bot = 1;
int t[7]{0,6,5,4,3,2,1};
int x, y;
int dx[]{ 0,0,0,-1,1 };
int dy[]{0,1,-1,0,0};

int* a[7];


int dice[]{ 0,0,0,0,0,0,0 };
void f(int v) {
	x += dx[v];
	y += dy[v];
	if (x<0 || y<0 || x>N - 1 || y>M - 1) {
		x -= dx[v];
		y -= dy[v];
		return;
	}

	int* t = a[1];
	if (v == 1) {
		a[1] = a[3]; a[3] = a[6]; a[6] = a[4]; a[4] = t;
	}else if (v == 2) {
		a[1] = a[4]; a[4] = a[6]; a[6] = a[3]; a[3] = t;
	}
	else if (v == 3) {
		a[1] = a[2]; a[2] = a[6]; a[6] = a[5]; a[5] = t;
	}
	else if (v == 4) {
		a[1] = a[5]; a[5] = a[6]; a[6] = a[2]; a[2] = t;
	}
	//cout << "bot: " << *a[1]<< " top: " << *a[6] << " ";
	
	
	if (arr[x][y] == 0) {
		arr[x][y] = *a[1];
	}
	else {
		*a[1] = arr[x][y];
		arr[x][y] = 0;
	}
	cout << *a[6] << "\n";
	return;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> N >> M >> X >> Y >> K;
	x = X; y = Y;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >>arr[i][j];
		}
	}
	int T= 0;
	for (int i = 1; i < 7; i++) {
		a[i] = dice + i;
	}
	for (int i = 0; i < K; i++) {
		cin >> T;
		f(T);
	}
	return 0;
}