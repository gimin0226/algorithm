#include <bits/stdc++.h>
using namespace std;
         

#define INF 987654321
typedef pair<int, int> pa;
int dist[2001];
int check[2001] = { 0 };
int g, h;
void Dijkstra(int start,const vector<pa> vec[]) {
    priority_queue<pa, vector<pa>, greater<>> pq;
    dist[start] = 0;
    check[start] = 0;
    pq.push({ dist[start],start });
    
    while (!pq.empty()) {
        int current, distance;
        tie(distance, current) = pq.top(); pq.pop();

        if (dist[current] < distance)continue;
        for (int i = 0; i < vec[current].size(); i++) {
            int next, next_distance;
            tie(next_distance, next) = vec[current][i];

         
            if (next_distance + distance == dist[next]) {
            //    cout << "Fdssfad" <<current<<" "<<next<<" "<<check[next] << endl;
                if (check[next] == 1)continue;
                if ((g == current && h == next) || (g == next && h == current)) {
                    check[next] = 1;
                }
                else check[next] = check[current];
             //   cout << check[next] << endl;
            }
            if (next_distance + distance <dist[next]) {
                if ((g == current && h == next)||(g==next&&h==current)) {
                    check[next] = 1;
                    
                    
                }
                else check[next] = check[current];
             //   cout << "Fd" << current << " " << next << endl;
                dist[next] = next_distance + distance;
                pq.push({ dist[next],next });
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int I = 0; I < T; I++) {
        vector<pa> vec[2001];
        vector<int> v;
        for (int i = 0; i < 2001; i++) {
            check[i] = 0;
            dist[i] = INF;
        }
        int n, m, t;
        cin >> n >> m >> t;
        int s;
        cin >> s >> g >> h;
    
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            vec[x].push_back({ z,y });
            vec[y].push_back({ z,x });
        }
        Dijkstra(s,vec);
        for (int i = 0; i < t; i++) {
            int p; cin >> p;
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (check[v[i]] == 1)cout << v[i] << " ";
        }cout << endl;
    }
}