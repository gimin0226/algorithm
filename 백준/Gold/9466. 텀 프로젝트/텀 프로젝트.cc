#include <bits/stdc++.h>
using namespace std;

bool done[100001] = { 0 };
bool visited[100001] = { 0 };
int arr[100001];
int num;
int che = 0;
int dfs(int x) {
   // cout << x << " ";
    if (done[x])return 0;
    if (visited[x] == 1)return x;
    visited[x] = 1;
    if (arr[x] == x) {
        num -= 1;
        return x;
    }
    int t= dfs(arr[x]);
    done[x] = 1;
    if (t == x) {
   //     cout <<"asfsd"<< t << " " << che << endl;
        num -= che+1;
    }
    else {
        che++;
    }
    return t;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        num = n;
        memset(done, 0, sizeof(done));
        memset(visited, 0, sizeof(visited));

        for (int i = 1; i<= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (done[i])continue;
            dfs(i);
            che = 0;
        //    cout << endl;
        }
        cout << num<<'\n';
    }

    return 0;
}