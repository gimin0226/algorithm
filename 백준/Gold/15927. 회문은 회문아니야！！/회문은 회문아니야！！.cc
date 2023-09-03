#include<bits/stdc++.h>

using namespace std;

bool allEqual(const string& str) {
	for (char c : str) {
		if (c != str[0]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	string str;
	cin >> str;
	int n = str.length();

	string str2=str;
	reverse(str.begin(), str.end());
	if (str2 != str) {
		cout << n;
		return 0;
	}
	else {
		if (allEqual(str2))
		{
			cout << -1;
		}
		else {
			cout << n - 1;
		}
		return 0;
	}
}