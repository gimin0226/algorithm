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
    int dp[1001];
    fill(dp, dp + 201, 1);
    int dp2[1001];
    fill(dp2, dp2 + 1001, -1);
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[j] < vec[i]) {  
                if (dp[j] + 1 > dp[i]) {
                    dp2[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
      }
    }
    int maxx = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
      
        if (maxx < dp[i]) {
            maxx = dp[i];
            k = i;
        }
    }
    stack<int> sta;
   // cout << k << " " << vec[k] << " " << dp2[k] << endl;
    sta.push(vec[k]);
    
    while (true) {
        int t = dp2[k];
        if (t == -1) {
            break;
        }
        sta.push(vec[t]);
        k = t;
    }
  /* for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }cout << endl;
    */
    cout << maxx<<endl;
    while (!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    return 0;
}