#include<bits/stdc++.h>

using namespace std;
const int INF = 1e8;
vector<int> v[5];

int f2(int maxx,int gap,int idx) {
	if (idx == 1||idx==2) return v[idx][maxx] - gap;
	else return v[idx][maxx] + gap;
}

int f(int x, int y) {
	int maxx = max(abs(x), abs(y));
	int t;
	if (maxx == -x) {
		t=f2(maxx, y, 2);
	}
	else if (maxx == -y) {
		t=f2(maxx, x, 3);
	}
	else if (maxx == x) {
		t=f2(maxx, y, 4);
	}
	else if (maxx == y) {
		t=f2(maxx, x, 1);
	}
	return t;
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
//	ios::sync_with_stdio(false);
	
	for (int i = 1; i < 5; i++)v[i].push_back({ 1});

	for (int i = 1; i < 5; i++) {
		int sum = 1;
		for (int j = 1; j < 5001; j++) {
			int t = v[i][j-1] + (2 * i - 1) + 8 * (j - 1);
			v[i].push_back(t);
		}
	}

	int arr[50][5];
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int I = 0, J = 0;
	int len = 0;
	for (int i = x1; i <= x2; i++) {
		J = 0;
		for (int j = y1; j <= y2; j++) {
				int p= f(i, j); 
				arr[I][J] = p;
			int t = to_string(arr[I][J]).length();
				J++;
			len = max(t, len);
		}//cout << endl;
		I++;
	}

	for (int i = 0; i < x2-x1 + 1; i++) {
		for (int j = 0; j < y2 - y1 + 1; j++) {
			printf("%*d ", len,arr[i][j]);
		}cout << '\n';
	}
	
}

