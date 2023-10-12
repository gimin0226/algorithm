#include <bits/stdc++.h>
using namespace std;
long long arr[5][5];
long long arr1[5][5];
long long arr2[5][5];
long long N, M;

void matrix_multipli() {
	long long arr3[5][5];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int t = 0; t < N; t++) {
				sum=(sum+arr1[i][t] * arr2[t][j])%1000;
			}
			arr3[i][j] = sum;
		}
	}
	for (int i = 0; i < N; i++) {
		copy(arr3[i], arr3[i] + N, arr1[i]);
	}
}
void matrix_multipli2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int t = 0; t < N; t++) {
				sum =(sum+ arr1[i][t] * arr[t][j])%1000;
			}
			arr2[i][j] = sum;
		}
	}
}

void divide_conquer(long long n) {
	
	if (n == 1) {
		return;
	}

	if (n % 2 == 0) {
		divide_conquer(n / 2);
		for (int i = 0; i < N; i++) {
			copy(arr1[i], arr1[i] + N, arr2[i]);
		}
		matrix_multipli();
	}
	else if (n % 2 == 1) {
		divide_conquer(n / 2);
		for (int i = 0; i < N; i++) {
			copy(arr1[i], arr1[i] + N, arr2[i]);
		}
		matrix_multipli2();
		matrix_multipli();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	
	
	
	cin >> N >> M;
	long long x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			arr[i][j]=x%1000;
			arr1[i][j] = arr[i][j];
		}
	}
	
	divide_conquer(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}