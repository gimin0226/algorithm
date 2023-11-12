#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int n;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int arr[301];
int arr2[301][301];
int visited[301] = { 0 };
int dist[301] = { 0 };
long long sum = 0;
void prim() {
    for (int i = 1; i <= n; i++)dist[i] = INF;
    
    while(!pq.empty()) {
        int cost, node;
        tie(cost, node) = pq.top();
        pq.pop();

       // for (int i = 1; i <= n; i++)cout << dist[i] << " ";
      //  cout << endl;
        if (dist[node] == -1)continue;
        dist[node] = -1;
        sum += cost;
        
     //   cout << cost << " " << node << endl;
        for (int i = 1; i <= n; i++) {
            if (i == node)continue;
            if (arr2[node][i] < dist[i]) {
                dist[i] = arr2[node][i];
                pq.push({ dist[i],i });
            }
        }
    }
    cout << sum;
}
int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        arr[i] = k;
        pq.push({ k,i });
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr2[i][j];
        }
    }
    prim();
}