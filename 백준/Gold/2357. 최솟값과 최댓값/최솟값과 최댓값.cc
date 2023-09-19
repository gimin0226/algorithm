#include<bits/stdc++.h>

using namespace std;
long long num[100001];
long long tree_min[100001*4];
long long tree_max[100001 * 4];

int init_min(int start, int end, int node) {
	if (start == end)return tree_min[node] = num[start];

	int mid = (start + end) / 2;
	return tree_min[node]=min(init_min(start, mid, node * 2), init_min(mid+1, end, node * 2 + 1));
}

int init_max(int start, int end, int node) {
	if (start == end)return tree_max[node] = num[start];

	int mid = (start + end) / 2;
	return tree_max[node] = max(init_max(start, mid, node * 2), init_max(mid + 1, end, node * 2 + 1));
}

int minn(int start, int end, int node, int left, int right) {
	if (start > right || end < left)return INT_MAX;
		
	if (left <= start && end <= right) return tree_min[node];
	
	int mid = (start + end) / 2;
	return min(minn(start, mid, node * 2, left, right), minn(mid + 1, end, node * 2 + 1, left, right));
	
}

int maxx(int start, int end, int node, int left, int right) {
	if (start > right || end < left)return 0;

	if (left <= start && end <= right) return tree_max[node];

	int mid = (start + end) / 2;
	return max(maxx(start, mid, node * 2, left, right), maxx(mid + 1, end, node * 2 + 1, left, right));

}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	init_min(0, n - 1, 1);
	init_max(0, n - 1, 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << minn(0, n - 1, 1, a - 1, b - 1) << " " << maxx(0, n - 1, 1, a - 1, b - 1) << '\n';
	}

}