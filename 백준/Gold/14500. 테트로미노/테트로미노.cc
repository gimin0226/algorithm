#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[502][502] = { 0 };
int dx1[10]{ 0,1,1,0,1,0,0,0,0,0 };
int dy1[10]{ 0,0,1,2,0,2,0,1,0,0 };
int dx2[10]{ 1,1,1,1,1,1,1,0,0,0 };
int dy2[10]{ 0,1,2,2,2,0,2,2,1,2 };
int maxx = 0;
int dx3[10]{ 2,0,1,1,0,0,0,0,0,0 };
int dy3[10]{ 0,0,1,0,1,1,0,0,1,0 };
int dx4[10]{ 2,0,2,2,2,1,1,2,2,2 };
int dy4[10]{ 1,1,1,0,1,1,0,0,0,1 };

void f1() {
	for (int i = 0; i < n-1; i++) {
		int sum = arr[i][0] + arr[i][1] + arr[i][2];
		sum += arr[i + 1][0] + arr[i+1][1] + arr[i+1][2];
		
		for (int t = 0; t < 10; t++) {
			int q = sum - arr[i+dx1[t]][dy1[t]]-arr[i+dx2[t]][dy2[t]];
			maxx = max(maxx, q);
			//cout << q << '\n';
		}

		for (int j = 3; j < m; j++) {
			sum -= arr[i][j - 3]+arr[i+1][j-3];
			sum += arr[i][j]+arr[i+1][j];
		//	cout <<"dfsdasad"<< sum << endl;
			for (int t = 0; t < 10; t++) {
				int q = sum - arr[i + dx1[t]][j -2+ dy1[t]] - arr[i + dx2[t]][j-2 + dy2[t]];
			//	cout << q << " ";
				maxx = max(maxx, q);

			}//cout << endl;
		}
	}
}

void f2() {
	for (int i = 0; i < n -2; i++) {
		int sum = arr[i][0] + arr[i][1];
		sum += arr[i + 1][0] + arr[i + 1][1];
		sum+=arr[i + 2][0] + arr[i + 2][1];

		for (int t = 0; t < 10; t++) {
			int q = sum - arr[i + dx3[t]][dy3[t]] - arr[i + dx4[t]][dy4[t]];
			maxx = max(maxx, q);
			//cout << q << " ";
		}

		for (int j = 2; j < m; j++) {
			sum -= arr[i][j - 2] + arr[i + 1][j - 2]+arr[i+2][j-2];
			sum += arr[i][j] + arr[i + 1][j]+arr[i+2][j];
		//	cout << "dfsdasad" << sum << endl;
			for (int t = 0; t < 10; t++) {
				int q = sum - arr[i + dx3[t]][j - 1 + dy3[t]] - arr[i + dx4[t]][j - 1 + dy4
					[t]];
			//	cout << q << " ";
				maxx = max(maxx, q);

			}//cout << endl;
		}
	}
}

void f3() {
	for (int i = 0; i < n; i++) {
		int sum = arr[i][0] + arr[i][1] + arr[i][2] + arr[i][3];
		maxx = max(maxx, sum);
		for (int j = 4; j < m; j++) {
			sum -= arr[i][j - 4];
			sum += arr[i][j];
			maxx = max(maxx, sum);
		}
	}
}

void f4() {
	for (int i = 0; i < m; i++) {
		int sum = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
		maxx = max(maxx, sum);
		for (int j = 4; j < n; j++) {
			sum -= arr[j-4][i];
			sum += arr[j][i];
			maxx = max(maxx, sum);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	f1();
	//cout << endl;
	f2();
	f3();
	f4();
	cout << maxx;
}