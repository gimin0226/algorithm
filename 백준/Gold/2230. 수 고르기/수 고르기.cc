#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> v;

ll lower_bound(ll x) {
	ll left = 0; ll right = v.size() - 1;
	ll mid;
	while (true) {
		if (left > right) {
			break;
		}
		mid = (left + right) / 2;
		if (v[mid] >=x) {
			right = mid-1;
		}
		else {
			left = mid + 1;
		}
	}
	//cout << left << " ";
	
	return left;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	ll minn = LONG_MAX-1;
	for (int i = 0; i < v.size(); i++) {
		ll t = v[i] + m;
		ll x=lower_bound(t);
		if (x > v.size() - 1)continue;
		if (v[x] - v[i] >= m) {
			minn = min(v[x] - v[i], minn);
		}
	}
	cout << minn;
}