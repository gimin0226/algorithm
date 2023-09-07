#include<bits/stdc++.h>	

using namespace std;

const int INF = INT_MAX-1;
vector<pair<int, int>> vec[101]; //int int 연결된번호 길이 
int item[101];

int Dijkstra(int start,int n,int m) {
	int distance[101];
	for (int i = 1; i <= n; i++)distance[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //int int 거리 길이
	distance[start] = 0;
	pq.push({ distance[start],start });
	while (!pq.empty()) {
		int dist = pq.top().first;
		int num = pq.top().second;
		pq.pop();

		if (dist > distance[num])continue;

		for (int i = 0; i < vec[num].size(); i++) {
			int num2 = vec[num][i].first;
			int dist2 = vec[num][i].second;
			if (dist + dist2 < distance[num2]) {
				distance[num2] = dist + dist2;
				pq.push({ distance[num2],num2 });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (distance[i] <= m) {
			sum += item[i];
		}
	}

	return sum;
}

int main(void) {
	int n, m, r; //n:지역의 개수 m:수색범위 r:길의 개수

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		item[i] = t;
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	int max =0;
	for (int i = 1; i <= n; i++) {
		int x=Dijkstra(i,n,m);
		if (x > max) {
			max = x;
		}
	}

	cout << max;


}