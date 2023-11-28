#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;

vector<pair<int, string>> v;
bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)return true;
	else if (a.first > b.first)return false;
	else {
		string s = a.second;
		string t = b.second;
		if (s.compare(t) < 0) {
			return true;
		}
		else return false;
	}
}
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
		v.push_back(p);
	}
	
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << "\n";
	}
}

