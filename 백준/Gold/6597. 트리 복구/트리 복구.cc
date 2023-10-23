#include<bits/stdc++.h>
using namespace std;


string s1, s2;
int k = 0;
char arr[1000] = { 0 };
void f(int t, int start, int end) {
	if (start > end) return; // 범위가 잘못된 경우 반환

	if (start == end) {
		arr[t] = s1[k++];
		return;
	}

	for (int i = start; i <= end; i++) {
		if (s2[i] == s1[k]) {
			arr[t] = s1[k];
			k++;
			f(2 * t, start, i - 1);
			f(2 * t + 1, i + 1, end);
			return;
		}
	}
}

void f2(int x) {
	if (arr[x] == 0)return;
	f2(2 * x);
	f2(2 * x + 1);
	cout << arr[x];
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> s1 >> s2;
		if (cin.eof())break;
		for (int i = 0; i < 100; i++)arr[i] = 0;
		k = 0;
		f(1, 0, s2.length());
		f2(1);
		cout << endl;
	}
	
}