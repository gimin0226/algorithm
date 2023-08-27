#include<iostream>	
#include<cstdio>
using namespace std;

int n, m, h;
int** arr;
int** road;
int minn = 100;
void BackTracking(int num) {

	if (num > 3) {
		return;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (road[i][j] == 0&&road[i][j-1]!=1&&road[i][j+1]!=1) {
				road[i][j] = 1;
				int count = 0;
				int x, y;
				for (int t = 1; t <= n; t++) {
					x = 1; y = t;

					int k = 0;
					for (k = x; k <= h; k++) {
						if (road[k][y]==1) {
							y += 1;
						}
						else if (road[k][y-1]==1) {
							y -= 1;
						}
					}

					if (y == t) {
						count += 1;
					}
					else {
						break;
					}			
				}
				if (count == n) {
					if (num < minn) {
						minn = num;
					}
				}
				road[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <n; j++) {
			if (road[i][j] == 0 && road[i][j - 1] != 1 && road[i][j + 1] != 1) {
				road[i][j] = 1;
				BackTracking(num + 1);
				road[i][j] = 0;
			}
		}
	}
}
int main(void) {
	cin >> n >> m >> h;
	road = new int* [h+2];
	for (int i = 1; i <= h; i++) {
		
		road[i] = new int[n +1];
		for (int j = 1; j < n; j++) {
			road[i][j] = 0;
		}
	}
	for (int i = 1; i <= h; i++) {
		road[i][0] = -1;
		road[i][n] = -1;
	}
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		road[x][y] = 1;
	}
	int count = 0;
	int x, y;
	for (int t = 1; t <= n; t++) {
		x = 1; y = t;

		int k = 0;
		for (k = x; k <= h; k++) {
			if (road[k][y] == 1) {
				y += 1;
			}
			else if (road[k][y - 1] == 1) {
				y -= 1;
			}
		}
		if (y == t) {
			count += 1;
		}
		else {
			break;
		}
	}
	if (count == n) {
		cout << "0";
		return 0;
	}
	BackTracking(1);
	if (minn == 100)
		cout << "-1";
	else
		cout << minn;
}