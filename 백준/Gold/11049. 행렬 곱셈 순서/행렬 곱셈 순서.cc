#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int d[502];

int minmult(int n) {
    long long M[501][501];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            M[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)M[i][i] = 0;

    for (int t = 1; t < n; t++) {
        for (int i = 1; i <= n - t; i++) {
            int p = i + t;
            for (int j = i; j < p; j++) {
                if (M[i][j] + M[j + 1][p] + d[i - 1] * d[j] * d[p] < M[i][p]) {
                    M[i][p] = M[i][j] + M[j + 1][p] + d[i - 1] * d[j] * d[p];
                }
            }
        }
    }

    return M[1][n];
}

int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0)d[0] = a;
        else d[i] = a;
        if (i == n - 1)d[i + 1] = b;
    }
    cout << minmult(n);


    return 0;
}