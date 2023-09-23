#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
int arr[1000001];
int tree[4 * 1000001];

void update(int node, int start, int end, int idx, int value) {
    if (idx < start || end < idx) return;
    tree[node] += value;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, value);
        update(node * 2 + 1, mid + 1, end, idx, value);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    ll num = 0;
    for (int i = N; i >= 1; i--) {
        num += query(1, 1, N, 1, arr[i] - 1);
        update(1, 1, N, arr[i], 1);
       // cout << num<<endl;
    }
    cout << num;
    return 0;
}
