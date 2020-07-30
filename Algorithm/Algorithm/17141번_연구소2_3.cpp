#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int map[50][50];
int map2[50][50];
vector<pair<int, int>> choose; //virus 놓을 수 있는칸
vector<pair<int, int>> virus; //virus
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[50][50];
bool check;
int minVal = 2500;
int maxVal;
void BFS() {
	queue<pair<int, int>> q;
	check = false;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
		visited[virus[i].first][virus[i].second] = true;
		
	}

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				map[nx][ny] = map[x][y]+1;
				//cout << map[nx][ny] << endl;
				maxVal = map[nx][ny];
				q.push(make_pair(nx, ny));
			}
		}
	}
	/*
	cout << "-------------------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "감염후" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 1 && visited[i][j] == false) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
		cout << endl;
	}
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 1 && visited[i][j] == false) {
				check = true;
				break;
			}
			
		}
	}

	if (check == false) {

		if (maxVal < minVal) minVal = maxVal;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = map2[i][j];
		}
	}

}
void DFS(int index, int level) {//virus 놓기
	if (level == m) {
		BFS();
		return;
	}

	for (int i = index; i < choose.size(); i++) {
		virus.push_back(make_pair(choose[i].first, choose[i].second));
		DFS(i + 1, level + 1);
		virus.pop_back();
	}
}
int main() {
	cin >> n >> m; // n 연구소 크기, m 바이러스 수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				choose.push_back(make_pair(i, j));
				map[i][j] = 0;
			}
			map2[i][j] = map[i][j];
		}
	}

	DFS(0, 0);

	if (minVal == 2500)
		cout << -1 << endl;
	else
		cout << minVal << endl;
		
}