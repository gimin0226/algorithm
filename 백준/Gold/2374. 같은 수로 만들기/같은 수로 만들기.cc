#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long maxx = 0;
	stack<int> sta;
	sta.push(arr[0]);
	maxx = arr[0];
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		if (sta.top() < arr[i]) {
			sum +=arr[i]- sta.top();
			maxx = max(arr[i], maxx);
			while (true) {
				if ( sta.empty()||sta.top() >= arr[i]) {
					break;
				}
				sta.pop();
			}
			sta.push(arr[i]);

		}
		else {
			sta.push(arr[i]);
		}
	}
	sum += (maxx - sta.top());
	cout << sum;
	return 0;
}