#include<bits/stdc++.h>

using namespace std;

//a(n+1) = a(n)*2+3
//a(n+1)+3=2*(a(n)+3)
//a(n)=8*2^(n-1)-3=2^(n+2)-3
//a(50)= 4,503,599,627,370,493
long long len[51];
long long num[51];
long long N,X;
long long sum = 0;
string str = "BPPPB";

void recursion(long long x,int n) {
	if (n == 1) {
		for (int i = 0; i < x; i++) {
			if (str[i] == 'P') {
				sum += 1;
			}
		}
		return;
	}
	if (x == len[n - 1]+1) {
		sum += num[n - 1];
		return;
	}
	else if (x == len[n - 1] + 2) {
		sum += num[n - 1] + 1;
		return;
	}
	else if (x > len[n-1]+2) {
		sum += num[n - 1]+1;
		x -= len[n - 1] + 2;
		recursion(x, n - 1);
	}
	else if (x < len[n-1]+2) {
	//	cout << "fsda"<<endl;
		recursion(x-1, n - 1);

	}
	
}
int main(void)	{

	cin >> N>>X;
	len[1] = 5;
	num[1] = 3;
	for (int i = 2; i <= N; i++) {
		len[i] = len[i - 1] * 2 + 3;
		num[i] = num[i - 1] * 2 + 1;
	}
	
	recursion(X,N);
	cout << sum;
}