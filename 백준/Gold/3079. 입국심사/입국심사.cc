#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long n, m;
	cin >> n >> m;
	vector<unsigned long long> vec;
	unsigned long long max2 = 0;
	for (int i = 0; i < n; i++) {
		unsigned long long t;
		cin >> t;
		vec.push_back(t);
		if (t > max2) {
			max2 = t;
		}
	}

	unsigned long long low = 1;
	unsigned long long high = max2*m;
	unsigned long long mid;
	unsigned long long min=high;

	int size = vec.size();
	while (true) {
		unsigned long long sum = 0;
		if (low > high) {
			break;
		}

		mid = (low + high) / 2;
		for (int i = 0; i < size; i++) {
			sum += mid / vec[i];
		}
		
		if (sum<m) {
			low = mid + 1;
		}
		else {
			if (mid < min) {
				min = mid;
			//	cout << min << '\n';
			}
			high = mid - 1;
		}
		

	}
	cout << min;
}