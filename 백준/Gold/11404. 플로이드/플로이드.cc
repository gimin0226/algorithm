#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[101];  //그다음 위치, 비용

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			arr[i][j] = 987654321;
		}
	}

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y] = min(arr[x][y], z);
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}



	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	/*	cout << "k:" << k << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j]==1000001)cout << "!" << " ";
				else cout << arr[i][j] << " ";
			}cout << endl;
		}
		*/
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j||arr[i][j]==987654321)cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}cout << endl;
	}
}