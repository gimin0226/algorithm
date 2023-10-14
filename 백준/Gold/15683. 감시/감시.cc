#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
int n,m;
int dx[] { 0,-1,0,1};
int dy[] { -1,0,1,0 };
vector<tuple<int, int, int>> vec;
int ans=0;
int minn = INT_MAX;


int check(int i,int x, int y) {
	i = i % 4;
	int count = 0;
	while (true) {
		x += dx[i];
		y += dy[i];
		if (x<0 || y<0 || x>n - 1 || y>m - 1)return count;
		if (arr[x][y] == 6) { //벽을 만났을 때
			return count;
		}
		else if (arr[x][y] == 0) { //빈땅일때
			arr[x][y] = -1;
			count++;
		}
	}
}
void f(int p) {
	if (p== vec.size()) {
		minn = min(ans, minn);
		return;
	}
	int X, Y, Z;
	tie(X, Y, Z) = vec[p];
	
	int tmp[9][9];
	for (int i = 0; i < 4; i++) {

		int count = 0;

		for (int t= 0; t < n; t++) {
			for (int j = 0; j < m; j++) {
				tmp[t][j] = arr[t][j];
			}
		}

		switch (Z) {
		case 1:
			count += check(i, X, Y);
			break;
		case 2:
			count += check(i, X, Y);
			count += check(i + 2, X, Y);
			break;
		case 3:
			count += check(i, X, Y);
			count += check(i + 1, X, Y);
			break;
		case 4:
			count += check(i, X, Y);
			count += check(i + 1, X, Y);
			count += check(i + 2, X, Y);
			break;
		case 5:
			count += check(i, X, Y);
			count += check(i + 1, X, Y);
			count += check(i + 2, X, Y);
			count += check(i + 3, X, Y);
		}
		ans -= count;
		f(p + 1);
		ans += count;
		for (int t = 0; t < n; t++) {
			for (int j = 0; j < m; j++) {
				arr[t][j] = tmp[t][j];
			}
		}
	}
	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> n >> m;
	
	int T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T;
			arr[i][j]=T;
			if (T != 0 && T != 6) {
				vec.push_back({ i,j,T });
			}
			else if(T==0) {
				ans++;
			}
		}
	}

	f(0);
	cout << minn;
	return 0;
}