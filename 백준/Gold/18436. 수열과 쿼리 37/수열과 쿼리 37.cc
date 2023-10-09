#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, k;
vector <int> arr, tree;
void input() {
	cin >> n;
	arr.resize(n,0);
	tree.resize(4 * n);
	for (int i = 0;i < n;i++) {
		cin >> k;
		if (k % 2 == 1) arr[i] = 1;
	}
}

int init(int i,int S,int E) {
	if (S == E) return tree[i] = arr[S];
	return tree[i] = init(2 * i, S, (S + E) / 2)
		+ init(2 * i + 1, (S + E) / 2 + 1, E);
}

void update(int i,int S,int E,int idx, int val) {
	if (idx < S || E < idx) return;
	tree[i]+=val;
	if (S != E) {
		update(2 * i, S, (S + E) / 2, idx, val);
		update(2 * i + 1, (S + E) / 2 + 1, E, idx, val);
	}
}

int query(int i, int S, int E,int L ,int R) {
	if (E < L || R < S) return 0;
	if (L <= S && E <= R) return tree[i];
	return query(2 * i, S, (S + E) / 2, L, R)
			+query(2 * i + 1, (S + E) / 2 + 1, E, L, R);
}
void output() {
	int a, b, c;
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			c = c % 2;
			if (arr[b - 1] != c) {
				if (c==1)update(1, 0, n - 1, b - 1, 1);
				else update(1, 0, n - 1, b - 1, -1);
				arr[b - 1] = c;
			}
		}
		else if (a == 2) cout<<c-b+1-query(1,0,n-1,b-1,c-1)<<'\n';
		else cout<<query(1,0,n-1,b-1,c-1)<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	init(1,0,n-1);
	output();
	return 0;
}