#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
int check[1001][1001][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    queue<tuple<int, int, int, int>> q; // x, y, distance, broken
    q.push({0, 0, 1, 0});
    check[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, dist, broken;
        tie(x, y, dist, broken) = q.front(); q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << dist;
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (arr[nx][ny] == 1 && !broken) {
                if (!check[nx][ny][1]) {
                    check[nx][ny][1] = 1;
                    q.push({nx, ny, dist + 1, 1});
                }
            }
            
            if (arr[nx][ny] == 0 && !check[nx][ny][broken]) {
                check[nx][ny][broken] = 1;
                q.push({nx, ny, dist + 1, broken});
            }
        }
    }
    
    cout << -1;
    return 0;
}
