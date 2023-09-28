#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	int t;
	vector<int> v;
	long long max = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t;
			sum += t;

			if (t != 0) {
				v.push_back(t);
			}
			if (max < t) {
				max = t;
			}
		}
	}
	

	int start = 0;
	int end = max;
	while (true) {
		
		if (start >= end) {
			cout << end;
			return 0;
			
		}
		int mid = (start + end) / 2;
		//cout << mid << endl;
		long long num = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] <= mid) {
				num += v[i];
			}
			else if (v[i] > mid) {
				num += mid;
			}
		}
		//cout << num<<endl;
		if (((double)num/(double)sum*100)>=50) {
			end = mid;
		}
		else{
			start = mid + 1;
		}
		
	}

	
}
	