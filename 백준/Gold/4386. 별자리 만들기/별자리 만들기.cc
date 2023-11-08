#include<bits/stdc++.h>

using namespace std;
const double INF = 1e7;
double dist[101];
double d[101][101];
pair<double, double> arr[101];
bool visited[101] = { 0 };
double sum = 0;
double prim(int n) {
    
    int x = 1;
    for (int i = 1; i <= n; i++)dist[i] = d[1][i];
    visited[1] = 1;
    
    for (int i = 0; i < n - 1; i++) {
        double minn = INF;
        int vnear;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0 && dist[j] < minn) {
                minn = dist[j];
                vnear = j;
            }
        }
        //cout << vnear << endl;
        visited[vnear] = 1;
        sum += minn;

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && d[vnear][i] < dist[i]) {
                dist[i] = d[vnear][i];
            }
        }
    }
    return sum;
}
int main() {
    
    int n;
    cin >> n;
  

    for (int i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        arr[i] = { a,b };
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)d[i][j] = 0;
            else {
                double x1, y1; 
                x1 = arr[i].first; y1 = arr[i].second;
                double x2, y2;
                x2 = arr[j].first; y2 = arr[j].second;

                d[i][j] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            }
        }
    }

  /*  for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.2f ", d[i][j]);
        }cout << endl;
    }*/
    printf("%.2f",prim(n));

    return 0;
}