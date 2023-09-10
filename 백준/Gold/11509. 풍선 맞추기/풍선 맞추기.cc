#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;


int main(void) {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	int minn = INT_MAX;
	vector<int> v2(n);
	unordered_map<int, int> um; //int:높이 int:화살의 개수
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (um.find(v[i]) == um.end()||um[v[i]]==0) {
			num++;
		}
		else if (um[v[i]] > 0) {
			um[v[i]] -= 1;	
		}
		if (um.find(v[i] - 1) == um.end()) {
			um.insert({ v[i] - 1,1 });
		}
		else {
			um[v[i] - 1] += 1;
		}
	}
	cout << num;
}
