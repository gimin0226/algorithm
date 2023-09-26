#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long a,b;
	cin >> a >> b;
	queue<long long> que;
	unordered_set<long long> s;
	que.push(a);
	s.insert(a);
	queue<string> que2;
	que2.push("");
	if (a == b) {
		cout << "0";
		return 0;
	}
	while (!que.empty()) {
		
		long long x = que.front(); que.pop();
		string str = que2.front(); que2.pop();
	//	cout << x << endl;
		if (x == b) {
			cout << str;
			return 0;
		}
		if (s.find(x * x) == s.end()) {
			que.push(x * x);
			s.insert(x * x);
			que2.push(str + "*");
		}
		if (s.find(x + x) == s.end()) {
			que.push(x + x);
			s.insert(x + x);
			que2.push(str + "+");
		}
		if (s.find(x - x) == s.end()) {
			que.push(x - x);
			s.insert(x - x);
			que2.push(str + "-");
		}
		if (x!=0&&s.find(x / x) == s.end()) {
			que.push(x / x);
			s.insert(x / x);
			que2.push(str + "/");
		}
	}
	cout << "-1";
	return 0;
}