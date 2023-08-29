#include <iostream>
#include <algorithm>


using namespace std;

int main(){

    int n;
    int arr[1001];
    int dp[1001];
    int ans=0;

    cin >> n;
    for(int i=0;i<n;i++){
	cin >> arr[i];
    }

    for(int i=0;i<n;i++){
	dp[i] = 1;
	for(int j=0;j<i;j++){
	    if(arr[i] < arr[j]){
		dp[i] = max(dp[i],dp[j]+1);
	    }
	}
	ans = max(ans,dp[i]);
    }

    cout << ans << endl;

    return 0;
}