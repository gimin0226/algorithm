#include<bits/stdc++.h>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> v1;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v1.push_back(t);
	}

	vector<int> v2;
	for (int i = 0; i < v1.size(); i++) {
		int t = v1[i];
		if (v2.empty()) {
			v2.push_back(t);
		}
		else {
			if (t > v2[v2.size() - 1]) {
				v2.push_back(t);
			}
			else{
				auto it = lower_bound(v2.begin(), v2.end(), t);
				*it = t;
			}
		}
	}

	cout << v2.size();
}