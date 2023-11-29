#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int n,m;
int arr[11][11];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int parent[51] ;
int depth[51];
int ar[11][11] = { 0 };
int island = 0; //섬의 개수
int find_node(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find_node(parent[x]);
}

bool union_node(int x, int y) {
	int a = find_node(x);
	int b = find_node(y);
	
	if (a != b) {
		if (depth[a] > depth[b]) {
			parent[b] = a;
		}
		else if (depth[a] < depth[b]) {
			parent[a] = b;
		}
		else {
			parent[b] = a;
			depth[a]++;
		}
		return true;
	}
	return false;
}

void bfs() {

	bool visited[11][11] = { 0 };
	queue<pair<int, int>> que;
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)continue;
			if (visited[i][j] == 1)continue;
			que.push({ i,j });
			//cout << endl;
			ar[i][j] = num;
			visited[i][j] = 1;
			while (!que.empty()) {
				
				int x, y;
				tie(x, y) = que.front();
				que.pop();
				ar[x][y] = num;
				for (int t = 0; t < 4; t++) {
					int nx = x + dx[t];
					int ny = y + dy[t];
					if (nx<0 || ny<0 || nx>n - 1 || ny > m - 1)continue;
					if (visited[nx][ny] == 1)continue;
					visited[nx][ny] = 1;
					if (arr[nx][ny] == 1) {
						que.push({ nx,ny });
					}
				}
			}
			num++;
		}
	}
	island = num-1;
	return;
}
vector<tuple<int, int, int>> vec;
void find_edge() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)continue;
			int x = i; int y = j;
		//	cout << x << " " << y << '\n';
			for (int t = 0; t < 4; t++) {
				int num = 0;
				int nx = x;
				int ny = y;
				while (true) {
					nx += dx[t];
					ny += dy[t];
					if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1)break;
					if (arr[nx][ny] == 1) {
						//printf("x:%d y:%d nx:%d ny:%d\n", x, y, nx, ny);
						if (num < 2)break;
						if (ar[x][y] == ar[nx][ny])break;
						vec.push_back({ num,ar[x][y],ar[nx][ny] });
						break;
					}
					num++;
				}
			}
		}
	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n>>m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	
	bfs();
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}cout << endl;
	}*/
	find_edge();
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		int dist, x, y;
		tie(dist, x, y) = vec[i];
		//printf("dist:%d x:%d y:%d\n", dist, x, y);
	}
	int che_num = 0;
	int ans = 0;

	for (int i = 1; i <= island; i++) {
		parent[i] = i;
	}
//cout << endl;
	for(int i=0;i<vec.size();i++) {
		if (che_num == island-1) {
			cout << ans;
			return 0;
		}
		int dist, x, y;
		tie(dist, x, y) = vec[i];
		bool a=union_node(x, y);
		if (a == true) {
		//	printf("dist:%d x:%d y:%d\n", dist, x, y);
			ans += dist;
			che_num++;
		}
	}
	cout << "-1";
	return 0;
}

