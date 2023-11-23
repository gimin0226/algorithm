#include<bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v[21];
const int INF = 1e8;
int arr[11];
int n;
vector<int> v1;
vector<int> v2;
int cal() {
	int sum = 0;
	int tmp = v1[0];

	for (int i = 0; i < v1.size() - 1; i++) {
		switch (v2[i]) {
		case '+':
			tmp += v1[i + 1];
			break;
		case '-':
			tmp -= v1[i + 1];
			break;
		}
	}
	return tmp;
}
void f2(int x) {
	string str = to_string(x);
	int len = to_string(x).length();
	for (int i = 0; i < len; i++) {
		if (i == len - 1)cout << str[i];
		else cout << str[i] << " ";
	}
}
void f(int x, int i) {
	if (i == n) {

		v1.push_back({ x });
		if (cal() == 0) {
			//cout << v1.size() << " " << v2.size() << endl;
			for (int i = 0; i < v2.size(); i++) {
				if (to_string(v1[i]).length() != 1)f2(v1[i]);
				else cout << v1[i];
				cout<<(char)v2[i];
			}
			if (to_string(v1[v1.size()-1]).length() != 1)f2(v1[v1.size()-1]);
			else cout << v1[v1.size() - 1];
			cout << endl;
		}
		v1.pop_back();
		return;
	}
	int t;
	//합치기
	t = x * 10 + i + 1;
	f(t, i + 1);
	//+
	v1.push_back({ x });
	v2.push_back({ '+' });
	f(i + 1, i + 1);
	v1.pop_back();
	v2.pop_back();

	//-
	v1.push_back({ x });
	v2.push_back({ '-' });
	f(i + 1, i + 1);
	v1.pop_back();
	v2.pop_back();

}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;

		for (int i = 0; i < 11; i++)arr[i] = i;
		f(1, 1);
		cout << endl;
	}
}
