#include<bits/stdc++.h>

using namespace std;
#define X 1000000007

long long num[1000001];
long long tree[1000001*4];

long long init(int start, int end, int node) {
	if (start == end)return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node]=init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % X;
}

long long sum(int start, int end, int left, int right, int node) {
	if (start > right || end < left)return 1;

	if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) * sum(mid + 1, end, left, right, node * 2 + 1)%X;
}

long long update(int start, int end, int index, int node,int dif) {
	if (start > index || index > end)return tree[node];
	
	if (start == end && start == index) return tree[node] = dif;

	if (start == end)return tree[node];
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, index, node * 2, dif) * update(mid + 1, end, index, node * 2 + 1, dif)%X;

}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m,k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	init(0, n - 1, 1);
	int a, b, c;
	for (int i = 0; i < m+k; i++) {
		cin >> a >> b>>c;
		if (a == 1) {
			update(0, n - 1, b-1, 1, c);
		}
		else if (a == 2) {
			cout<<sum(0, n - 1, b - 1, c - 1, 1)<<'\n';
		}
	}
}
