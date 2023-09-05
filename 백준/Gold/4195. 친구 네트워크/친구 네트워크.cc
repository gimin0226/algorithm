#include<bits/stdc++.h>

using namespace std;
unordered_map<string,tuple<string,int,int>> um; // string int int 부모 높이 인원 
string find_node(string x) {
	auto it = um.find(x);
	if (it == um.end()) {
		um[x] = { x,1,1 };
		return x;
	}
	string mom = get<0>(it->second);
	string& parent_mom = get<0>(um[mom]);
	if (parent_mom==mom) {
		return parent_mom;
	}
	else {
		return parent_mom=find_node(parent_mom);
	}
}

void union_node(string x, string y) {
	string a = find_node(x);
	string b = find_node(y);

	string& momA = get<0>(um[a]);string& momB = get<0>(um[b]);
	int& heightA = get<1>(um[a]);int& heightB = get<1>(um[b]);
	int& countA = get<2>(um[a]);int& countB = get<2>(um[b]);

	if (a != b) {
		if (heightA > heightB) {
			momB = momA;
			countA += countB;
			cout << countA << '\n';
		}
		else if (heightA < heightB) {
			momA = momB;
			countB += countA;
			cout << countB << '\n';
		}
		else {
			momA = momB;
			countB += countA;
			heightB += 1;
			cout << countB << '\n';
		}	
	}
	else {
		cout << countB << '\n';
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int case_num;
	cin >> case_num;
	for (int t = 0; t < case_num; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string x;
			string y;
			cin >> x >> y;
			union_node(x, y);

		}
		um.clear();
	
	}
}