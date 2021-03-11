#include<iostream>
#include<vector>
#include<limits.h>
#include<cstring>
#include<queue>
using namespace std;
int N, M;
int map[50][50];
vector<pair<int, int> > tmp;
int ans = INT_MAX;
bool check[10];
bool check2[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int zero = 0;
int spread = 0;
int cal() {
	int ret = 0;
	queue<pair<int, int> > q;
	for (int i = 0; i < tmp.size(); i++) {
		if (check[i] == true) {
			check2[tmp[i].first][tmp[i].second] = true;
			q.push(make_pair(tmp[i].first, tmp[i].second));
		}

	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (check2[nx][ny] == false && map[nx][ny] == 0) {
				check2[nx][ny] = true;
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[x][y] + 1;
				spread++;
				if (ret < map[nx][ny])
					ret = map[nx][ny];
			}
		}
	}
	return ret;
}
void cpy(int a[50][50], int b[50][50]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void DFS(int idx, int cnt) {
	if (cnt == M) {
		spread = 0;
		int map2[50][50];
		cpy(map2, map); //***
		memset(check2, false, sizeof(check2));
		int c = cal();
		if (spread == zero && c < ans) {
			ans = c;
		}
		cpy(map, map2); //***

	}
	else {
		for (int i = idx; i < tmp.size(); i++) {
			if (check[i] != true) {
				check[i] = true;
				DFS(i, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				tmp.push_back(make_pair(i, j));
				map[i][j] = 0;
			}
			else if (map[i][j] == 0) {
				zero++;
			}

		}
	}
	zero += tmp.size() - M;

	DFS(0, 0);

	if (ans == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}
