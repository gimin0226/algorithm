#include<bits/stdc++.h>

using namespace std;
int n;
int arr[21][21];
int sum1 = 0;
int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;
int summ = 0;
int ans = INT_MAX;
void sum(int x1,int y1,int x2, int y2,int x3,int y3,int x4,int y4,bool che[101][101]) {
	sum1 = 0; sum2 = 0; sum3 = 0; sum4 = 0; sum5 = 0;
	for (int i = 1; i < x1; i++) {
		for (int j = 1; j <= y2; j++) {
			if (che[i][j] == 1)break;
			sum1 += arr[i][j];
		}
	}
	for (int i = 1; i <= x4; i++) {
		for (int j = n; j >= y2+1; j--) {
			if (che[i][j] == 1)break;
			sum2 += arr[i][j];
		}
	}
	
	for (int i = x1; i <= n; i++) {
		for (int j = 1; j < y3; j++) {
			if (che[i][j] == 1)break;
			sum3 += arr[i][j];
		}
	}

	for (int i = x4 + 1; i <= n; i++) {
		for (int j = n; j >= y3; j--) {
			if (che[i][j] == 1)break;
			sum4 += arr[i][j];
		}
	}
}
int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			summ += arr[i][j];
		}
	}

	int d1, d2;
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < n - 1; j++) {
			int x = i, y = j;
			for (d1 = 1; d1 < x; d1++) {
				for (d2 = 1; d2 < n - x+1; d2++) {
					bool che[101][101] = { 0 };
					int x1, y1, x2, y2, x3, y3, x4, y4;
					x1 = i, y1 = j;
					x2 = i - d1, y2 = j + d1;
					x3 = i + d2, y3 = j + d2;
					x4 = i + d2 - d1, y4 = j + d1 + d2;
					if (y2 > n || y3 > n || y4 > n)continue;
					che[x1][y1] = 1; che[x2][y2] = 1; che[x3][y3] = 1; che[x4][y4] = 1;
					for (int t = 1; t <= d2; t++) {
						che[x1 + t][y1 + t] = 1;
						che[x2 + t][y2 + t] = 1;
					}
					for (int t = 1; t <= d1; t++) {
						che[x1 -t][y1 + t] = 1;
						che[x3 -t][y3 + t] = 1;
					}
					sum(x1, y1, x2, y2, x3, y3, x4, y4,che);
					sum5 = summ - sum1 - sum2 - sum3 - sum4;
					int minn, maxx;
					minn = min(min(sum1, sum2), min(min(sum3, sum4), sum5));
					maxx = max(max(sum1, sum2), max(max(sum3, sum4), sum5));
					//printf("x1:%d y1:%d x2:%d y2:%d x3:%d y3:%d x4:%d y4:%d\n", x1, y1, x2, y2, x3, y3, x4, y4);
					//printf("sum1:%d sum2:%d sum3:%d sum4:%d sum5:%d\n", sum1, sum2, sum3, sum4, sum5);
					ans = min(ans, maxx - minn);
				}
			}
		}
	}

	cout << ans;
}