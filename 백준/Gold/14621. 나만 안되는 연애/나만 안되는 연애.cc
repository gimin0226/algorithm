#include<bits/stdc++.h>

using namespace std;

char arr[1001];
int parent[1001];
int depth[1001];

struct edge {
	int x;
	int y;
	int cost;

	edge(int X, int Y, int COST) {
		x = X; y = Y; cost = COST;
	}

	bool operator<(edge& edge) {
		return this->cost < edge.cost;
	}
};

typedef struct edge edge;
int find_node(int x) {
	if (x == parent[x])return x;
	else return parent[x] = find_node(parent[x]);
}

bool merge_node(int x,int y) {
	int p = find_node(x);
	int q = find_node(y);
	if (p != q) {
		if (depth[p] == depth[q]) {
			depth[p]++;
			parent[q] = p;
		}
		else if (depth[p] > depth[q]) {
			parent[q] = p;
		}
		else {
			parent[p] = q;
		}
		return true;
	}
	return false;
}
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	vector<edge> v;
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		if (arr[x] != arr[y]) {
			v.push_back(edge(x, y, cost));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		depth[i] = 0;
	}

	int num = n - 1;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (num == 0) {
			break;
		}
		if (merge_node(v[i].x, v[i].y)) {
			sum += v[i].cost;
			num--;
		}
	}
	if (num > 0)cout << "-1";
	else cout << sum;
}