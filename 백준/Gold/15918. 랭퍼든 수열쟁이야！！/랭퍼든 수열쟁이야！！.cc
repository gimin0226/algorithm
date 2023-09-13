#include<bits/stdc++.h>

using namespace std;
int arr[26];
int n;
bool check[13] = { false };
int num = 0;

void BackTracking(int idx) {
	for (int i = 1; i <= n; i++) {
		if (check[i] == false)break;
		if (i == n) {
			num++;
			return;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check[i])continue;
		if (idx + i + 1 < 2 * n + 1 && arr[idx + i + 1] == -1) {
			arr[idx] = i;
			arr[idx + i + 1] = i;
			check[i] = true;
			int idx2 = idx;
			while (true) {
				idx2++;
				if (arr[idx2] == -1) {
					break;
				}
			}
			BackTracking(idx2);
			arr[idx] = -1;
			arr[idx + i + 1] = -1;
			check[i] = false;
		}

	}
}

int main(void){
	int x, y;
	cin >> n >> x >> y;
	memset(arr, -1, sizeof(arr));

	arr[x] = y - x - 1;
	arr[y] = y - x - 1;
	check[y - x - 1] = true;
	
	if (x != 1)BackTracking(1);
	else if (x == 1)BackTracking(2);
	cout << num;
}
