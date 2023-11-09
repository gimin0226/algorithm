#include<bits/stdc++.h>

using namespace std;
const int INF = 1e7;

int arr[101][101] = { 0 };
int p[101][101] = { 0 };
int c[101][101];
void path(int i, int j) {
    if (p[i][j] == 0)return;
    int mid = p[i][j];
    path(i, mid);
    cout << mid << " ";
    path(mid, j);
}
int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if(i!=j)  arr[i][j] = INF;
          c[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c<arr[a][b])arr[a][b] = c;
    }


    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][t] + arr[t][j] < arr[i][j]) {
                    arr[i][j] = arr[i][t] + arr[t][j];
                    p[i][j] = t;
                    c[i][j] = c[i][t] + c[t][j] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF)cout << "0 ";
            else cout << arr[i][j] << " ";
        }cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j||arr[i][j]==INF) {
                cout << "0\n";
                continue;
            }
            else {
                cout << c[i][j]+2 << " ";
                cout << i << " ";
                path(i, j);
                cout << j << '\n';
            }
        }
    }
}
