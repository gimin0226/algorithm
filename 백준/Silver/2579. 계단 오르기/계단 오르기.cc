#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long x[301];  //연속 o
    long long o[301];  //연속 x

    int N;
    cin >> N;
    int arr[301];
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    o[0] = 0, x[0] = 0;
    o[1] = arr[1]; x[1] = arr[1];

    for (int i = 2; i <= N; i++) {
        o[i] = arr[i]+x[i - 1];
        x[i] = arr[i] + max(o[i - 2], x[i - 2]);
    }
    cout << max(o[N], x[N]);
}
