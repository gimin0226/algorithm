#include<bits/stdc++.h>

using namespace std;

int main(void) {

	int n;
	int k;
	cin >> n >> k;
	vector<pair<int,bool>> arr(n * 2);

	for (int i = 0; i < n * 2; i++) {
		cin >> arr[i].first;
		arr[i].second = false;
	}

	int start = 2*n-1;
	int out = (start + n - 1) % (2 * n);
	queue<int> robot;
	int time = 0;
	int num = 0;
	while (true) {
		
	
		int t = robot.size();
		for (int i = 0; i < t; i++) {
			//cout << robot.front() << " ";
			int x = robot.front(); robot.pop();
			if (x == out) {
				arr[x].second = false;
				continue;
			}

			int k = (x + 1) % (2 * n);
			if (arr[k].second == false && arr[k].first >= 1) {
				arr[x].second = false;
				arr[k].second = true;
				arr[k].first -= 1;
				if (arr[k].first == 0)num++;
				if (k == out) {
					arr[k].second = false;
					continue;
				}
				robot.push(k);

			}
			else {
				robot.push(x);
			}


		}
		//cout << endl;

		if (arr[start].first >= 1) {
			arr[start].second = true;
			arr[start].first -= 1;
			if (arr[start].first == 0)num++;
			robot.push(start);
		}
		time++;
		if (num >= k)break;
		if (start >= 1) {
			start -= 1;
		}
		else {
			start = 2 * n - 1;
		}
		out = (start + n - 1) % (2 * n);
	}

	cout << time;
}