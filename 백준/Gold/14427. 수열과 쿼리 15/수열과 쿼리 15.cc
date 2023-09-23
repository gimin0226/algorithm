#include<bits/stdc++.h>

using namespace std;
using pa = pair<int, int>;


int check[5001] = { 0 };	
int N;
int K;
deque<int> dq;
int arr[100001];
pa tree[400004];

pa init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = { arr[start],start };
	}

	int mid = (start + end) / 2;
	pa a = init(start, mid, node * 2);
	pa b = init(mid + 1, end, node * 2 + 1);

	if (a.first == b.first) { return tree[node] = { a.first,min(a.second,b.second) }; }
	else if (a.first < b.first) { return tree[node] = { a.first,a.second }; }
	else if (a.first > b.first) { return tree[node] = { b.first,b.second }; }
}

pa update(int start, int end, int node, int index, int change) {
	if (index<start || index>end) 	return tree[node];
	
	if (start == end && start == index) return tree[node] = { arr[start],start };
	
	int mid = (start + end) / 2;
	pa a = update(start, mid, node * 2, index, change);
	pa b = update(mid + 1, end, node * 2 + 1, index, change);
	
	if (a.first == b.first) { return tree[node] = { a.first,min(a.second,b.second) }; }
	else if (a.first < b.first) { return tree[node] = { a.first,a.second }; }
	else if (a.first > b.first) { return tree[node] = { b.first,b.second }; }

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	init(0, N - 1, 1);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			arr[b-1] = c;
			update(0, N - 1, 1, b-1, c);
		}
		else if (a == 2) {
			cout << tree[1].second+1 << '\n';
		}
	}
	
}