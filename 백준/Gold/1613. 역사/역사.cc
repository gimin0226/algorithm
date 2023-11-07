#include<bits/stdc++.h>
using namespace std;


int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int arr[401][401] = { 0 };

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j])continue;
				if (arr[i][k] && arr[k][j])arr[i][j] = 1;
			}
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (arr[a][b]) {
			cout << "-1\n";
			continue;
		}
		else if (arr[b][a]) {
			cout << "1\n";
			continue;
		}
		cout << "0\n";
	}
}