#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;

typedef struct node {
    int x;
    int y;
    int cost;

    node(int x, int y, int cost) {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }

    bool operator<(node& node) {
        return this->cost < node.cost;
    }
}node;
int parent[100001];
int depth[100001];
    
int n;
int maxx = 0;
int sum = 0;
int find_parent(int x) {
    if (parent[x] == x)return parent[x];
    else return parent[x]=find_parent(parent[x]);
}

bool union_parent(int x, int y) {
    int a= find_parent(x);
    int b = find_parent(y);
   // cout << a << " " << b << endl;
    if (a != b) {
        if (depth[a] == depth[b]) {
            parent[b] = a;
            depth[a]++;
        }
        else if (depth[a] > depth[b]) {
            parent[b] = a;
        }
        else {
            parent[a] = b;
        }
        return true;
    }
    else return false;

}
int main() {
    int m;
    cin >> n>> m; vector<node> v;
    for (int i = 1; i <= n; i++)parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(node(a, b, c));
    }

    sort(v.begin(), v.end());
   
    for (int i = 0; i < m; i++) {
        if (union_parent(v[i].x, v[i].y)) {
          //  cout << v[i].x << " " << v[i].y << " " << v[i].cost << endl;
            sum += v[i].cost;
            maxx = max(maxx, v[i].cost);
        }
    }
    cout << sum - maxx;
}