#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr2[7]{ 100,50,20,10,5,2,1 };
	long long arr[10001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long a1 = arr[0];
	long long a2 = arr[1];
	for (int i = 2; i < n; i++) {
		if (a1 <= a2) {
			a1 += arr[i];
		}
		else if (a1 > a2) {
			a2 += arr[i];
		}
	}
	
	int x = abs(a1 - a2);
	
	int i = 0;
	int num = 0;
	while (true) {
		if (x == 0) {
			cout << num;
			return 0;
		}
		if (arr2[i] <= x) {
			
			x -= arr2[i];
			num++;
		}
		else {
			
			i++;
		}
	}

}
