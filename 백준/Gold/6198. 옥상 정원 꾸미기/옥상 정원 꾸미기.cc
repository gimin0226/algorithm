#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		vec.push_back(t);
	}
	
	stack<int> sta;
	sta.push(vec[0]);
	long long num = 0;
	for (int i = 1; i < n; i++) {
		if (vec[i] < sta.top()) {
			num+=sta.size();
			sta.push(vec[i]);
		//	cout << vec[i]<< endl;
		}
		else {
			while (!sta.empty()&&vec[i]>=sta.top()) {
				sta.pop();
			}
			num += sta.size();
			sta.push(vec[i]);
		//	cout << vec[i] << endl;
		}
	}

	cout << num;
	return 0;
	
}
