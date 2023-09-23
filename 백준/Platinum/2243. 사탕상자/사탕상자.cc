#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int N;
int K;
deque<int> dq;
ll num[1000001] = { 0 };
ll tree[4000004] = { 0 };

ll update(int start, int end, int node, int index,ll change) {
	
//	cout << start << " " << end << " " << '\n';
	if (index < start || end < index)return tree[node];

	if (start == end )return tree[node]=change;
	
	//cout << "sfd";
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index,change);
	update(mid + 1, end, node * 2 + 1, index,change);
	return tree[node] = tree[node*2]+tree[node*2+1];
}
ll query(int start, int end, int node, int index) {
	if (start == end) {
		tree[node]--;
		return start;
	}
	int mid = (start + end) / 2;

	if (index <= tree[node * 2]) {
		return query(start, mid, node * 2, index);
		
	}
	else if (index > tree[node * 2]){
		return query(mid + 1, end, node * 2 + 1, index-tree[node*2]);
		
	}


}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	
	ll a, b, c;

	for (int i = 0; i < N; i++) {
		
		cin >> a;
		if (a == 1) {
			cin >> b;
			int t = query(1, 1000001, 1, b);
			cout<<t<<'\n';
			num[t]--;
			update(1, 1000001, 1,t, num[t]);
		}
		else if (a == 2) {
			cin >> b >> c;
			num[b]+c<0?num[b]=0:num[b] += c;
			update(1, 1000001, 1, b,num[b]);
		
		}
	}
	
}