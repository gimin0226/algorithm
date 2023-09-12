#include<bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x>> y;
		pq.push({ x,y });
	}
	

	int end = pq.top().second;
	pq.pop();
	int num = 1;

	while (!pq.empty()) {
		int x, y;
		tie(x, y) = pq.top();
		pq.pop();
		if (x >= end) {
			num++;
			end = y;
		//	cout << x << end<<'\n';
		}
		else if (y < end) {
			end = y;
		//	cout << "y"<<y << end << '\n';
		}
	}
	cout << num;
}