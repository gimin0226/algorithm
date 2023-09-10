#include<bits/stdc++.h>

using namespace std;


//1cm=10,000,000 nm
vector<long long> v;
long long binarySearch(long long x) {

	
	long long left = 0;
	long long right = v.size() - 1;
	long long mid;
	while (true) {
		if (left > right) {
			return -1;
		};
		mid = (left + right) / 2;

		if (v[mid] > x) {
			right = mid - 1;
		}
		else if (v[mid] < x) {
			left = mid + 1;
		}
		else {
			return mid;
		}

	}
}
int main(void) {

	long long x;
	while (true) {
		
		cin >> x;
		if (cin.eof())break;

		
		x *= 10000000;
		long long n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			v.push_back(t);
		}

		sort(v.begin(), v.end());

		long long maxx = -1;
		long long a, b;
		for (int i = 0; i < v.size(); i++) {
			long long k = v[i];
			long long ptr = x - k;

			long long p = binarySearch(ptr);
			if (p != -1&&p!=i) {
				if (abs(v[p] - k) > maxx) {
					if (v[i] > v[p]) {
						maxx = abs(v[p] - k);
						a = v[p]; b = v[i];
					}
					else {
						maxx = abs(v[p] - k);
						a = v[i]; b = v[p];
					}
				}
			}
		}
		if (maxx == -1) {
			cout << "danger\n";
		}
		else {
			cout <<"yes " << a << " " << b<<'\n';
		}
		v.clear();
	}
	return 0;
	
}
