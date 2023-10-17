#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[51][51];
vector<tuple<int, int, int>> vec;
int check[7] = { 0 };
int minn = INT_MAX;
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
void turn(int x, int y, int z) {
    int x_s = x - z - 1;
    int y_s = y - z - 1;
    int x_e = x + z - 1;
    int y_e = y + z - 1;
  //  printf("x_s:%d y_s:%d x_e:%d y_e:%d\n", x_s, y_s, x_e, y_e);
   
    while (true) {
        if (x_s == x_e || y_s == y_e)break;
        if (x_e - x_s == 1 ) {
            int v = arr[x_s][y_s];
            int a = x_s, b = y_s;
            while (true) {
                a += 1;
                swap(v, arr[a][b]);
                if (a == x_e) {
                    arr[x_s][y_s] = v;
                    break;
                }
            }
        }
        else if (y_e - y_s == 1) {
            int v = arr[x_s][y_s];
            int a = x_s, b = y_s;
            while (true) {
                b += 1;
                swap(v, arr[a][b]);
                if (b == y_e) {
                    arr[x_s][y_s] = v;
                    break;
                }
            }
        }
        int v = arr[x_s][y_s];
        int di= 0;
        int a = x_s, b = y_s;
        while (true) {
          //  cout << "a:" << a << " b:" << b << endl;
            if (a + dx[di] == x_s && b+ dy[di] == y_s) {
                a += dx[di]; b += dy[di];
                swap(v, arr[a][b]);
                break;
            }
            if (a + dx[di]<x_s || a + dx[di]>x_e || b + dy[di]<y_s || b + dy[di]>y_e) {
                di++;
            }
         
            a = a + dx[di]; b = b + dy[di];
            swap(v, arr[a][b]);

        }
        x_s += 1; x_e -= 1; y_s += 1; y_e -= 1;
    //    cout << endl;
       /* for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }cout << endl;
        }cout << endl;*/
    }/*
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;
    */
}

void f(int ti) {
    if (ti == k) {
      
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += arr[i][j];
            }
         //   cout << sum << endl;
            minn = min(sum, minn);
        }
        return;
    }
    for (int i = 0; i < vec.size(); i++) {
        if (check[i] == 1)continue;

        int x, y, z;  tie(x, y, z) = vec[i];
        int arr2[51][51];
        for (int t = 0; t < n; t++) {
            for (int j = 0; j < m; j++) {
                arr2[t][j] = arr[t][j];
            }
        }
        check[i] = 1;
        turn(x, y, z);
        f(ti + 1);
        check[i] = 0;
        for (int t = 0; t < n; t++) {
            for (int j = 0; j < m; j++) {
                arr[t][j] = arr2[t][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec.push_back({ x,y,z });
    }
    
    f(0);
    cout << minn<<'\n';
    return 0;
}