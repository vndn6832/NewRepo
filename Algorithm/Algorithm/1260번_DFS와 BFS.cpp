#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, v;
vector<int> map[1001];
bool check[1001];
void dfs(int v1) {
	if (check[v1] == true) return;
	check[v1] = true;
	cout << v1 << " ";
	for (size_t i = 0; i < map[v1].size() ; i++) {
		int v2 = map[v1][i];
		dfs(v2);
	}
}
void bfs(int v1) {
	queue <int> q;
	q.push(v1);
	check[v1] = true;

	while (!q.empty())
	{
		int v1 = q.front();
		q.pop();
		cout << v1 << " ";
		for (size_t i = 0; i < map[v1].size(); i++) {
			int v2 = map[v1][i];
			if (check[v2] == false) {
				q.push(v2);
				check[v2] = true;
			}
		}

	}


}
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		sort(map[i].begin(),map[i].end());
	}

	dfs(v);
	cout << endl;
	memset(check, false, sizeof(check));
	bfs(v);
}