#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> plus;
	vector<int> minus;
	int t;

	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t > 0) {
			plus.push_back(t);
		}
		else if (t < 0) {
			minus.push_back(-t);
		}
	}
	if(plus.size()!=0)sort(plus.begin(), plus.end(),greater<int>());
	if(minus.size()!=0)sort(minus.begin(), minus.end(),greater<int>());
	int sum = 0;
	if (minus.size() == 0) {
		sum += plus[0];
		int i = m;
		while ( i < plus.size()) {
			sum += 2 * plus[i];
			i += m;
		}
	}
	else if (plus.size() == 0) {
		sum += minus[0];
		int i = m;
		while ( i < minus.size()) {
			sum += 2 * minus[i];
			i += m;
		}
	}
	else if (plus[0] >= minus[0]) {
		sum += plus[0];
		int i = m;
		while (plus.size()!=0&&i < plus.size()) {
			sum +=2* plus[i];
			i += m;
		}

		i = 0;
		while (minus.size()!=0&&i < minus.size()) {
			sum += 2*minus[i];
			i += m;
		}
	}else {
		sum += minus[0];
		int i = 0;
		while (plus.size() != 0 && i < plus.size()) {
			sum += 2*plus[i];
			i += m;
		}

		i = m;
		while (minus.size() != 0 && i < minus.size()) {
			sum += 2*minus[i];
			i += m;
		}
	}
	cout << sum;
}
	