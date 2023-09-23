#include<bits/stdc++.h>

using namespace std;

int check[5001] = { 0 };	
int N;
deque<int> dq;
void f(int n,int t) {
	if (t == 0) {
		while (!dq.empty()) {
			cout << dq.front() << " ";
			dq.pop_front();
		}
		exit(0);

	}
	if (n - t > 0 && check[n - t] == 0) {
		check[n - t] = 1;
		dq.push_back(n - t);
		f(n - t, t - 1);
		check[n - t] = 0;
		dq.pop_back();
	}
	if (n + t <= N&&check[n+t]==0) {
		check[n + t] = 1;
		dq.push_back(n + t);
		f(n + t, t - 1);
		check[n - t] = 0;
		dq.pop_back();
	}
	return ;
}
int main(void) {

	
	cin >> N;


	for (int i = N; i > 0; i--) {
		check[i] = 1;
		dq.push_back(i);
		f(i,N-1);
		check[i] = 0;
		dq.pop_back();
	}

}