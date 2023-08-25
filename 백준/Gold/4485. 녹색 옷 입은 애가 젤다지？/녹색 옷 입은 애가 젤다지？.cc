#include<iostream>
#include<climits>
#include<queue>

static int INF = INT_MAX;
int** arr;
int** dist;
int n;
class Node {
public:
	int x;
	int y;
	int cost;
	Node(int x1,int y2,int z3)
		:x(x1),y(y2),cost(z3){}
	
};

struct CompareNode {
	bool operator() (const Node& n1, const Node& n2 ) {
		return n1.cost > n2.cost;
	}
};
void Dijkstra() {
	std::priority_queue<Node, std::vector<Node>, CompareNode> pq;
	Node node(0, 0, arr[0][0]);
	pq.push(node);
	while (!pq.empty()) {
		node = pq.top();
		pq.pop();
		int x = node.x;
		int y = node.y;
		int cost = node.cost;
		if (cost > dist[x][y]) {
			continue;
		}
		if (x - 1 >= 0 && arr[x - 1][y] + cost < dist[x - 1][y]) {
			dist[x - 1][y] = arr[x - 1][y] + cost;
			Node node2(x - 1, y, arr[x - 1][y] + cost);
			pq.push(node2);
		}
		if (x +1 <n && arr[x + 1][y] + cost < dist[x + 1][y]) {
			dist[x + 1][y] = arr[x + 1][y] + cost;
			Node node2(x + 1, y, arr[x + 1][y] + cost);
			pq.push(node2);
		}
		if (y + 1 < n && arr[x][y+1] + cost < dist[x][y+1]) {
			dist[x][y+1] = arr[x][y+1] + cost;
			Node node2(x, y+1, arr[x][y+1] + cost);
			pq.push(node2);
		}
		if (y -1>=0 && arr[x][y - 1] + cost < dist[x][y - 1]) {
			dist[x][y - 1] = arr[x][y - 1] + cost;
			Node node2(x, y - 1, arr[x][y - 1] + cost);
			pq.push(node2);
		}

	}
}

int main(void) {

	int idx = 1;
	while (true) {
		n;
		std::cin >> n;
		if (n == 0) {
			break;
		}
		arr = new int* [n];
	    dist = new int* [n];

		for (int i = 0; i < n; i++) {
			dist[i] = new int[n];
			arr[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> arr[i][j];
				dist[i][j] = INF;
			}
		}

		Dijkstra();


		std::cout << "Problem " << idx << ": " << dist[n - 1][n - 1] << std::endl;
		idx++;
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}
}