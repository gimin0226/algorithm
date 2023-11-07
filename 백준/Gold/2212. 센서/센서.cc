#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end());
   
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        int t = vec[i + 1] - vec[i];
        if (t == 0)continue;
        v.push_back(t);
    }
  
    int x = v.size();
    x = x - k + 1;
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += v[i];
    }
    cout << sum;
    return 0;
}