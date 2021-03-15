#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
int n, m;
vector<pair<int, int>> graph[21];
struct Edge {
	int vax;
	int dis;
	Edge(int a, int b) {
		vax = a;
		dis = b;
	}
	bool operator<(const Edge& b)const {
		return dis > b.dis;
	}
};
priority_queue<Edge> pq;
int main() {

	
	cin >> n >> m;
	vector<int> dist(n + 1, INT_MAX);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		
	}

	pq.push(Edge(1, 0));
	dist[1] = 0;
	while (!pq.empty()) {
		int now = pq.top().vax;
		int cost = pq.top().dis;
		pq.pop();

		if (cost > dist[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int nextVax = graph[now][i].first;
			int nextDis = cost + graph[now][i].second;

			if (dist[nextVax] > nextDis) {
				dist[nextVax] = nextDis;
				pq.push(Edge(nextVax, nextDis));
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == INT_MAX)
			cout << i << " : " << "impossible" << endl;
		else
			cout << i << " : " << dist[i] << endl;
	}

	return 0;
}