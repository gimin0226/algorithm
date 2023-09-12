#include<bits/stdc++.h>

using namespace std;
vector<int> vec[32001];
int check[32001] = { 0 };
queue<int> que;
int result[32001];

void TopologicalSort() {
	int q = 0;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		result[q] = x; q++;
		for (int i = 0; i < vec[x].size(); i++) {
			if (--check[vec[x][i]] == 0) {
				que.push(vec[x][i]);
			}

		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		check[y]++;
	}
	
	for (int i = 1; i <= n; i++) {
		
		if (check[i] == 0) {
			que.push(i);
		}
	}
	
	TopologicalSort();
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}




