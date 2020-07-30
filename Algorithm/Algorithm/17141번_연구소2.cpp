#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<limits.h>
using namespace std;
int N, M;
int map[50][50];
int dist[50][50];
vector<pair<int, int>> temp, bomb;
queue<pair<int, int>>q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag2;
int min_cnt = INT_MAX;
int max_dist;
void BFS() {
	flag2 = false;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < bomb.size(); i++) {
		q.push(make_pair(bomb[i].first, bomb[i].second));
		dist[bomb[i].first][bomb[i].second] = 0;
	}


	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
			//if (map[nextY][nextX] == 1 || map[nextY][nextX] == -1) continue;
			if (map[nextY][nextX] != 1 && dist[nextY][nextX] == -1) {
				q.push(make_pair(nextY, nextX));
				dist[nextY][nextX] = dist[y][x] + 1;
				max_dist = dist[nextY][nextX];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 1 && dist[i][j] == -1) {
				flag2 = true;
				break;
			}
		}
	}

	if (flag2 == false) {


		if (max_dist < min_cnt) min_cnt = max_dist;
	}




}
void DFS(int index, int cnt) {
	if (cnt == M) {
		BFS();
		return;
	}

	for (int i = index; i < temp.size(); i++) {
		bomb.push_back(make_pair(temp[i].first, temp[i].second));
		DFS(i + 1, cnt + 1);
		bomb.pop_back();
	}
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				temp.push_back(make_pair(i, j));
				map[i][j] = 0;
			}

		}
	}

	DFS(0, 0);

	if (min_cnt == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << min_cnt << endl;
	}

	return 0;
}