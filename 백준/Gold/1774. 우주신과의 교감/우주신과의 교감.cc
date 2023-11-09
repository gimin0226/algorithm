
#include<bits/stdc++.h>

using namespace std;
vector<long long> vec[1001];
const double INF = 1e8;
double dist[1001];
double arr[1001][1001];
double sum = 0;
int visited[1001] = { 0 };
void prim(int n, int m) {
    priority_queue<pair<double, int>,vector<pair<double,int>>,greater<>> pq;
    visited[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = i;
        double y = arr[1][i];
        pq.push({ y,x });
    }

    while (!pq.empty()) {
        int idx = pq.top().second;
        double dist = pq.top().first;
        pq.pop();

        if (visited[idx] == 0) {
            visited[idx] = 1;
            sum += dist;
        }
        else {
            continue;
        }

        for (int i = 2; i <= n; i++) {
            int next_idx = i;
            double next_dist = arr[idx][i];
            if (visited[next_idx] == 0) {
                pq.push({ next_dist,next_idx });
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> v;
    v.push_back({ 0,0 });
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    for (int i = 1; i < n; i++) {
        long long x1, y1;
        tie(x1, y1) = v[i];
        for (int j = i + 1; j <= n; j++) {
            long long x, y;
            tie(x, y) = v[j];
            long long k = (long long)(x - x1) * (x - x1) + (long long)(y - y1) * (y - y1);

            double t = sqrt(k);
            arr[i][j] = t;
            arr[j][i] = t;
        }
    }
    int p = m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 0;
        arr[b][a] = 0;
    }
    
   
    prim(n, p);
    printf("%.2f", sum);
    return 0;
}
