#include <bits/stdc++.h>
using namespace std;

int check[250001] = { 0 };
int check2[250001] = { 0 };

int main(void) {
	int n; cin >> n;
	long long x;
	vector<long long> v;
	long long ans = 0;
	queue<int> que;
	int first;
	int end;
	for (int i = 1; i <= n; i++) {
		
		cin >> x;
		v.push_back(x);
		if (x != 0) {
			que.push(i);
			ans += x;
			check[i] = 1;
		}
	}
	if (que.size() == 0) {
		int t = n;
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
			int t=(n - end + first - 1);
			if (t % 2 == 0) {
				ans += t / 2;
			}
			else {
				ans += t / 2 + 1;
			}
			cout << ans;
			return 0;
		}
		int x = que.front();
		que.pop();
		int y = que.front();
		int t = y - x - 1;
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