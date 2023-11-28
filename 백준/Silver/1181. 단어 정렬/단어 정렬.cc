#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;

struct Compare {
	bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
		if (a.first != b.first) return a.first < b.first;
		return a.second < b.second;
	}
};
set<pair<int, string>,Compare> v;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		pair<int, string> p = { st.length(),st };
		v.insert(p);
	}
	
	for (auto t : v) {
		cout << t.second<<"\n";
	}
}

