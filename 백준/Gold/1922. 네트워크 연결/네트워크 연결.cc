#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int F = 0;
int nearest[1001];
int dist[1001];
vector<pair<int,int>> vec[10001];
int visited[1001] = { 0 };

priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> pq;


int sum = 0;
int num;
void prim(int n) {
	for (int i = 0; i < vec[1].size(); i++) {
		int x, y; tie(x, y) = vec[1][i];
		pq.push({ y,x });
	}
	visited[1] = 1;
	num = n-1;
	while (num>0) {
		int x, y;
		tie(x, y) = pq.top();
		pq.pop();
		if (visited[y] == 1)continue;
		//cout << x <<" "<< y << " "<<num<<endl;
		sum += x;
		visited[y] = 1;
		num--;
		for (int i = 0; i < vec[y].size(); i++) {
			int a,b; tie(a,b) = vec[y][i];
			if (visited[a] == 1)continue;
			pq.push({ b,a });
		}
	}


	
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}

	prim(n);
	cout << sum;

}