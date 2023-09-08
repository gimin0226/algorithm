#include <bits/stdc++.h>

using namespace std;

int dx[]{ -1,0,+1,0 }; //북  0 남 0
int dy[]{ 0,1,0,-1};  //0  동 0 서

// 0 북쪽, 1 동쪽, 2 남쪽, 3 서쪽

int arr[51][51];

int main(void) {
	int n,m;
	cin >> n >> m;

	int x, y, direct;

    cin >> x >> y >> direct;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            arr[i][j] = t;
        }
    }
    int num = 1;
    arr[x][y] = -1;
    while (true) {
        
        
        bool check = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1)continue;
            if (arr[nx][ny] == 0) {
                check = true;
                break;
            }
        }

        if (check == true) {
            //반시계 회전 
            // 북(0)->서(3) 서(3)->남(2) 남(2) -> 동(1) 동(1) -> 북(0)
            direct = direct - 1 >= 0 ? (direct - 1) : 3;
            int nx = x + dx[direct];
            int ny = y + dy[direct];
            if (arr[nx][ny] == 0) {
                arr[nx][ny] = -1;
                x = nx; y = ny;
                num++;
            }
        }
        else if (check == false) {
            int nx = x - dx[direct];
            int ny = y - dy[direct];
            if (arr[nx][ny] == 1) {
                cout << num;
                return 0;
            }
            else if (arr[nx][ny] == 0) {
                arr[nx][ny] = -1;
                x = nx; y = ny;
                num++;
            }
            else if (arr[nx][ny] == -1) {
                x = nx; y = ny;
            }
        }
    }

}