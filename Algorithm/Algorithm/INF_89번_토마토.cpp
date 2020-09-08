#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int m, n;
int map[1000][1000];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int check[1000][1000];
vector<pair<int, int>> tomato;
int zero = 0;
int dist[1000][1000];
void BFS() {
	queue<pair<int, int>> q;
	for (int i = 0; i < tomato.size(); i++) {
		q.push(make_pair(tomato[i].first, tomato[i].second));
		check[tomato[i].first][tomato[i].second] = true;
		dist[tomato[i].first][tomato[i].second] = 0;
	}

	while (!q.empty()) {



			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			/*for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (check[nx][ny] != true && map[nx][ny] == 0) {
					check[nx][ny] = true;
					
						map[nx][ny] = 1;
						zero--;
						dist[nx][ny] = dist[x][y] + 1;
					
					
					q.push(make_pair(nx, ny));


				}
			}


		




	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				tomato.push_back(make_pair(i, j));
			if (map[i][j] == 0)
				zero++;
		}
	}
	if (tomato.size() == m * n)
		cout << 0 << endl;
	else {
		BFS();
		if (zero != 0)
			cout << -1 << endl;
		else {
			int res = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (dist[i][j] > res) res = dist[i][j];
				}
			}
			cout << res << endl;
		}
	}

}