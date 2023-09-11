#include<bits/stdc++.h>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	stack<int> sta;
	vector<int> v;
	int n, m;
	cin >> n >> m;

	int maxx = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		v.push_back(t);
		maxx = max(maxx, t);
	}

	for (int i = maxx; i >= 1; i--) {
		vector<int> vec;
		for (int j= 0; j < v.size(); j++) {
			if (v[j] >= i) {
				vec.push_back(j);
			}
		}

		for (int j = 0; j < vec.size()-1; j++) {
			int x = vec[j + 1] - vec[j] - 1;
			ans += x;
		}
	}

	cout << ans;
	
}


