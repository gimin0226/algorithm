#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int main(void) {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, int>> pq;
	multiset<int> myset;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ y,x });
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		myset.insert(x);
	}

	long long sum = 0;
	int num = m;
	while (!pq.empty()) {
		if (num == 0) {
			break;
		}
		int cost=pq.top().first;
		int weight=pq.top().second;
		pq.pop();
		auto it = myset.lower_bound(weight);
		
		if (it != myset.end()) {
			myset.erase(it);
			sum += cost;
			//cout << t<<" "<<cost << " " << weight << " " << sum << "\n";
			num -= 1;
		}
	}
	cout << sum;
}