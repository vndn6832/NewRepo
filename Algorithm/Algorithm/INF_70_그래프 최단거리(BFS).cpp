#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<int> v[21];
int ch[21];
int dis[21];
queue<int> q;
int main() {
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	q.push(1);
	ch[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (ch[v[x][i]] != 1) {
				ch[v[x][i]] = 1;
				q.push(v[x][i]);
				dis[v[x][i]] = dis[x] + 1;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << dis[i] << endl;
	}
}
