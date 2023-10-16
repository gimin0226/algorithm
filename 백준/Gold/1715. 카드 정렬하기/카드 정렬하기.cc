#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
  
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<>> pq;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.push(t);
    }
    int sum = 0;
    if (n == 1) {
        cout << 0;
        return 0;
   }
    while (pq.size()>=2) {
        int x = pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        sum += x + y;
        pq.push(x + y);

    }

    cout << sum;
    
    return 0;
}

