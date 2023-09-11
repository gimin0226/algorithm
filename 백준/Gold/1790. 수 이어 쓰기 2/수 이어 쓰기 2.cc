#include<bits/stdc++.h>

using namespace std;


int main(void) {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string str=" ";
	int num = 0;
	for (int i = 1; i <= n; i++) {
		int ptr = num;
		num += to_string(i).length();
		if (num >= k) {
			//printf("i:%d ptr:%d num:%d k:%d\n", i, ptr, num, k);
			char c = to_string(i)[k - ptr-1];
			cout << c - '0';
			return 0;
		}
	}
	cout << -1;
	return 0;

	

}
