#include <bits/stdc++.h>
using namespace std;
int n, l;
int arr[101][101];

int visited[101][101] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> l ;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
   
    for (int i = 0; i < n; i++) {
        int x = arr[i][0];
        for (int j = 0; j < n-1; j++) {
           
            x = arr[i][j];
            if (x - arr[i][j + 1] > 1) break;
            else if (x - arr[i][j + 1] == 1) {
                if (i == 3) {
              //      cout << "qwe ";
                }
                int che = 0;
                for (int t = 0; t < l; t++) {

                    if (visited[i][j + 1 + t] == 1 || arr[i][j + 1 + t] != x - 1) {
                        che++;
                        break;
                    }
                    visited[i][j + 1 + t] = 1;
                }
                if (che == 1)break;
            }
            else if (arr[i][j + 1] - x > 1)break;
            else if (arr[i][j + 1] - x == 1) {
               
                int che = 0;
                for (int t = 0; t < l; t++) {

                    if (visited[i][j- t] == 1 || arr[i][j- t] != x) {
                        che++;
                        break;
                    }
                    visited[i][j -t] = 1;
                }
                if (che == 1)break;
            }

            if (j == n - 2) {
             /*   cout << endl;
                for (int t = 0; t < n; t++) {
                    cout << arr[i][t] << " ";
                }cout << endl;
                cout << endl;*/
                ans++;
            }
            
            
        }
   }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int x = arr[0][i];
        for (int j = 0; j < n - 1; j++) {

            x = arr[j][i];
            if (x - arr[j+1][i] > 1) break;
            else if (x - arr[j+1][i] == 1) {
                if (i == 3) {
              //      cout << "qwe ";
                }
                int che = 0;
                for (int t = 0; t < l; t++) {

                    if (visited[j + 1 + t][i] == 1 || arr[j + 1 + t][i] != x - 1) {
                        che++;
                        break;
                    }
                    visited[j + 1 + t][i] = 1;
                }
                if (che == 1)break;
            }
            else if (arr[j+1][i] - x > 1)break;
            else if (arr[j+1][i] - x == 1) {

                int che = 0;
                for (int t = 0; t < l; t++) {

                    if (visited[j-t][i] == 1 || arr[j-t][i] != x) {
                        che++;
                        break;
                    }
                    visited[j-t][i] = 1;
                }
                if (che == 1)break;
            }

            if (j == n - 2) {
               /* cout << endl;
                for (int t = 0; t < n; t++) {
                    cout << arr[t][i] << " ";
                }cout << endl;
                cout << endl;*/
                ans++;
            }


        }
    }
    cout << ans;
}