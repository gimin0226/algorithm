#include<bits/stdc++.h>
#include <climits>
using namespace std;


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v1;  //음수 저장
	vector<int> v2;  //양수 저장
	bool zero = false;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t < 0) {
			v1.push_back(t);
		}
		else if (t > 0) {
			v2.push_back(t);
		}
		else if (t == 0) {
			zero = true;
		}
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(), v2.end());
	int min = INT_MAX;
	int a, b;

	if (v1.empty()) {//전부 양수
		if (zero)cout << 0 << " " << v2[0];
		else if(1)cout << v2[0] << " " << v2[1];
	}
	else if (v2.empty()) {
		if (zero)cout<< v1[v1.size() - 1] <<" " << 0;
		else if(1)cout << v1[v1.size() - 2] <<" "<< v1[v1.size() - 1];
	}
	else {
		if (zero) {
			min = v2[0];
			a = 0; b = v2[0];
		}
		else {
			if (v2.size() > 1) {
				min = v2[0] + v2[1];
				a = v2[0]; b = v2[1];
			}
		}

		if (zero) {
			if (abs(v1[v1.size() - 1]) < min) {
				min = abs(v1[v1.size() - 1]);
				a = v1[v1.size() - 1]; b = 0;
			}
		}
		else {
			if (v1.size() > 1) {
				if (abs(v1[v1.size() - 1] + v1[v1.size() - 2]) < min) {
					min = abs(v1[v1.size() - 1] + v1[v1.size() - 2]);
					a = v1[v1.size() - 2]; b = v1[v1.size() - 1];
				}
			}
		}
		
		for (int i = 0; i < v1.size(); i++) {
			int x = -v1[i];
			int y;
			auto it = lower_bound(v2.begin(), v2.end(), x);
			
			if (it == v2.end()) {
				y = *(it - 1);
				int tmp = abs(y + v1[i]);
				
				if (tmp < min) {
				//	cout << "sdf";
					a = v1[i];
					b = y;
					min = tmp;
				//	cout << a << " " << b << '\n';
				}
			}
			else if (it == v2.begin()) {
				y = *it;
				int tmp = abs(y + v1[i]);
				if (tmp < min) {
					
					a = v1[i];
					b = y;
					min = tmp;
				//	cout << a << " " << b << '\n';
				}
			}
			else {
				
				auto it2 = it - 1;
				int tmp1 = abs(*it + v1[i]);
				int tmp2 = abs(*it2 + v1[i]);
				if (tmp1 < tmp2) {
					if (tmp1 < min) {
						
						a = v1[i];
						b = *it;
						min = tmp1;
				//		cout << a << " " << b << '\n';
					}
				}
				else {
					if (tmp2 < min) {
						a = v1[i];
						b =*it2;
						min = tmp2;
					//	cout << a << " " << b << '\n';
					}
				}
			}
		}
		cout << a <<" " << b;
	}



}