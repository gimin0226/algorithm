#include<bits/stdc++.h>

using namespace std;

long long lower_bound(const vector<long long>& arr, long long x) {
	long long left = 0; long long right = arr.size() - 1;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

//	printf("x:%d left:%d arr[left]:%d\n", x, left, arr[left]);
	if (left<arr.size()&&arr[left] == x)return left;
	else {
		return -1;
	}
}

long long upper_bound(const vector<long long>& arr, long long x) {
	long long left = 0; long long right = arr.size() - 1;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (arr[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	//printf("x:%d right:%d arr[right]:%d\n", x,left-1, arr[left-1]);
	if(left-1>=0&&arr[left-1]==x)return left;
	else {

		return -1;
	}
}
int main(void) {

	int t;
	cin >> t;
	int a_n, b_n;
	cin >> a_n;
	int a[1001];
	int b[1001];
	for (int i = 0; i < a_n; i++) {
		cin >> a[i];
	}
	cin >> b_n;
	for (int i = 0; i < b_n; i++) {
		cin >> b[i];
	}

	vector<long long> vec1;
	vector<long long> vec2;

	for (int i =1; i <= a_n; i++) {
		long long sum = 0;
		for (int j = 0; j < i; j++) {
			sum += a[j];
		}
		vec1.push_back(sum);
		for (int j = 0; j < a_n-i; j++) {
			sum -= a[j];
			sum += a[j+i];
			vec1.push_back(sum);
			//printf("i:%d j:%d j+i:%d sum:%d\n", i, j, i + j, sum);
		}
	}
	

	for (int i = 1; i <= b_n; i++) {
		long long sum = 0;
		for (int j = 0; j < i; j++) {
			sum += b[j];
		}
		vec2.push_back(sum);
		for (int j = 0; j < b_n - i; j++) {
			sum -= b[j];
			sum += b[j + i];
			vec2.push_back(sum);
		}
	}


	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	long long num = 0;
	for (int i = 0; i< vec1.size(); i++) {
		int x = vec1[i];
		
		num += upper_bound(vec2, t-x) - lower_bound(vec2, t-x) ;
	}

	cout << num;
}