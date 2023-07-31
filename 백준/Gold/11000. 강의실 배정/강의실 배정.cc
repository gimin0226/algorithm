#include<iostream>	
#include<vector>
#include<queue>
#include<algorithm>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		vec.push_back(std::make_pair(x, y));
	}
	std::sort(vec.begin(), vec.end());

	std::priority_queue<int,std::vector<int>,std::greater<int>> que;
	

	que.push(vec[0].second);
	int num = 1;

	for (int i =1; i < n; i++) {
		if (que.top()<=vec[i].first)
		{
			que.pop();
			que.push(vec[i].second);
		}
		else
		{
		//	std::cout << "i:" << i << " vec[i].first" << vec[i].first << " vec[i].second" << vec[i].second << "\n";
			num++;
			que.push(vec[i].second);
		}
	}
	std::cout <<num;
}