#include<iostream>
#include<vector>	
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
vector<pair<int, int>>* vec;
const int INF = INT_MAX;
int n, m, k;
int start_point = 1;
priority_queue < int> pq2[1001];
void Dijkstra() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push(make_pair(0, start_point));
	pq2[1].push(0);
	while (!pq.empty()) {
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < vec[idx].size(); i++) {
			int next_cost = vec[idx][i].first;
			int next_idx = vec[idx][i].second;
			
			if (pq2[next_idx].size() < k) {
				pq2[next_idx].push(cost + next_cost);
				pq.push({ cost + next_cost, next_idx });
			}
			else if (pq2[next_idx].top() > cost + next_cost) {
				pq2[next_idx].pop();
				pq2[next_idx].push(cost + next_cost);
				pq.push({ cost + next_cost, next_idx });
			}
		}//cout << endl;
	}
}

int main(void) {
	cin >> n >> m >> k;
	vec = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(c, b));
	}
	Dijkstra();

	for (int i = 1; i <= n; i++) {
		if (pq2[i].size() < k) {
			cout << "-1\n";
		}
		else {
			cout << pq2[i].top() << '\n';
		}
	}

	return 0;


}