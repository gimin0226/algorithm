#include<bits/stdc++.h>

using namespace std;
long long num[1000001];
long long tree[1000001*5];

long long init(int start, int end, int node) {
	if (start == end)return tree[node] = num[start];
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 0;

	if (left <= start && end <= right)return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
	if (index<start || index>end)return;

	tree[node] += dif;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		num[i] = t;
	}
	init(0, n - 1, 1);

	long long a, b;
	long long c;
	long long dif;
	for (int i = 0; i < m + k; i++) {
		
		cin >> a >> b >> c;
		if (a == 1) {
			dif = c - num[b - 1];
			num[b - 1] = c;
			update(0, n - 1, 1, b - 1, dif);
		}
		else if (a == 2) {
			cout << sum(0, n - 1, 1,b - 1, c - 1) << '\n';
		}
	}

}