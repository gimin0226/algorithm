#include <bits/stdc++.h>

using namespace std;

int parent[1000002];
int node_rank[1000002];
int find_root(int x) {
	if (x == parent[x])return x;
	else return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	if (x != y) {
		
		if (node_rank[x] < node_rank[y]) parent[x] = y;
		else if (node_rank[x] > node_rank[y]) {
			parent[y] = x;
		}
		else  {
			parent[x] = y;
			node_rank[x]++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		node_rank[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 0) {
				union_root(a, b);
		}
		else if (k == 1) {
			if (find_root(a) == find_root(b)) {
				cout << "YES"<<'\n';
			}
			else {
				cout << "NO"<<'\n';
			}
		}
	}
}