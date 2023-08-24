
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>  

using namespace std;

const int INF = INT_MAX;  //climits 헤더를 통해 
vector<pair<int, int>>* vec;

int x_distance[1001];
int dist[1001];//distance는algorithm 헤더에 이미 정의된 함수

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};
int Dijkstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	fill(dist, dist + 1001, INF);
	dist[start] = 0;
	pq.push(make_pair(start, dist[start]));
	while (!pq.empty())
	{
		int idx = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (distance > dist[idx]) {
			continue;
		}
		for (int i = 0; i < vec[idx].size(); i++) {
			int idx2 = vec[idx][i].first;
			int distance2 = vec[idx][i].second;
			if (distance + distance2 < dist[idx2]) {
				dist[idx2] = distance + distance2;
				pq.push(make_pair(idx2, dist[idx2]));
			}
		}
	}
	return dist[end];
}
void Dijkstra2(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	fill(x_distance, x_distance + 1001, INF);
	x_distance[start] = 0;
	pq.push(make_pair(start, x_distance[start]));
	while (!pq.empty())
	{
		int idx = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (distance > x_distance[idx]) {
			continue;
		}
		for (int i = 0; i < vec[idx].size(); i++) {
			int idx2 = vec[idx][i].first;
			int distance2 = vec[idx][i].second;
			if (distance + distance2 < x_distance[idx2]) {
				x_distance[idx2] = distance + distance2;
				pq.push(make_pair(idx2, x_distance[idx2]));
			}
		}
	}
	return;
}
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vec = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int start, end, size;
		cin >> start >> end >> size;
		vec[start].push_back(make_pair(end, size));
	}
	int* answer = new int[n + 1]();
	Dijkstra2(x);
	for (int i = 1; i < n + 1; i++) {
		answer[i] += x_distance[i];
		answer[i] += Dijkstra(i, x);
	}
	
	int max = *max_element(answer, answer + n+1);
	printf("%d", max);

	delete[] vec;
	delete[] answer;
}