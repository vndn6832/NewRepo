#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m;
int map[8][8];
int mapCopy[8][8];
bool visited[8][8]; //시간이 느는 구나...
vector<pair<int, int>> check; //바이러스 위치
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;
int BFS() {
	queue<pair<int, int>> q;
	/*
	for (int i = 0; i < check.size(); i++) {
		q.push(make_pair(check[i].first, check[i].second));
	}
	*/

	/*시간단축*/
	for (int i = 0; i < check.size(); i++) {
		q.push(check[i]);
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (mapCopy[nx][ny] == 0 && visited[nx][ny] != true) {
				visited[nx][ny] = true;
				mapCopy[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}

		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapCopy[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;


}
void DFS(int level) {
	if (level == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mapCopy[i][j] = map[i][j];
			}
		}
		int temp = BFS();
		if (temp > ans) {
			ans = temp;
		}

		memset(visited, false, sizeof(visited));
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(level + 1);
				map[i][j] = 0;
			}
		}
	}

	int result = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
			if (map[i][j] == 2) {
				check.push_back(make_pair(i, j));
			}
		}
	}

	DFS(0);

	cout << ans << endl;


}