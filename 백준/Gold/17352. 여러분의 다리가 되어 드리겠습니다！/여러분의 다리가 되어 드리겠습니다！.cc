#include<bits/stdc++.h>

using namespace std;

int n;
int parent[300001];
int node_rank[300001];
int find_node(int x) {
	if (x == parent[x])return x;
	else return parent[x] = find_node(parent[x]);
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
			parent[b] = a;
			node_rank[a] += 1;
		}
	}
}
int main(void) {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		node_rank[i] = 1;
	}

	
	for (int i = 0; i < n - 2; i++) {
		int x, y;
		cin >> x >> y;
		union_node(x, y);
	}

	
	int a = find_node(1);
	for (int i = 2; i <= n; i++) {
		if (a != find_node(i)) {
			cout << a << " " << i;
			return 0;
		}
	}
}
