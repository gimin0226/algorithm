#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int>> v[21];
const int INF = 1e8;

int visited[21];
int dist[21];
int path[21];
void pa(int i) {
	if (i == path[i]) {
		cout << i << " ";
		return;
	}
	pa(path[i]);
	cout << i<<" ";
}

void Dijkstra() {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> pq;
	pq.push({ 0,0 });
	visited[0] = 1;
	dist[0] = 0;

	while (!pq.empty()) {
		int node;
		int cost;
		cost = pq.top().first;
		node = pq.top().second;
		pq.pop();
		if (cost > dist[node])continue;
		for (int i = 0; i < v[node].size(); i++) {
			int next_node = v[node][i].first;
			int next_cost = v[node][i].second;
			if (cost + next_cost < dist[next_node]) {
				dist[next_node] = cost + next_cost;
				pq.push({ dist[next_node],next_node });
				path[next_node] = node;
			}
		}
	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		int n, m;
		cin >> m >> n;
		for (int i = 0; i < 21; i++) {
			v[i].clear();
			visited[i] = 0;
			dist[i] = INF;
			path[i] = i;
		}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[x].push_back({ y,z });
			v[y].push_back({ x,z });
		}


		Dijkstra();
		cout << "Case #" << T+1 << ": ";
		if (dist[n - 1] == INF) cout << -1;
		else pa(n - 1);
		cout << endl;
	}
}
