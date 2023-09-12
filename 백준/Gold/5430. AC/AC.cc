#include<bits/stdc++.h>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		string str;
		deque<int> dq;
		cin >> str;

		int n;
		cin >> n;
		
		string str2;
		cin >> str2;
		
		int a = 1;
		string st = "";
		if (n != 0) {
			while (true) {
				if (str2[a] == ']') {
					dq.push_back(stoi(st));
					break;
				}

				if (str2[a] == ',') {
					dq.push_back(stoi(st));
					st = "";
					a++;
				}
				else {
					st += str2[a];
					a++;
				}
			}
		}

		bool check = false;  //false일때는 앞, true일때는 뒤
		bool check2 = false;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'R') {
				check = (check == false) ? true : false;
			}
			else if (str[i] == 'D') {
				if (dq.empty()) {
					cout << "error" << '\n';
					check2 = true;
					break;
				}
				else if (check == true) {
					dq.pop_back();
				}
				else if (check == false) {
					dq.pop_front();
				}
			}
		}
		if (check2 == false) {
			if (check == true) {
				int t = dq.size();
				cout << "[";
				for (int i = 0; i < t; i++) {
					int x = dq.back(); dq.pop_back();
					if (i == t - 1) {
						cout << x ;
					}
					else
						cout << x << ",";
				}
			}
			else {
				int t = dq.size();
				cout << "[";
				for (int i = 0; i < t; i++) {
					int x = dq.front(); dq.pop_front();
					if (i == t - 1) {
						cout << x ;
					}
					else
						cout << x << ",";
				}
			}cout<< "]" << endl;
		}
		
	}
}


