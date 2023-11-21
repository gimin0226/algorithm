#include<bits/stdc++.h>

using namespace std;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		int n, m;
		cin >> n >> m;
		int arr[31][31];
		for (int i = 1; i <= m; i++) {
			arr[1][i] = i;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= m-n+i; j++) {
				arr[i][j] = 0;
				for (int k = i-1; k <= j - 1; k++)
				{
					arr[i][j] += arr[i - 1][k];
				}
			}
		}
		
		cout << arr[n][m] << endl;
	}

}