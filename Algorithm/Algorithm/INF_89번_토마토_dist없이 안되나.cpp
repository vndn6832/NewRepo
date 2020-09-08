//꼭 dist 써야하나
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
int cnt = 0;
int zero = 0;
void BFS() {
	queue<pair<int, int>> q;
	for (int i = 0; i < tomato.size(); i++) {
		q.push(make_pair(tomato[i].first, tomato[i].second));
		check[tomato[i].first][tomato[i].second] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		
		cout << "size: " << size << endl;
		cout << endl;
		cnt++;
		for (int s = 0; s < q.size(); s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (check[nx][ny] != true && map[nx][ny] != 1) {
					check[nx][ny] = true;
					if (map[nx][ny] == 0) {
						map[nx][ny] = 1;
						zero--;
					}
					if (zero == 0) break;
					q.push(make_pair(nx, ny));
					
					
				}
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
		cout << cnt << endl;
	}
	
}