#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX-1;



int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	dp[0] = 0;
	for (int i = 1; i <=k; i++) { 
		dp[i] = INF;
		for (int j = 0; j <arr.size(); j++) {
			if (i - arr[j] >= 0)
				dp[i] = min(dp[i - arr[j]]+1, dp[i]);
		}
	}
	//for (int i = 0; i <= k; i++)cout << dp[i] << " ";
	if (dp[k] == INF)cout << -1;
	else cout << dp[k] << endl;
	return 0;
}