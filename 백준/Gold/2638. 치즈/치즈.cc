#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101][101];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int ti = 0;

int sum = 0;
void bfs() {
    queue<pair<int,int>> que;
    queue<pair<int, int>> que2;

    bool visited[101][101] = { false };
    que.push({0,0});
    int arr2[101][101] = { 0 };
    visited[0][0] = 1;

    while (!que.empty()) {
      
        int x, y;
        tie(x, y) = que.front();
        que.pop();
        int che = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
            else if (arr[nx][ny] == 1) {
                arr2[nx][ny] += 1;
            //    cout << nx << " " << ny << " " << arr2[nx][ny] << endl;
            }
            if (arr2[nx][ny] == 2) {
                arr[nx][ny] = -1;
                sum -= 1;
                que2.push({ nx,ny });
            }
            if (visited[nx][ny] == 1)continue;
            visited[nx][ny] = 1;

            if (arr[nx][ny] == 0) {
                que.push({ nx,ny });
            }
           
        }
    }
    
    while (!que2.empty()) {
        int x, y;

        tie(x, y) = que2.front();

      //  cout << x << " " << y << endl;
        que2.pop();
        arr[x][y] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)sum++;
        }
    }

    while (true) {
        ti++;
        bfs();
        int che = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    che++;
                    break;
                }
            }
        }


        if (che==0) {
            cout << ti;
            return 0;
        }
   }
    
}