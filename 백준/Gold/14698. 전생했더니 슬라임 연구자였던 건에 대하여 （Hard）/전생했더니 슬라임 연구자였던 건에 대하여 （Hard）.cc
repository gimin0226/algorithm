#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        int n;
        cin >> n;
        
        long long t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            pq.push(t);
        }

        if (n == 1) {
            cout << "1"<<'\n';
            continue;
        }
        long long sum = 1;
        while (true) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            long long t = (x *y );
           // sum = sum * t;
          //  cout << t << endl;
            sum = ((sum % 1000000007) * (t % 1000000007)) % 1000000007;
         //   cout << t << endl;
            if (pq.empty()) {
                cout << sum % 1000000007 << '\n';
                break;
            }
            pq.push(t);
        }
    }
    return 0;
}