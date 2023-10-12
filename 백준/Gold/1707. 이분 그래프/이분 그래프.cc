#include <bits/stdc++.h>
using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int z = 0; z < N; z++) {
		vector<int> vec[20001];
		int arr[20001];
		int check[20001] = { 0 };
		int p, q;
		cin >> p >> q;
		int x, y;
		for (int i = 0; i < q; i++) {
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		
		queue<int> que;
		int stop2 = 0;
        for (int i = 1; i <= p; i++) {
            if (check[i] == 1) continue;

            que.push(i);
            arr[i] = 0;  // 첫 노드의 색을 0으로 설정
            check[i] = 1;

            int stop = 0;
            while (!que.empty()) {
                int curr = que.front();
                que.pop();
                int a = 1 - arr[curr];  // 현재 노드와 다른 색을 a로 설정

                for (int next : vec[curr]) {
                    if (check[next] == 0) {
                        check[next] = 1;
                        arr[next] = a;
                        que.push(next);
                    }
                    else if (arr[next] == arr[curr]) {
                        stop = 1;
                        break;
                    }
                }

                if (stop == 1) break;
            }

            if (stop == 1) {
                stop2 = 1;
                cout << "NO" << '\n';
                break;
            }
        }
		if (stop2 == 0)cout << "YES" << '\n';

	}
}