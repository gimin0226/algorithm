#include<bits/stdc++.h>

using namespace std;

priority_queue<int> pq[12];
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq[x].push(y);
	}


	for (int i = 0; i < m; i++) {

		for (int j = 1; j < 12; j++) {
			if (pq[j].empty()) {
				
				continue;
			}
			else {
				int x = pq[j].top();
				if (x == 0) {
					continue;
				}
				pq[j].pop();
				pq[j].push(x - 1);
				
			}
		}
	}
	
	int sum = 0;
	for (int i = 1; i < 12; i++) {
		if (pq[i].empty()) {
			
			continue;
		}
		else {
			//cout << pq[i].top() << endl;
			sum += pq[i].top();
		}
	}

	cout << sum;
}