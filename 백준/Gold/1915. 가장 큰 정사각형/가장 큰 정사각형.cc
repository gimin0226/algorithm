#include <bits/stdc++.h>
using namespace std;


int arr[1002][1002] = { 0 };
int a[1002][1002] = { 0 };
int b[1002][1002] = { 0 };
int c[1002][1002] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j + 1] = str[j] - '0';
			a[i][j + 1] = str[j] - '0';
			b[i][j + 1] = str[j] - '0';
			c[i][j + 1] = str[j] - '0';
		}
	}
	
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0)continue;
			a[i][j] = min(a[i - 1][j - 1], min(b[i - 1][j], c[i][j - 1]))+1;
			maxx = max(maxx, a[i][j]);
			b[i][j] = b[i - 1][j] + 1;
			c[i][j] = c[i][j - 1] + 1;
		}
	}

	cout << maxx*maxx;
	
}