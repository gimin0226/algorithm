#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	int start = 0;
	int end = n - 1;
	int maxx = 0;
	int c = 0;
	while (true) {
		
		int count = 1;
		while (true) {
			if (start == end) {
				maxx = max(maxx, count * arr[start]);
				c++;
				break;
			}
			if (arr[start] != arr[start + 1]) {
				maxx = max(maxx, count * arr[start]);
				start++;
				break;
			}
			start++;
			count++;
		}
		if (c == 1) {
			break;
		}
	}
	int sum = accumulate(arr.begin(), arr.end(), 0);
	cout << maxx + sum << '\n';
	for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
	}
}
	