#include<iostream>
#include<queue>
using namespace std;
int n;
int map[20][20];
queue<pair<int, int>> q;
bool check[20][20];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1};
int cnt = 0;
void BFS() {
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = true;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] == 1 && check[nx][ny] != true) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}

		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] !=true) {
				q.push(make_pair(i, j));
				BFS();
				cnt++;
			}
		}
	}

	cout << cnt << endl;

}