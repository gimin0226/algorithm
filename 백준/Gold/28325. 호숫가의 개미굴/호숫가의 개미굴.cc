#include <bits/stdc++.h>
using namespace std;

int check[250001] = { 0 };
int check2[250001] = { 0 };

int main(void) {
	int n; cin >> n;
	int x;
	vector<int> v;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		v.push_back(x);
		if (x != 0) {
			ans += x;
			check[i] = 1;
		}
	}
	if (check[1] == 0 && check2[n] == 0 && check2[2] == 0) {
	//	cout << "sDF";
		ans++;
		check2[1] = 1;
	}
	for (int i = 2; i < n; i++) {
		if (check[i] == 1)continue;
		if (check2[i - 1] == 0 && check2[i + 1] == 0) {
	//		cout << i << " ";
			check2[i] = 1;
			ans++;
		}
	}
	if (check[n] == 0 && check2[n-1] == 0 && check2[1] == 0) {
		//cout << "qwe";
		ans++;
		check2[n] = 1;
	}
	cout << ans;
}
	