#include <bits/stdc++.h>
using namespace std;

int x, y;
int stop = 0;
int sum = 0;
vector<pair<int,int>> v[100001];
vector<int> dq;
int check[100001] = { 0 };
void dfs(int a) {
	for (int i = 0; i < v[a].size(); i++) {
		int k= v[a][i].first;
		int t = v[a][i].second;
		if (check[k] == 1) {
			continue;
		}
		if (k == y) {
			dq.push_back(t);
			sort(dq.begin(), dq.end());
			for (int i = 0; i < dq.size() - 1; i++) {
				sum += dq[i];
			}
			cout << sum;
			return;
		}
		dq.push_back(t);
		check[k] = 1;
		dfs(k);
		dq.pop_back();
		
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int n;
	cin >> n >> x >> y;
	if (n == 1||x==y) {
		cout << 0;
		return 0;
	}
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	check[x] = 1;
	dfs(x);

	
	
}