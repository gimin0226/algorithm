#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;


int main(void) {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	int start = 0;
	int end = n - 1;

	int minn = v[start]+v[end];
	while (true) {
		if (start+1 == end) {
			int t = v[start] + v[end];
			if (abs(t) < abs(minn)) {
				minn = t;
			}
			break;
		}
		if (abs(v[start + 1] + v[end]) < abs(v[start] + v[end - 1])) {
			start = start + 1;
		}
		else {
			end = end - 1;
		}
		int t = v[start] + v[end];
		if (abs(t) < abs(minn)) {
			minn = t;
		}
	}
	cout << minn;
}