#include<bits/stdc++.h>

using namespace std;

int arr[100001];	

int main(void) {
	int n; cin >> n;
	cin >> arr[0];
	if (n == 1) {
		cout << "YES";
		cout << endl << -1;
		cout << endl << arr[0] + 1;
		return 0;
	}
	cin >> arr[1];
	int t = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		cin >> arr[i];
		if (arr[i] - arr[i - 1] != t) {
			cout << "NO";
			return 0;
		}
	}

	int k = 3;
	int p = t - k;
	int a = 1;
	int b = arr[0] - a;
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		cout << a<<" ";
		a += k;
	}cout << endl;

	for (int i = 0; i < n; i++) {
		cout << b << " ";
		b += p;
	}



}
