#include<iostream>
#include<queue>
using namespace std;
int res = -1;
int map[7][7];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool check[7][7];
void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7) continue;
			if (map[nx][ny] == 0 && check[nx][ny] != true) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[x][y] + 1;
				if (nx == 6 && ny == 6) {
					res = map[nx][ny];
					break;
				}
				
			}
		}
	}
}
int main() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> map[i][j];
		}
	}

	BFS();

	cout << res << endl;

}