#include<bits/stdc++.h>

using namespace std;

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int arr[201][201];
priority_queue<tuple<int, int, int>,vector<tuple<int,int,int>>,greater<>> pq;

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t; cin >> t;
			arr[i][j] = t;
			if (t != 0) {
				pq.push({ t,i,j });
			}
		}
	}
	int X, Y, s;
	cin >>s>> X >> Y ;
	int time = 0;
	
	for(int I =0;I<s;I++)
	{
		queue<tuple<int, int, int>> que;
		while (!pq.empty()) {
			int t, x, y;
			tie(t, x, y) = pq.top();
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny<0 || nx>n - 1 || ny<0 || ny>n - 1)continue;

				if (arr[nx][ny] == 0) {
					arr[nx][ny] = t;
					que.push({ t,nx,ny });
				}
			}
		}

		while (!que.empty()) {	
			tuple<int, int, int> t = que.front();
			que.pop();
			pq.push(t);
		}
	}

	cout << arr[X - 1][Y - 1];
	
}




