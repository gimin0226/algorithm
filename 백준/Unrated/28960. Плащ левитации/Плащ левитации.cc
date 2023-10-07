#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);
	
	int h, l, a, b;
	cin >> h >> l >> a >> b;
	if ((double)a / 2 <= h && b <= l) {
		cout << "YES";
		return 0;
	}
	if ((double)b / 2 <= h && a <= l) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
