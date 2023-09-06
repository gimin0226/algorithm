#include<bits/stdc++.h>

using namespace std;


int parent[51];
int node_rank[51];

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
			parent[a] = b;	
			node_rank[b]++;
		}
	}
}
int main(void) {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		node_rank[i] = i;
	}
	int per;
	cin >> per;
	if (per == 0) {
		cout << m;
		return 0;
	}
	int* arr = new int[per];
	for (int i = 0; i < per; i++) {
		int t;
		cin >> t;
		arr[i] = t;
	}
	for (int i = 0; i < per - 1; i++) {
		union_node(arr[i], arr[i + 1]);
	}
	int party[51][51];

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		party[i][0] = k;
		for (int j = 1; j <= k; j++) {
			int t;
			cin >> t;
			party[i][j] = t;		
		}
	}


	for (int i = 0; i < m; i++) {
		int k = party[i][0];
		
		for (int j = 1; j < k; j++) {
			union_node(party[i][j], party[i][j+1]);
		}
	}
	
	int num = m;
	for (int i = 0; i < m; i++) {
		int k = party[i][0];
		int t = find_node(arr[0]);
		for (int j = 1; j <= k; j++) {
			if (find_node(party[i][j]) == t) {
				num--;
				break;
			}
		}
	}
	cout << num;
	return 0;
}