#include <bits/stdc++.h>
using namespace std;

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

int arr[101][101];
int visited[101][101];

int n, m;
int ti = 0;
int bfs(int num) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> que;
    que.push({ 0,0 });
    visited[0][0] = 1;
    queue<pair<int, int>> que2;
    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
            if (visited[nx][ny] == 1)continue;
            visited[nx][ny] = 1;

            if (arr[nx][ny] == 1) {
                arr[nx][ny] = -1;
                num -= 1;
                que2.push({ nx,ny });
            }
            else if (arr[nx][ny] == 0) {
                que.push({ nx,ny });
            }
        }
    }ti++;

    /*cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;
    */
    while (!que2.empty()) {
        int x, y;
        tie(x, y) = que2.front(); que2.pop();
        arr[x][y] = 0;
    }
    // cout << num << endl;
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                num++;
            }
        }
    }
    while (true) {
        int k = num;
        num = bfs(num);
        if (num == 0) {
            cout << ti << endl;
            cout << k;
            break;
        }
    }
    return 0;
}