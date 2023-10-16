#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int arr[51][51];
int x[2], y[2];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

void f() {
    int arr2[51][51] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0||arr[i][j] < 5||arr[i][j]==-1) {
                arr2[i][j] += arr[i][j];
                continue;
            }

            int k = arr[i][j] / 5;
            int che = 0;
            for (int t = 0; t < 4; t++) {
                int x = i + dx[t];
                int y = j + dy[t];
                if (x<0 || y<0 || x>N - 1 || y>M - 1||arr[x][y]==-1)continue;
                arr2[x][y] += k;
                che++;
            }
            arr2[i][j] += arr[i][j] - k * che;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = arr2[i][j];
     
        }
    }
}

void f2() {

    for (int c= 0; c < 2; c++) {
        int A = x[c];
        int a = x[c]; int b = y[c]+1;

        int t=arr[a][b];
        arr[a][b] = 0;
        
        for (int i = 2; i < M; i++) swap(t, arr[a][++b]);
      //  cout << a << " " << b << endl;
        if (c == 0)  for (int i = 0; i < A; i++) swap(t, arr[--a][b]);
        else if (c == 1)for (int i = 0; i < N - A-1; i++)swap(t, arr[++a][b]);
      //  cout << a << " " << b << endl;
    
        for (int i = 1; i < M; i++)swap(t, arr[a][--b]);
      //  cout << a << " " << b << endl;

        if (c == 0)for (int i = 0; i < A-1; i++)swap(t, arr[++a][b]);
        else if (c == 1)for (int i = 0; i < N - A-2; i++)swap(t, arr[--a][b]);
    //    cout << a << " " << b << endl;
/*
        cout << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << arr[i][j] << " ";
            }cout << endl;
        }*/
    }
   
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    cin >> N >> M >> T;
    
    int che = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                x[che] = i; y[che] = j;
                che++;
            }
        }
    }
    for (int i = 0; i < T; i++) {
        f();
        f2();
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0)continue;
            sum += arr[i][j];
        }
    }
    cout << sum + 2;
    return 0;
}

