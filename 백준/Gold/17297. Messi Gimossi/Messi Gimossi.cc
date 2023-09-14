#include<bits/stdc++.h>

using namespace std;

int N, M;
int m;
vector<int> vec;
string m1, m2;
void recursion(int n, int m) {
	if (m == 6) {
		cout << "Messi Messi Gimossi";
		return;
	}
	if (m<=vec[1]) {
		cout << m2[m - 1];
		return;
	}
	if (m == vec[n - 1] + 1) {
		cout << "Messi Messi Gimossi";
		 return;
	}
	else if (m > vec[n - 1] + 1) {
	//	printf("a n-2:%d k:%d k-vec[n-1]-1:%d\n", n - 2, k, k-vec[n-1]-1);
		recursion(n - 2, m - vec[n - 1] - 1);
	}
	else if (m < vec[n - 1] + 1) {
		//printf("b n-1:%d k:%d\n", n - 1, k);
		recursion(n - 1, m);
	}
}

int main(void) {
	m1 = "Messi";
	m2 = "Messi Gimossi";
	cin >> m;
	vec.push_back(5);
	vec.push_back(13);
	M = m;

	
	int i = 0;
	int a = 5, b = 13;
	int x = 0;
	while (x<M) {
		x = a + b + 1;   
		a = b;
		b = x;
		vec.push_back(x);
		
	}

	N = vec.size();
	recursion(N, M);
}
