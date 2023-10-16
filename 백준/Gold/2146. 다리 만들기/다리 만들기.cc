#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int n;

queue<tuple<int, int, int,int>> qu;

void f() {
    queue<pair<int, int>> que;
    int num = 2;
    int check[101][101] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 || check[i][j] == 1)continue;

            arr[i][j] = num;
            check[i][j] = 1;
            que.push({ i,j });
            while (!que.empty()) {
                int x, y; tie(x, y) = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if ( nx<0 || ny<0 || nx>n - 1 || ny>n - 1|| check[nx][ny] == 1)continue;
                    check[nx][ny] = 1;
                    if (arr[nx][ny] == 1) {
                        que.push({ nx,ny });
                        arr[nx][ny] = num;
                    }
                }

            }
            num++;

        }
    }
}

void f2() {
    int check[101][101] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0)continue;
            qu.push({ i,j,arr[i][j],0});
        }
    }
    int che = 0;
    int arr2[101][101] = { 0 };
    int time = 0;
    int minn = INT_MAX;
    while (!qu.empty()) {
        int t = qu.size();
     
        time++;
        for (int i = 0; i < t; i++) {
           
            int x, y, z,q;
         
            tie(x, y, z,q) = qu.front();
            qu.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x+ dx[j];
                int ny = y + dy[j];
                
                if ( nx<0 || ny<0 || nx>n - 1 || ny>n - 1)continue;
                if (arr[nx][ny] == arr[x][y])continue;

                if (arr[nx][ny] == 0)
                {
                    arr[nx][ny] = arr[x][y];
                    arr2[nx][ny] = q + 1;
                    qu.push({ nx,ny,arr[x][y],q+1});   
                }
                else {
                  //  cout <<x<<" "<<y<<" "<< nx << " " << ny << " " << arr[nx][ny] << endl;
                    minn=min(minn,arr2[nx][ny] + q);
                 
                    che=1;
                }

            }
        }
        if (che == 1) {
            cout << minn;
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
  
    
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    
    f();
    f2();
   /* cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }*/
    return 0;

}

