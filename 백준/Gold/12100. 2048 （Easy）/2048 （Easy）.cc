#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int **arr;
int n;
int maxx=0;
queue<int> que;

void BackTracking(int num) {
	if (num == 5) {/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}cout << endl;
		}cout << endl;*/
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxx < arr[i][j]) {
					maxx = arr[i][j];
				}
			}
		}
		return;
	}
	int** arr2 = new int* [n];
	for (int i = 0; i < n; i++) {
		arr2[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		std::copy(arr[i], arr[i] + n, arr2[i]);
	}
	//왼쪽으로 이동
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				que.push(arr[i][j]);
			}
		}
		int idx = 0;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (!que.empty()&&que.front() == x) {
				que.pop();
				arr[i][idx] = x * 2;
				idx++;
			}
			else {
				arr[i][idx] = x;
				idx++;
			}
		}
		for (int j = idx; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	BackTracking(num + 1);
	for (int i = 0; i < n; i++) {
		std::copy(arr2[i], arr2[i] + n, arr[i]);
	}
	//오른쪽으로 이동
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >=0; j--) {
			if (arr[i][j] != 0) {
				que.push(arr[i][j]);
			}
		}
		int idx = n-1;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (!que.empty() && que.front() == x) {
				que.pop();
				arr[i][idx] = x * 2;
				idx--;
			}
			else {
				arr[i][idx] = x;
				idx--;
			}
		}
		for (int j = 0; j <=idx; j++) {
			arr[i][j] = 0;
		}
	}
	BackTracking(num + 1);
	for (int i = 0; i < n; i++) {
		std::copy(arr2[i], arr2[i] + n, arr[i]);
	}
	
	//위로 이동
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != 0) {
				que.push(arr[j][i]);
			}
		}
		int idx = 0;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (!que.empty() && que.front() == x) {
				que.pop();
				arr[idx][i] = x * 2;
				idx++;
			}
			else {
				arr[idx][i] = x;
				idx++;
			}
		}
		for (int j = idx; j < n; j++) {
			arr[j][i] = 0;
		}
	}
	
	BackTracking(num + 1);
	for (int i = 0; i < n; i++) {
		std::copy(arr2[i], arr2[i] + n, arr[i]);
	}
	//아래쪽으로 이동
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (arr[j][i] != 0) {
				que.push(arr[j][i]);
			}
		}
		int idx = n - 1;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (!que.empty() && que.front() == x) {
				que.pop();
				arr[idx][i] = x * 2;
				idx--;
			}
			else {
				arr[idx][i] = x;
				idx--;
			}
		}
		for (int j = 0; j <= idx; j++) {
			arr[j][i] = 0;
		}
	}
	BackTracking(num + 1);
	for (int i = 0; i < n; i++) {
		std::copy(arr2[i], arr2[i] + n, arr[i]);
	}

	for (int i = 0; i < n; i++) {
		delete[] arr2[i];
	}delete[] arr2;

	return;
}


int main(void) {
	
	cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	BackTracking(0);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	cout << maxx;
	return 0;

}