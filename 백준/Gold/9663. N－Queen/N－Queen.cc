#include<bits/stdc++.h>
using namespace std;

int arr[15][15];
int n;
int num = 0;
void BackTracking(int  t) {
	if (t == n - 1) {
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}cout << '\n';
		}*/
		for (int i = 0; i < n; i++) {
			if (arr[t][i] == 0) {
				num++;

			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (arr[t][i] == 1) {
			continue;
		}
		arr[t][i] = 1;
		queue<pair<int, int>> que;
	

		for (int j = 1; j < n; j++) {
			if (t + j < n && arr[t + j][i] == 0)
			{
				que.push({ t + j, i });
				arr[t + j][i] = 1;
			}
			if (i + j < n && arr[t][i + j] == 0)
			{
				que.push({ t, i + j });
				arr[t][i + j] = 1;
			}
			if (t + j < n && i + j < n && arr[t + j][i + j] == 0)
			{
				que.push({ t + j, i + j }); 
				arr[t + j][i + j] = 1;
			}
			if (t + j < n && i - j >= 0 && arr[t + j][i - j] == 0)
			{
				que.push({ t + j, i - j });
				arr[t + j][i - j] = 1;
			}
		}
		BackTracking(t + 1);
		arr[t][i] = 0;
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			arr[x][y] = 0;
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	BackTracking(0);
	cout << num;
}