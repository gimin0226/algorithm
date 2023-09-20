#include<bits/stdc++.h>

using namespace std;

long long num[100001];
long long tree[100001*4];
int cnt=0;

long long init(int start, int end, int node) {
	if (start == end)return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node]=min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

void update(int start, int end, int node, int index, long long change) {
	if (start == end){
		tree[node] =  change; return;
}
	int mid = (start + end) / 2;
	if (index > mid) {
		update(mid + 1, end, node * 2 + 1, index, change);
	}
	else if (index <= mid) {
		update(start, mid, node * 2, index, change);
	}
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

long long sum(int start, int end, int left, int right, int node) {
	if (start > right || end < left)return INT_MAX;	
	if (left <= start && end <= right)return tree[node];

	int mid = (start+end) / 2;
	return min(sum(start, mid, left, right,2* node), sum(mid + 1, end, left, right, 2*node+1));
	
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	init(0, n - 1, 1);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, n - 1, 1, b-1, c);
		}
		else if (a == 2) {
			cout << sum(0, n - 1, b-1, c-1, 1)<<'\n';
		}
	}
	return 0;

}
