#include <bits/stdc++.h>
using namespace std;
int n, l;
typedef pair<int, int> pa;
vector<pa> vec[201];  //거리, 연결 노드 번호
int dist[201];
int arr[201];
void Dijkstra(int start) {
    priority_queue<pa, vector<pa>, greater<>> pq;
    for (int i = 0; i < 201; i++) {
        dist[i] = INT_MAX;
        arr[i] = i;
    }
    dist[start] = 0;
    pq.push({ dist[start],start });

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if (dist[current] < distance)continue;
        for (int i = 0; i < vec[current].size(); i++) {
            int next_distance = vec[current][i].first;
            int next = vec[current][i].second;
            if (next_distance + distance < dist[next]) {
                if (current == start)arr[next] = next;
                else arr[next] = arr[current];
                dist[next] = next_distance + distance;
                pq.push({ dist[next],next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec[x].push_back({ z,y });
        vec[y].push_back({ z,x });
    }
   
    for (int i = 1; i <= n; i++) {
        Dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (i == j)cout << "- ";
            else {
                cout << arr[j] << " ";
            }
        } cout << endl;
    }
}