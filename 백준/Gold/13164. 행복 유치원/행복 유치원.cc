#include<bits/stdc++.h>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;
	int x;
	int y;
	cin >> y;
	vector<int> v;
	long long sum = 0;
	for (int i = 1; i <n; i++) {
		cin >> x;
		v.push_back(x - y);
		sum += x - y;
		y = x;
	}
	sort(v.rbegin(), v.rend());
	
	for (int i = 0; i < m - 1; i++) {
		sum -= v[i];
	}
	cout << sum;
}