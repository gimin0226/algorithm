#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec[11];
int sum = 0;
bool check[11] = { false };
int maxx = 0;
void BackTracking(int n) {
	//cout << n << endl;
	if (n == 10) {
		for (int i = 0; i < vec[n].size(); i++) {
			if (check[vec[n][i].second] == false) {
				sum += vec[n][i].first;
				maxx = max(maxx, sum);
				sum -= vec[n][i].first;
			}
		}
		return;
	}
	for (int i = 0; i < vec[n].size(); i++) {
		
		if (check[vec[n][i].second] == false)
		{
			sum += vec[n][i].first;
			check[vec[n][i].second] = true;
			BackTracking(n + 1);
			sum -= vec[n][i].first;
			check[vec[n][i].second] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		maxx = 0;
		sum = 0;
		int arr[11][11];
		
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				int t;
				cin >> t;
				arr[i][j] = t;
				if (t > 0) {
					vec[i].push_back({ t,j });
				}
			}
		}

		BackTracking(0);

		for (int i = 0; i <11; i++) {
			check[i] = false;
			vec[i].clear();
		}
		cout << maxx<<endl;
		
	}
	

}
