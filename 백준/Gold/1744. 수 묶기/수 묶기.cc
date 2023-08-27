#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> nega;
priority_queue<int> posi;
int zero=0;
int main(void) {
	cin >> n;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			zero += 1;
		}
		else if (t < 0) {
			nega.push(t);
		}
		else if (t > 0) {
			posi.push(t);
		}
	}

	while (!nega.empty()) {
		if (nega.size() == 1) {
			if (zero == 0) {
				sum += nega.top();
				nega.pop();
			}
			else if (zero > 0) {
				sum += 0;
				nega.pop();
			}
		}
		else {
			int x = nega.top();
			nega.pop();
			int y = nega.top();
			nega.pop();
			sum += x * y;
		}
	}
	while (!posi.empty()) {
		if (posi.size() == 1) {
			sum += posi.top();
			posi.pop();
		}
		else {
			int x = posi.top();
			posi.pop();
			int y = posi.top();
			posi.pop();
			if (x == 1 || y == 1) {
				sum += x + y;
			}
			else {
				sum += x * y;
			}
		}
	}
	cout << sum;
}