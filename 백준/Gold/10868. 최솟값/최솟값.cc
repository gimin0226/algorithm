#include<bits/stdc++.h>

using namespace std;
long long num[100001];
long long tree[100001*4];

int init(int start, int end, int node) {
	if (start == end)return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node]=min(init(start, mid, node * 2), init(mid+1, end, node * 2 + 1));
}

int minn(int start, int end, int node, int left, int right) {
	if (start > right || end < left)return INT_MAX;
		
	if (left <= start && end <= right) return tree[node];
	
	int mid = (start + end) / 2;
	return min(minn(start, mid, node * 2, left, right), minn(mid + 1, end, node * 2 + 1, left, right));
	
}



int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	init(0, n - 1, 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout<<minn(0, n - 1, 1, a-1, b-1)<<"\n";
	}

}