#include<bits/stdc++.h>
using namespace std;
int t = 0;
int arr1[1001];
int arr2[1001];
int n;
void f(int start,int end) {
	if (start > end) {	
		return;
	}
	for (int i = start; i <= end; i++) {  //범위는 end까지만 봐야함 
		if (arr1[t] == arr2[i]) {
			t++;
			f(start, i- 1);		
			f(i + 1, end);
			cout << arr2[i] << " ";
			return;
		}
	}	
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int p; cin >>p;
	for (int i = 0; i < p; i++) {
		t = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
		f(0, n - 1);
		cout << endl;
		
	}
}