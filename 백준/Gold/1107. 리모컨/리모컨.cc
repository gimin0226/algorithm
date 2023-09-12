#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
int x;
int minn = INT_MAX;	
int len;
void recursion(string str,int num) {
	
	
	if (!str.empty()&&stoi(str) > x) {
		int num2 = num + (stoi(str) - x);
		minn = min(minn, num2);
		return;
	}

	if (num >= 1&&!str.empty()) {
		int num2 = num + x - stoi(str);
		minn = min(num2, minn);
	}
	for (int i = 0; i < vec.size(); i++) {
		string str2="";
		if (vec[i] == 0 && str == "") { 
			minn = min(minn, x +1);
			continue; }
		str2 += str;
		str2+=to_string(vec[i]);
	//	cout << str2 << endl;
		recursion(str2, num + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x;
	len = to_string(x).length();
	int n;
	cin >> n;
	int arr[10] = { false };
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a] = true;
	}
	
	
	for (int i = 0; i < 10; i++) {
		if (arr[i] == false) {
			vec.push_back(i);
		}
	}

	minn = abs(x - 100);
	recursion("", 0);
	cout << minn;
}




