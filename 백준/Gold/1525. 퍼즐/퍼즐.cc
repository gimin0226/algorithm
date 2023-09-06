#include<bits/stdc++.h>	

using namespace std;
int dx[]{ 3,-3,1,-1 };
/*
1 0 3
4 2 5
7 8 6

103425786


*/
int main(void) {
	
	unordered_map<string, bool> um;
	string start;
	int idx;
	for (int i = 0; i < 9; i++) {
		char c;
		cin >> c;
		if (c == '0')idx = i;
		start += c;
	}
	
	queue<pair<string, int>> que;
	que.push({start,idx});
	um[start] = true;
	int time=0;
	while (true) {
		if (que.empty()) {
			cout << "-1";
			return 0;
		}
		int n = que.size();
		for (int i = 0; i < n; i++) {
			string str = que.front().first;
			int idx = que.front().second;
			que.pop();
		//	cout << str << "\n";
			if (str == "123456780") {
				cout << time;
				return 0;
			}
			

			for (int j = 0; j < 4; j++) {
				int nx = idx + dx[j];
				
				
				if (nx < 0 || nx>=9)continue;
				if (idx % 3 == 0 && j == 3) continue; 
				if (idx % 3 == 2 && j == 2) continue; 
				
				std::swap(str[idx], str[nx]);
				if (um.find(str)==um.end()) {
					que.push({ str,nx });
					um.insert({ str,true });
				}
				
				std::swap(str[idx], str[nx]);
			}
			
		}
		
		time++;
	}

}