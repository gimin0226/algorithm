#include<bits/stdc++.h>

using namespace std;
string str;
int sum = 0;
int idx = 0;
int f() {
	int num = 0;
	while (idx < str.length()) {
		if (str[idx] == '(') {
			num -= 1;
		//	cout << num << endl;
			idx += 1;
			int t = (str[idx-2] - '0') * f();
			num += t;
		//	cout << "back" << num << endl;
		}
		else if (str[idx] == ')') {
			idx++;
			return num ;
		}
		else {
			idx++;
			num++;
		}
		
	}
	return num;
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> str;
	cout<<f();
}