#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int n;
int arr[51][51];
/*
int parent[51] ;
int depth[51];
int find_node(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find_node(parent[x]);
}

void union_node(int x, int y) {
	int a = parent[x];
	int b = parent[y];
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
	}
}
*/

int sum = 0;
int dist[51];
int f() {
	for (int i = 2; i <= n; i++) {
		if (arr[1][i] == 0)dist[i] = INF;
		else dist[i]= min(arr[1][i],arr[i][1]);

	}
	dist[1] = -1;
	int su = 0;
	for(int j=0;j<n-1;j++) {
		int minn = INF;
		int vnear;
		for (int i = 2; i <= n; i++) {
		//	cout << dist[i] << " ";
			if (dist[i] >= 0 && dist[i] < minn) {
				minn = dist[i];
				vnear = i;
			}
		}//cout << endl;

		if (minn == INF) {
			return -1;
		}
		su += minn;
		dist[vnear] = -1;
		for (int i = 2; i <= n; i++) {
			if (i == vnear)continue;
			if (arr[vnear][i] < dist[i])dist[i] = arr[vnear][i];
			if (arr[i][vnear] < dist[i])dist[i] = arr[i][vnear];
		}


	}
	return su;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	
	
	for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
		for(int j=1;j<=n;j++){
			if (str[j - 1] == '0') {
				arr[i][j] = INF;
				continue;
			}
			else if (str[j-1] < 91) arr[i][j] = str[j-1] - 'A' + 27;
			else arr[i][j] = str[j-1]-'a'+1;
			sum += arr[i][j];
		}
	}
	
	int t = f();
	if (t == -1)cout << t;
	else cout << sum - t;
	
	
}

