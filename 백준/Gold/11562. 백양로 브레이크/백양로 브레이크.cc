#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;
vector<pair<int, int>> vec[251];

int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int arr[251][251];
    int ca[251][251];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)ca[i][j] = 0;
            else ca[i][j] = INF;
        }
    }
    
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            arr[a][b] = 1;
            arr[b][a] = 1;
            ca[a][b] = 0;
            ca[b][a] = 0;
        }if (c == 0) {
            arr[a][b] = 1;
            ca[a][b] = 0;
            ca[b][a] = 1;
        }
    }

    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][t] == 1 && arr[t][j] == 1) {
                    ca[i][j] = 0;
                    arr[i][j] = 1;
                }
                else{
                    ca[i][j] = min(ca[i][t] + ca[t][j], ca[i][j]);
                }
            }
        }
    }

 /*   for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ca[i][j] << " ";
        }cout << endl;
    }*/
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << ca[a][b] << "\n";
    }
}