#include<stdio.h>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
int V, E;
int start;
vector<pair<int, int>> graph[20001];
struct Edge {
	int v;
	int dis;
	Edge(int a, int b) {
		v = a;
		dis = b;
	}
	bool operator<(const Edge& b)const {
		return dis > b.dis;
	}
};
priority_queue<Edge> pq;
int main() {
	scanf("%d %d", &V, &E);

	scanf("%d", &start);
	vector<int> dist(V + 1, INT_MAX);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
	}

	pq.push(Edge(start, 0));
	dist[start] = 0;

	while (!pq.empty()){

		int now = pq.top().v;
		int cost = pq.top().dis;
		pq.pop();
		if (dist[now] < cost) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = cost + graph[now][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(Edge(next, nextCost));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}