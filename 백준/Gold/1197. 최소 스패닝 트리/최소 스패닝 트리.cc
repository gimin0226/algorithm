#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int F = 0;
int nearest[10001];
int dist[10001];
vector<pair<int,int>> vec[10001];
int visited[10001] = { 0 };

int sum = 0;
void prim(int n) {
	for (int i = 2; i <= n; i++) {
		nearest[i] = 1;
		dist[i] = INF;
	}
	for (int i = 0; i < vec[1].size(); i++) {
		int x, y;
		tie(x, y) = vec[1][i];
		dist[x] = y;
	}
	int vnear;
	for (int t = 0; t < n-1; t++) {
		int minn = INF;
		for (int i = 2; i <= n; i++) {
			if (visited[i]==0 && dist[i] < minn) {
				vnear = i;
				minn = dist[i];
			}
		}

		sum += dist[vnear];
		visited[vnear] = 1;

		for (int i = 0; i < vec[vnear].size(); i++) {
			int x = vec[vnear][i].first;
			int y = vec[vnear][i].second;
			if (y< dist[x]) {
				dist[x] = y;
				nearest[x] = vnear;
			}
		}
	}
	
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, e;
	cin >> n>> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	prim(n);
	cout << sum;
}