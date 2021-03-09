#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int map[25][25];
bool chk[25][25];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> num;
void BFS(int x, int y, int cnt) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	chk[x][y] = true;
	num.push_back(0);

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		num[cnt]++;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (chk[nx][ny] != true && map[nx][ny] == 1) {
				chk[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
vector<pair<int, int> > house;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		if (chk[x][y] != true) {

			BFS(x, y, cnt);
			cnt++;
		}
	}

	cout << num.size() << endl;

	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
	}
}
