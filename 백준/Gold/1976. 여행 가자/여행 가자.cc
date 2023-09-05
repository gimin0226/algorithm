#include<bits/stdc++.h>	

using namespace std;

int parent[201];
int node_rank[201];

int find_node(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find_node(parent[x]);
}

void union_node(int x, int y) {
	int a = find_node(x);
	int b = find_node(y);

	if (a != b) {
	
		if (node_rank[a] > node_rank[b]) {
			parent[b] = a;
		}
		else if (node_rank[a] < node_rank[b]) {
			parent[a] = b;
		}
		else {
			parent[a] = b;
			node_rank[b]++;
		}
	}
}
int main(void) {
	int n;
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		node_rank[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t;
			cin >> t;
			if (j >= i)continue;

			if (t == 1) {
				union_node(i, j);
			}

		}
	}


	int arr[1001];
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		arr[i] = t;
	}
	for (int i = 0; i < m - 1; i++) {
		if (find_node(arr[i]) != find_node(arr[i+1])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}