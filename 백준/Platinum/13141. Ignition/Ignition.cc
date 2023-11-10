#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;
int arr[201][201];
int arr2[201][201];
int n;


double f() {
    double ans = INF;
    double t;
    for (int start = 1; start <= n; start++) {
        t = 0;
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (arr2[from][to] != -1) {
                    double x = arr2[from][to] - (arr[start][to] - arr[start][from]);
                    if (x > 0) {
                        double s = x / 2 + arr[start][to];
                        t = max(t, s);
                    }
                }
            }
        }


        ans = min(ans, t);
    }
    return ans;
}
int main() {

    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)arr[i][j] = 0;
            else {
                arr[i][j] = INF;
                arr2[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
     if (arr2[a][b] == -1 || arr2[a][b] < c) {
            arr2[a][b] = c;
            arr2[b][a] = c;
        }
      if (arr[a][b] == INF || arr[a][b] > c) {
            arr[a][b] = c;
            arr[b][a] = c;
        }
    }
    //Floyd
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (arr[i][t] + arr[t][j] < arr[i][j]) {
                    arr[i][j] = arr[i][t] + arr[t][j];
                }
            }
        }
    }

    printf("%.1f\n",f());
    
}