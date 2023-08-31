#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int  n, m, l;
	cin >> n >> m >> l;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	sort(v.begin(), v.end());

	
	vector<int> v2;
	if (v.empty()) {
		v2.push_back(l-1);
	}
	else {
		v2.push_back(l - v[v.size() - 1] - 1);
		v2.push_back(v[0] - 1);
		for (int i = 0; i < v.size() - 1; i++) {
			v2.push_back(v[i + 1] - v[i] - 1);
		//	cout << v[i + 1] - v[i] - 1 << " ";
		}//cout << '\n';
	}
	//cout << "fsda";

	int low = 1;
	int high = l;
	int mid;
	int min = INT_MAX;
	while (true) {
		if (low>high) {
			break;
		}
		mid = (low + high) / 2;
		
		int num = 0;
		for (int i = 0; i < v2.size(); i++) {
			num += v2[i] / mid;
		}

		if (num > m) {
			low = mid + 1;
		}
		else {
			if (mid  < min) {
		//		cout << num <<" "<<mid << '\n';
				min = mid;
			}
			high= mid - 1;
		}
	}
	cout << min;
}