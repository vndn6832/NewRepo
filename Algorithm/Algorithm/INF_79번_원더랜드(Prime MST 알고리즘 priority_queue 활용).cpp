#include<stdio.h>
#include<queue>
using namespace std;
int V, E;
struct info{
	int v;
	int val;
	info(int a, int b) {
		v = a;
		val = b;
	}
};
struct cmp { //우선순위 큐 정렬 기준 설정
	bool operator()(info i1, info i2) {
		return i1.val > i2.val;
	}
};
bool check[101];
vector<pair<int,int>> map[101];
priority_queue<info,vector<info>,cmp> pq; //우선순위 큐 선언 방법
int ans = 0;
int main() {
	scanf_s("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf_s("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));

	}

	pq.push(info(1, 0));
	while (!pq.empty()) {
		int v = pq.top().v;
		int val = pq.top().val;
		pq.pop();
		if (check[v] != true) { //*** 트리의 원소가 아니면 - 사이클 생기면 안됨
			check[v] = true;
			ans += val;
			for (int i = 0; i < map[v].size(); i++) {
				if (check[map[v][i].first] != true) {
					pq.push(info(map[v][i].first, map[v][i].second));
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}