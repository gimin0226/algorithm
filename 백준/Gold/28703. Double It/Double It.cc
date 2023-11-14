#include<bits/stdc++.h>
using namespace std;
const int INF = 1e10;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v;
    long long maxx2 = 0;
    long long maxx = 0; long long minn = INF;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        maxx = max(maxx, t);
        v.push_back(t);
        pq.push(t);
    }
    maxx2 = maxx;
    while (true) {
        long long x = pq.top();
        if (x > maxx2)break;
        pq.pop();
        minn = min(maxx - x, minn);
      //  cout << x << " " << maxx << " " << maxx - x <<" " <<minn<< endl;
       
        if ((long long)x * 2 > maxx)maxx = x * 2;
        
        pq.push(x * 2);

    }
    cout << minn;
}