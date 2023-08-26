#include<iostream>
#include<vector>	
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
vector<pair<int, int>>* vec;
const int INF = INT_MAX;
int n, m;
int start_point, end_point;
int* dist;
vector<int>* back_number;
void Dijkstra() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start_point] = 0;
	pq.push(make_pair(dist[start_point], start_point));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (cost > dist[idx]) {
			continue;
		}
		for (int i = 0; i < vec[idx].size(); i++) {
			int cost2 = vec[idx][i].first;
			int idx2 = vec[idx][i].second;

			if (cost2 + cost < dist[idx2]) {
				dist[idx2] = cost2 + cost;
				pq.push(make_pair(dist[idx2], idx2));
				back_number[idx2].clear();
				back_number[idx2].push_back(idx);

			}
			else if (cost2 + cost == dist[idx2]) {
				back_number[idx2].push_back(idx);
				
			}
		}
	}







}

int main(void) {


	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			exit(0);
		}
		cin >> start_point >> end_point;
		vec = new vector<pair<int, int>>[n];
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec[a].push_back(make_pair(c, b));
		}
		dist = new int[n];
		back_number = new vector<int>[n];
		for (int i = 0; i < n; i++) {
			dist[i] = INF;
		}
		Dijkstra();
		//	cout <<"정답"<< dist[end_point]<<endl;

	/*		for (int i = 0; i < n; i++) {
				if (back_number[i].empty()) {
					cout << i << "번째: 백넘버가 없다" << endl;
				}
				else {
					cout << i << "번째: ";
					for (int j = 0; j < back_number[i].size(); j++) {
						cout <<back_number[i][j] << " ";
					}
					cout << endl;
				}
			}*/
		vector<pair<int, int>> que;

		queue<int> que2;
		que2.push(end_point);
		bool check[501] = { false };

		while (!que2.empty()) {
			int idx2 = que2.front();
			if (idx2 == start_point) {
				que2.pop();
				continue;
			}
			que2.pop();
			check[idx2] = true;
			for (int i = 0; i < back_number[idx2].size(); i++) {
				if (back_number[idx2][i] == 0) {
					que.push_back(make_pair(0, idx2));
					continue;
				}
				else {
					if (check[back_number[idx2][i]] == true) {
						continue;
					}
					que.push_back(make_pair(back_number[idx2][i], idx2));
					que2.push(back_number[idx2][i]);
				}
			}
		}
		for (int i = 0; i < que.size(); i++) {
			int target = que[i].second;
			//cout << que[i].first<<"," << que[i].second << " ";
			vec[que[i].first].erase(remove_if(vec[que[i].first].begin(), vec[que[i].first].end(),
				[target](const pair<int, int>& p) {return p.second == target; }), vec[que[i].first].end());
		}//cout << endl;

		for (int i = 0; i < n; i++) {
			dist[i] = INF;
		}
		Dijkstra();
		if (dist[end_point] == INF) {
			cout << "-1" << endl;
		}
		else {
			cout << dist[end_point] << endl;
		}
		delete[] vec;
		delete[] dist;
		delete[] back_number;
	}
}