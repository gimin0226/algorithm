#include<bits/stdc++.h>

using namespace std;
vector<int> vec;
struct tuple_hash {
    template <class T1, class T2, class T3>
    std::size_t operator() (const std::tuple<T1, T2, T3>& t) const {
        auto h1 = std::hash<T1>{}(std::get<0>(t));
        auto h2 = std::hash<T2>{}(std::get<1>(t));
        auto h3 = std::hash<T3>{}(std::get<2>(t));
        return h1 ^ h2 ^ h3;
    }
};

unordered_map<tuple<int, int, int>, bool, tuple_hash> um;
int siz[3];

void recursion(int a, int b, int c) {
    if (um.find({ a, b, c }) != um.end()) return;
    if (a == 0) vec.push_back(c);
    um[{a, b, c}] = true;

    int water[]{ a, b, c };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            int arr[3] = { a, b, c };
            if (water[i] + water[j] <= siz[j]) {
                arr[j] += arr[i];
                arr[i] = 0;
            }
            else {
                arr[i] -= (siz[j] - arr[j]);
                arr[j] = siz[j];
            }
            recursion(arr[0], arr[1], arr[2]);
        }
    }
}

int main(void) {
    for (int i = 0; i < 3; i++) cin >> siz[i];
    recursion(0, 0, siz[2]);
    sort(vec.begin(), vec.end());
    for (int i : vec) {
        cout << i << " ";
    }
}
