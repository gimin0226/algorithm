#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;

int check_num;
bool che[31][31];
char arr[31][31];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int minn;
int n, m;

void backTracking(int num,int x,int y) {
	//printf("x:%d y:%d num:%d check_num:%d\n", x, y, num,check_num);
	if (check_num == 0) {
		minn = min(minn, num );
		//	cout << num << "끝\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx=x, ny=y;
		vector<pair<int, int>> vec;
		int num2 = 0;
		while (true) {
			nx += dx[i]; ny += dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny > m - 1)break;
			if (arr[nx][ny] == '*'||che[nx][ny]==1)break;
			vec.push_back({ nx,ny });
			che[nx][ny] = 1;
			check_num--;
			num2++;
			if (check_num == 0) {
				minn = min(minn, num+1);
			//	cout << num << "끝\n";
				for (int j = 0; j < vec.size(); j++) {
					che[vec[j].first][vec[j].second] = 0;
				}
				check_num += num2;
				return;
			}
		}
		nx -= dx[i]; ny -= dy[i];
		if (nx == x && ny == y) {
		//	cout << "벽\n";
			continue;
		}
		backTracking(num + 1, nx, ny);
		for (int j = 0; j < vec.size(); j++) {
			che[vec[j].first][vec[j].second] = 0;
		}
		check_num += num2;
	}
	//cout << "리턴\n";
}

int main() {
	int k = 1;
	while (true) {
		
		vector<pair<int, int>> v;
		
		cin >> n >> m;
		if (cin.eof())break;
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				che[i][j] = 0;
			}
		}
		check_num = 0;
		minn = INF;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '.') {
					v.push_back({ i,j });
					check_num++;
				}
			}
		}
		int t = check_num-1;
		for (int i = 0; i < v.size(); i++) {
		//	cout << "시작\n";
			check_num = t;
			che[v[i].first][v[i].second] = 1;
			backTracking(0,v[i].first,v[i].second);
			che[v[i].first][v[i].second] = 0;
		}
		if(minn==INF) cout << "Case " << k << ": " << -1 << endl;
		else cout << "Case " << k<<": "<< minn << endl;
		k++;
	}
}