#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>> pq;//난이도가 어려운 순서 //문제 난이도,문제 번호
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;//난이도가 쉬운 순서
unordered_map<int, int> um;


int main() {
	int n;
	cin >> n;
	
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pq.push({ y,x }); //y:난이도 x:문제 번호
		pq2.push({ y,x });
		um[x] = y;
	}

	int t;
	cin >> t;
	string str;
	for (int i = 0; i < t; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x >> y;
			pq.push({ y,x });
			pq2.push({ y,x });
			um[x] = y;
		//	cout << pq2.top().first << " " << pq2.top().second << '\n';
		}
		else if (str == "recommend") {
			cin >> x;
			if (x == 1) {
				while (true) {
					if (um[pq.top().second] != pq.top().first) {
					
						pq.pop();
						continue;
					}
					//um[pq.top().second] = 0;
					cout << pq.top().second << '\n';
					
					break;
				}
			}
			else if (x == -1){
				while (true) {
					//cout << "fsd" << pq2.top().first << endl;
					if (um[pq2.top().second] != pq2.top().first) {
					
						pq2.pop();
						continue;
					}
				//	um[pq2.top().second] = 0;
					cout << pq2.top().second << '\n';
					
					break;
				}
			}
		}
		else if (str == "solved") {
			cin >> x;
			um[x] = 0;
		//	cout << um[x] << '\n';
		}
	}
}