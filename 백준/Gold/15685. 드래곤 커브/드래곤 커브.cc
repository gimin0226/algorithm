#include<bits/stdc++.h>

using namespace std;
int n;
int arr[101][101] = { 0 };
int dx[]{ 0,-1,0,1 };
int dy[]{ 1,0,-1,0 };
void make(int x,int y,int d,int r) {
	if (r == 0) {
		arr[x][y] += 1;
		x += dx[d]; y += dy[d];
		arr[x][y] += 1;
		return;
	}
	int k = d;
	deque<int> dq;
	deque<int> dq2;
	deque<int> dq3;
	arr[x][y] +=1;
	x = x + dx[d];
	y = y + dy[d];
	d = (d + 1) % 4;
	arr[x][y] += 1;
	x = x + dx[d];
	y = y + dy[d];
	arr[x][y] += 1;
	dq.push_back(d );
	
	for (int i = 0; i < r-1; i++) {
		int t = dq.size();	
		for (int j = 0; j < t; j++) {
			int p = dq.back(); dq.pop_back();
			dq2.push_front(p);
			p = (p + 1) % 4;
			dq3.push_back(p);
			x += dx[p];
			y += dy[p];
			arr[x][y] += 1;
		}
		t = dq3.size();
		for (int j = 0; j < t; j++) {
			int p = dq3.front();
			dq.push_back(p);
			dq3.pop_front();
		}
		t = dq2.size();
		for (int j = 0; j < t; j++) {
			int p = dq2.front();
			x += dx[p]; y += dy[p];
			arr[x][y] += 1;
			dq.push_back(p);
			dq2.pop_front();
		}
	}
}
int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, r;
		cin >> x>> y >> d >> r;
		make(y,x, d, r);
	}
	int num = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!arr[i][j] || !arr[i + 1][j] || !arr[i][j + 1] || !arr[i + 1][j + 1])continue;
			num++;
		}
	}
	cout << num;
}