#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

int maxx = 0;


void recursion(int num) {
	//cout << num << "     ";
	//for (int i = 0; i < n; i++) {
	//	cout << v[i].first << "," << v[i].second << " ";
	//}cout << endl;
	if (num == n) {
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0) {
				t++;
			}
		}
		maxx = max(t, maxx);
		return;
	}
	if (v[num].first <= 0) {
		recursion(num + 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num == i)continue;
		if (v[i].first > 0) {
			v[num].first -= v[i].second;
			v[i].first -= v[num].second;
			recursion(num + 1);
			v[num].first += v[i].second;
			v[i].first += v[num].second;
		}
		else {
			recursion(num + 1);
		}
	}
}

int main(void) {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	recursion(0);
	cout << maxx;
}
