#include<bits/stdc++.h>

using namespace std;

#define max 100001

typedef long long ll;

long long arr[max];
long long tree[max * 4];

long long init(int node, int start, int end) {
	if (start == end)return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
ll sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start)return 0;

	if (left <= start && end <= right)return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long change) {
	if (start == end && start == index) {
		tree[node] += change;
		return;
	}

	if (start <= index && index <= end) {
		int mid = (start + end) / 2;
		tree[node] += change;
		update(node * 2, start, mid, index, change);
		update(node * 2 + 1, mid + 1, end, index, change);
	}
	return;

}
int main(void) {
	ios::sync_with_stdio(false);
		cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x, y, a;
	long long b;
	init(1, 0, n - 1);
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> a >> b;
		if (x <= y) {
			cout << sum(1, 0, n - 1, x-1, y-1) << '\n';
		}
		else {
			cout << sum(1, 0, n - 1, y-1, x-1) << '\n';
		}

		update(1, 0, n - 1, a - 1, b-arr[a-1]);
		arr[a - 1] = b;
	}
}
