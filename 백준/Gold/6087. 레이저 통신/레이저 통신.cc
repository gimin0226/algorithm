#include <bits/stdc++.h>
using namespace std;
         

#define INF 987654321
typedef pair<int, int> pa;
typedef tuple<int, int, int, int> tu;
char arr[101][101];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int n, m;
int check[4][101][101] = { 0 };
int dist[4][101][101];
void Dijkstra(int x,int y){
    
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dist[t][i][j] = INT_MAX;
            }
        }
    }

    priority_queue<tu,vector<tu>,greater<>> pq;
    pq.push({ 0,x,y,0 });
    pq.push({ 0,x,y,1 });
    pq.push({ 0,x,y,2 });
    pq.push({ 0,x,y,3 });
    for(int i=0;i<4;i++) dist[i][x][y] = 0;
    for (int i = 0; i < 4; i++) {
        check[i][x][y] = 1;
    }
    while (!pq.empty()) {
        
        int c_x, c_y,cost,direct;
        tie(cost, c_x, c_y, direct) = pq.top(); pq.pop();
     //   cout << c_x << " " << c_y << " " << direct << endl;
        
        if (cost > dist[direct][c_x][c_y])continue;
        for (int i = 0; i < 4; i++) {
           
            int nx, ny, n_cost;
            int n_direct=i;
            nx = c_x + dx[i]; ny = c_y + dy[i];
            
            if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
            if (arr[nx][ny] == '*')continue;
            
            if (n_direct == direct)n_cost = cost;
            else n_cost=cost + 1;
            if (nx == 3 && ny == 1) {
          //      cout << n_direct << " " << direct << " " << n_cost << " " << cost << endl;
            }
            if (n_cost < dist[n_direct][nx][ny]) {
        
                dist[n_direct][nx][ny] = n_cost;
                pq.push({ n_cost,nx,ny,n_direct });
            }

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

   
    cin >> m >> n;
    int s_x, s_y, e_x, e_y;
    int che = 0; 
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++){
            arr[i][j] = str[j];
            if (str[j] == 'C') {
                if (che == 0) {
                    s_x = i;  s_y = j;
                    che++;
                }if (che == 1) {
                    e_x = i; e_y = j;
                }
            }
        }
    }
    Dijkstra(s_x, s_y);
   /* cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == INT_MAX)cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }cout << endl;
    }*/
    
    int result = INT_MAX;
    for (int i = 0; i < 4; i++) {
        result = min(result, dist[i][e_x][e_y]);
    }
    cout <<result;
}