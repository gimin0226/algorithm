#include<bits/stdc++.h>

using namespace std;
int n;
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

const int INF = 1e7;
char arr[51][51];
int dist[51][51];
pair<int,int> door[2];
void Dijkstra(int N) {
    priority_queue < tuple<int,int, int,int>, vector < tuple<int,int, int,int >> , greater<> > pq;
    //<int,int,int,int> a b c d    
    //door[N]에서 (b,c)까지 가기위해 a개의 거울이 필요하다 빛이 d방향에서 옴
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }
    int visited[51][51] = { 0 };
    for (int i = 0; i < 4; i++) {
        int nx = door[N].first;
        int ny = door[N].second;
        while (true) {
            nx += dx[i]; ny += dy[i];
            if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || arr[nx][ny] == '*')break;
            if (nx == door[1].first && ny == door[1].second) {
                cout << "0";
                return;
            }
            if (arr[nx][ny] == '!') {
                pq.push({ 1,nx,ny,i});
                dist[nx][ny] = 1;
            }
        }
    }
  

    while (!pq.empty()) {
        int num, x, y,direct;
        tie(num, x, y,direct) = pq.top();
        pq.pop();
        if (num > dist[x][y])continue;
        for (int i = 0; i < 4; i++) {
            if (direct >= 2) {
                if (i >= 2)continue;
            }if (direct < 2) {
                if (i < 2)continue;
            }
            int nx = x;
            int ny = y;    
            while (true) {
                nx += dx[i]; ny += dy[i];
                if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || arr[nx][ny] == '*')break;
                if (nx == door[1].first && ny == door[1].second) {
                    cout << num;
                    return;
                }
                if (arr[nx][ny] == '!'&&num+1<dist[nx][ny]) {
                    pq.push({ num+1,nx,ny,i });
                    dist[nx][ny] = num+1;
                }
            }
        }/*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF)cout << "!";
                else cout << dist[i][j];
            }cout << endl;
        }cout << endl;
        */
    }
    cout << "0";
    return;
}
int main() {
    cin >> n;
    int check = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '#') {
                if (check == 1) {
                    door[1].first = i;
                    door[1].second = j;
                }
                else {
                    door[0].first = i;
                    door[0].second = j;
                    check++;
                }
            }
        }
    }
    Dijkstra(0);
    return 0;
}