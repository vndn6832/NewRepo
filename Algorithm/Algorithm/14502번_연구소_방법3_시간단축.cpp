#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int map[8][8];
int map2[8][8];
vector<pair<int, int>> zero;
vector<pair<int, int>> virus;;
vector<pair<int, int>> wall;
int ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[8][8];
void BFS() {
	for (int i = 0; i < wall.size(); i++) {
		map[wall[i].first][wall[i].second] = 1;
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (map[nx][ny] == 0 && visited[nx][ny] != true) {
				visited[nx][ny] = true;
				map[nx][ny] = 2;
				q.push(make_pair(nx, ny));

			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}

	if (cnt > ans) ans = cnt;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map2[i][j];
		}
	}
}

void DFS(int index, int level) {
	if (level == 3) {
		BFS();
		return;
	}

	for (int i = index; i < zero.size(); i++) {
		wall.push_back(make_pair(zero[i].first, zero[i].second));
		DFS(i + 1, level + 1);
		wall.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero.push_back(make_pair(i, j));
			}

			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}

			map2[i][j] = map[i][j];

		}
	}

	DFS(0, 0);//∫Æ º±≈√

	cout << ans << endl;
}