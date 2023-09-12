#include <iostream>
using namespace std;
 
int N, M, ansCnt, ansDir;
char direction[] = { 'U', 'R', 'D', 'L' };
char map[502][502];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool isVoyager;
 
void sendSiganl(int startX, int startY, int startDir) {
    int x = startX, y = startY;
    int cnt = 1; int dir = startDir;
 
    while (1) {
        x = x + dx[dir];
        y = y + dy[dir];
 
        if (x <= 0 || y <= 0 || x > N || y > M || map[x][y] == 'C') {
            if (ansCnt < cnt) {
                ansCnt = cnt;
                ansDir = startDir;
            }
            return;
        
        }
        if (x == startX && y == startY && dir == startDir) {
            ansDir = startDir;
            isVoyager = true;
            return;
        }
 
        if (map[x][y] == '/') dir = 1 ^ dir;
        else if (map[x][y] == '\\') dir = 3 - dir;
 
        cnt++;
    }
}
 
int main() {
    cin >> N >> M;
 
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
        }
    }
    int startX, startY;
    cin >> startX >> startY;
 
    for (int startDir = 0; startDir < 4; startDir++) {
        if (!isVoyager) 
            sendSiganl(startX, startY, startDir);
    }
 
    cout << direction[ansDir] << "\n";
    if (isVoyager) cout << "Voyager";
    else  cout << ansCnt;
}