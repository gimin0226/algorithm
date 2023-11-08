#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;
vector<pair<int, int>> vec[251];

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(),cmp);
    int m;
    cin >> m;
    deque<int> dq;
    vector<int> v2;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v2.begin(), v2.end(), cmp);
    for (int i = 0; i < v2.size(); i++) {
        dq.push_back(v2[i]);
    }

    if (v2[0] > v[0]) {
        cout << "-1";
        return 0;
    }
    int idx = 0;
    int num = 0;
    while (!dq.empty()) {
        int t = dq.size();
        idx = 0;
        num++;
        for (int i = 0; i < t; i++) {
            if (idx >= n) {
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
                continue;
            }
            int x = dq.front();
          //  cout << x << " ";
            dq.pop_front();
            if (x <= v[idx]) {
              
                idx++;
            }
            else {
          
                dq.push_back(x);
            }
        }
    //   cout << endl;
    }
    cout << num;
}