#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int n;
	cin >> n;
	int ar[2001];
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	
	int** arr = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)arr[i] = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		arr[i][i] = 1;
		if (ar[i] == ar[i + 1]) {
			arr[i][i + 1] = 1;
		}
		else {
			arr[i][i + 1] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j + i > n)continue;
			if (arr[j + 1][j+i - 1] == 1) {
				if (ar[j] == ar[j+i]) {
					arr[j][j+i] = 1;
				}
				else {
					arr[j][j+i] = 0;
				}
			}
			else {
				arr[j][j+i] = 0;
			}
		}
	}


	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << arr[x][y] << "\n";
	}
}