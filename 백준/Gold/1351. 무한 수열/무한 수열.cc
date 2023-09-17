#include<bits/stdc++.h>

using namespace std;


long long N,P,Q;
unordered_map<long long, long long> hm;

long long recursion(long long n) {
	if (hm.find(n) == hm.end()) {
		long long x = recursion(n / P);
		long long y = recursion(n / Q);
		hm[n] = x + y;
		return x + y;
	}
	else {
		return hm[n];
	}
	
}
int main(void) {
	cin >> N >> P >> Q;

	hm[(long long)0] = (long long)1;
	recursion(N);
	cout << hm[N];
}
