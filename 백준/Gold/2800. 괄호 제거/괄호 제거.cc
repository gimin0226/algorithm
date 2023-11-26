#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
string str;
int siz;
vector<int> st;
vector<pair<int, int>> v;
int che[201] = { 0 };
int che2 = 0;
set<string> ans;
void backTracking(int n) {
	
	if (n == v.size()) {
		if (che2 == 0) {
			che2 = 1;
			return;
		}
		string str2="";
		for (int i = 0; i < str.length(); i++) {
			if (che[i] == 1)continue;
			str2 += str[i];
		}
		ans.insert(str2);
		return;
	}
	backTracking(n + 1);
	che[v[n].first] = 1;
	che[v[n].second] = 1;
	backTracking(n + 1);
	che[v[n].first] = 0;
	che[v[n].second] = 0;
	
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	stack<int> sta;
	
	cin >> str; 
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			sta.push(i);
		}
		else if (str[i] == ')') {
			int t = sta.top();
			sta.pop();
			v.push_back({ t,i });
		}
	}
	sort(v.begin(), v.end());
	backTracking(0);
	for (auto x : ans) {
		cout << x << "\n";
	}
}

