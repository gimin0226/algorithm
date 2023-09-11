#include<bits/stdc++.h>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int d, n;
	cin >> d >> n;
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < d; i++) {
		int t;
		cin >> t;
		v1.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v2.push_back(t);	
	}

	int k = 0;
	int deep = 0;
	vector<int> vec(d+2);
	vec[0] = v1[0];
	while (true) {
		
		if (v2[0] > v1[k]) {
			break;
		}
		if(k>0)vec[k] = min(vec[k-1], v1[k]);
		k++;
		deep++;
	}
	/*
	for (int i = 0; i < k; i++) {
		cout << vec[i] << " ";
	}cout << endl;*/

	k -= 1;

	for (int i = 0; i < v2.size(); i++) {
		while (true) {
			if (k < 0) {
				cout << "0";
				return 0;
			}
			if (v2[i] <= vec[k]) {
			//	cout << v2[i] << " " << k << '\n';
				k--;
				break;
			}
			k--;
		}
	}

	cout << (k + 2);

	
}

