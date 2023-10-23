#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[101];  //그다음 위치, 비용

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	int t;
	if (b >= n)t = b;
	else t = n;
	if (a > t) {
		cout << "Subway";
		return 0;
	}
	else if (a < t) {
		cout << "Bus";
		return 0;
	}
	else {
		cout << "Anything";
		return 0;
	}

}