#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<long long> q;

int n;

long long num = 0;

void BackTracking() {
	if (q.empty()) {
		cout << -1;
		exit(0);
	}
	long long t = q.size();
	for(int i=0;i<t;i++) {
		long long x = q.front();
		q.pop();
		if (x % 10 != 0) {
			int t = x % 10;
			for (int j = 0; j < t; j++) {
				q.push(x * 10 + j);
			//	cout<<x * 10 + j<<endl;
				num++;
				if (num == n) {
					cout << x * 10 + j<<endl;
					exit(0);
				}
			}
		}
	}
	BackTracking();
}

int main(void) {
	std::cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		if (n == i) {
			cout << i;
			return 0;
		}
		q.push(i);
	}
	num = 9;
	BackTracking();
}