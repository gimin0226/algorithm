#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[10001][501];
int dx[]{ -1,0,1 };
int dy[]{ 1,1,1 };
int ti = 0;
bool visited[10001][501];
int ans = 0;
int num = 1;
int arr2[10001][501] = { 0 };

int dfs(int x, int y) {
   // cout << x << " " << y << endl;
    arr2[x][y] = num;
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)continue;
        if (visited[nx][ny])continue;
        visited[nx][ny] = 1;

        if (arr[nx][ny] == '.') {
            if (ny == m - 1) {
                ans++;
              //  cout <<"dafas"<< nx << " " << ny << endl;
                return 0;
            }
            int t=dfs(nx, ny);
            if (t == 0) {
                return 0;
            }
        }
    }
    return 1;
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
    
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
        num++;
    }
   /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr2[i][j];
        }cout << endl;
    }*/
    cout << ans;
}