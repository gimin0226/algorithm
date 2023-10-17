#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    int dp[201];
    fill(dp, dp + 201, 1);

    dp[0] = 1;
   
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[j] < vec[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
      }
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, dp[i]);
    }
    
    cout << n - maxx;
    return 0;
}