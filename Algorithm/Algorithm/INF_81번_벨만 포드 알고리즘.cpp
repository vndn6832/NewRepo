#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;
struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};
int main() {
	vector<Edge> v;
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf_s("%d %d %d", &a, &b, &c);
		v.push_back(Edge(a, b, c));
	}

	vector<int> dist(n + 1, INT_MAX);
	int start, end;
	scanf_s("%d %d", &start, &end); //출발정점, 도착정점
	dist[start] = 0;
	for (int i = 1; i < n; i++) { //이용 간선 개수
		for (int j = 0; j < v.size(); j++) {
			int s = v[j].s; //출발
			int e = v[j].e; //도착
			int w = v[j].val; //가중치 값
			if (dist[s] != INT_MAX && dist[s] + w < dist[e]) {
				dist[e] = dist[s] + w;
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		printf("*** %d\n", dist[i]);
	}
	*/
	for (int j = 0; j < v.size(); j++) {
		int s2 = v[j].s;
		int e2 = v[j].e;
		int w2 = v[j].val;
		if (dist[s2] != INT_MAX && dist[s2] + w2 < dist[e2]) {
			printf("-1\n");
		}
	}

	printf("%d\n", dist[end]);

	return 0;
}