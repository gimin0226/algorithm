#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long zero[91];
    long long one[91];
    int N;
    cin >> N;

    zero[1] = 1;
    zero[2] = 2;
    one[1] = 1;
    one[2] = 1;
    for (int i = 3; i <= N; i++) {
        zero[i] = zero[i - 1] + one[i - 1];
        one[i] = zero[i - 1];
    }
    cout << one[N];
}
