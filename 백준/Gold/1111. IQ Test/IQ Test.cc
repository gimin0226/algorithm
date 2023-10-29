#include<bits/stdc++.h>	
using namespace std;

int main(void) {

	int n;
	cin >> n;
	int arr[51];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << "A";
		return 0;
	}if (n == 2) {
		if (arr[0] == arr[1])cout << arr[0];
		else cout << "A";
		return 0;
	}
	int num = 0;
	int ans=87654321;
	for (int i = -200; i <= 200; i++) {
		int b = arr[1] - i * arr[0];
		for (int j = 1; j < n - 1; j++) {
			if (arr[j + 1] != arr[j] * i + b) {
				break;
			}
			if (j == n - 2) {
				//cout << i << " " << b << endl;
				
				int p = arr[j + 1] * i + b;
				if (ans == p)break;
				ans = p;
				num++;
			}
		}
	}
	
	if (num == 0) {
		cout << "B";
	}
	else if (num > 1) {
		cout << "A";
	}
	else if (num == 1) {
		cout << ans;
	}
	return 0;

}