
#include<bits/stdc++.h>
using namespace std;
int dx[]{ -1,0,0,1 };
int dy[]{ 0,-1,1,0 };
int arr[21][21];
int x, y, sizee;
int ti = 0;
int che = 0;
int n;
int lev;
void bfs() {
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> que;
	que.push({0, x,y });
	
	int	check[21][21] = { 0 };
	check[x][y] = 1;

	int timee = 0;
	while (true) {


		if (que.empty()) {
			che++;
			//	ti += timee + 1;
			return;
		}
		int a, b, tim;
		tie(tim,a, b) = que.top();
		//cout << a << " " << b << "qwer\n";
		que.pop();
		if (arr[a][b]!=0&&arr[a][b] < sizee) {
			lev--;
			arr[a][b] = 0;
			x = a;
			y = b;
			ti += tim ;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)continue;
			if (check[nx][ny] == 1)continue;
			check[nx][ny] = 1;
			
			if (arr[nx][ny] <= sizee || arr[nx][ny] == 0) {
				if (a == 0 && b == 2) {
			//		cout <<tim+1<<" " << nx << " " << ny << endl;
				}
				que.push({ tim + 1 , nx,ny});
			}
			


		}

	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	sizee = 2;
	lev = sizee;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				x = i, y = j;
				arr[x][y] = 0;
			}
		}
	}

	while (true) {
	//	printf("x:%d y:%d sizee:%d time:%d\n", x, y, sizee, ti);
	/*	cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}cout << endl;
		}cout << endl;*/
		bfs();
		if (lev == 0) {
		//	cout << "fsdafasd";
			sizee++;
			lev = sizee;
		}
		if (che == 1) {
			break;
		}
	}
	cout << ti;

}