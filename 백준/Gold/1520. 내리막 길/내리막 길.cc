#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[501][501];
bool visited[501][501] = { false };
int dp[501][501] = { 0 };
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int dfs(int x,int y) {
   // cout << "x" << x << "y" << y << "dp[x][y]" << dp[x][y] << endl;
    if (x == n - 1 && y == m - 1) {
    //    cout << "wtrewtew x" << x << "y" << y << "dp[x][y]" << dp[x][y] << endl;
        return 1;
    }
    if (visited[x][y] == 1) {
   //     cout << dp[x][y] << endl;
        return dp[x][y];
    }

    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
        if (arr[nx][ny] < arr[x][y]) {
            dp[x][y] +=dfs(nx, ny);
        }
    }
    return dp[x][y];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }

    dfs(0,0);
     
    cout << dp[0][0];
    
}