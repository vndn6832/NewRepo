#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int map[25][25];
bool check[25][25] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
vector<int> ans;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];

			if (x2 >= n || y2 >= n || x2 < 0 || y2 < 0) continue;

			if (map[x2][y2] == 1 && check[x2][y2] == 0) {
				q.push(make_pair(x2, y2));
				check[x2][y2] = 1;
				cnt++;
			}
		}
	}
	ans.push_back(cnt);
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}