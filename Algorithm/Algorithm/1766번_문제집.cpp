#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> node[32001];
int inDegree[32001];
int n, m;
void sort() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			pq.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pq.empty()) {
			return;
		}
		int x = pq.top();
		pq.pop();

		cout << x << " ";


		for (int i = 0; i < node[x].size(); i++) {
			int y = node[x][i];
			if (--inDegree[y] == 0)
				pq.push(y);
		}

	}

}
int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		inDegree[b]++;
	}
	sort();
}