#include <bits/stdc++.h>
using namespace std;


int main(void) {
	long long n; cin >> n;
	long long x;
	vector<long long> v;
	long long ans = 0;
	queue<long long> que;
	long long first;
	long long end;
	for (int i = 1; i <= n; i++) {
		
		cin >> x;
		v.push_back(x);
		if (x != 0) {
			que.push(i);
			ans += x;
		
		}
	}
	if (que.size() == 0) {
		long long t = n;
		if (t % 2 == 0) {
			ans += t / 2;
		}
		else {
			ans += t / 2 + 1;
		}
		cout << ans;
		return 0;
	}

	first = que.front();
	while (true) {
		if (que.size() == 1) {
			end = que.front();
			long long t=(n - end + first - 1);
			if (t % 2 == 0) {
				ans += t / 2;
			}
			else {
				ans += t / 2 + 1;
			}
			cout << ans;
			return 0;
		}
		long long x = que.front();
		que.pop();
		long long y = que.front();
		long long t = y - x - 1;
		if (t % 2 == 0) {
			ans += t / 2;
		//	cout << ans<<endl;
		}
		else {
			ans += t / 2 + 1;
		//	cout << ans << endl;
		}
	}
	
	

	
}
	