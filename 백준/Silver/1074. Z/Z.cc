#include<bits/stdc++.h>

using namespace std;


int N, X, Y;
int arr[2][2];
int sum = 0;
void recursion(int n,int x,int y) {
	if (n == 1) {
		if (x == 0 && y == 0)sum += 0;
		else if (x == 0 && y == 1)sum += 1;
		else if (x == 1 && y == 0)sum += 2;
		else if (x == 1 && y == 1)sum += 3;
		return;
	}

	if (x < n && y < n) {
	//	printf("x:%d y:%d N:%d sum:%d\n", x, y, n, sum);
		recursion(n / 2, x, y);
	}
	else if (x < n && y >=n) {
		sum += n * n;
	//	printf("x:%d y:%d N:%d sum:%d\n", x, y, n, sum);
		y -= n;
		recursion(n / 2, x, y);
	}
	else if (x >= n && y < n) {
		sum += 2 * n * n;
	//	printf("x:%d y:%d N:%d sum:%d\n", x, y, n, sum);
		x -= n;
		recursion(n / 2, x, y);
	}
	else if (x >= n && y >= n) {
		sum += 3 * n * n;
	//	printf("x:%d y:%d N:%d sum:%d\n", x, y, n, sum);
		x -= n;
		y -= n;
		recursion(n / 2, x, y);
	}
	
}
int main(void) {
	cin >> N >> X >> Y;
	arr[0][0] = 0; arr[0][1] = 1; arr[1][0] = 2; arr[1][1] = 3;

	recursion(pow(2,N-1), X, Y);
	cout << sum;
}


