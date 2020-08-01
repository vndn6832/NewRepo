#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<cstring>
using namespace std;
int n, m;//n:연구소 크기,m:놓을 수 있는 바이러스 수
int map[50][50];
int dist[50][50];//*
vector<pair<int, int>> choose; //비활성화 바이러스
vector<pair<int, int>> virus; //활성화 바이러스
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int minVal = INT_MAX;
int maxVal;
int zeroCnt =0;
void BFS() {
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
	    dist[virus[i].first][virus[i].second] = 0;
		q.push(make_pair(virus[i].first, virus[i].second));
	}
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (dist[nx][ny] == -1 && map[nx][ny] != 1) {//0,2 둘다 지날 수 있다
				
				dist[nx][ny] = dist[x][y] + 1;
				
				q.push(make_pair(nx, ny));
				if (map[nx][ny] == 0){
					maxVal = dist[nx][ny];
					cnt++;
				}
			}
		}
	}

	

	if (zeroCnt == cnt) {
		if (maxVal < minVal) minVal = maxVal;
	}

	

}
void DFS(int index, int level) {
	if (level == m) {
		BFS();
		return;
	}

	for (int i = index; i < (int)choose.size(); i++) {
		virus.push_back(make_pair(choose[i].first, choose[i].second));
		DFS(i + 1, level + 1);
		virus.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				choose.push_back(make_pair(i, j));
			}
			if (map[i][j] == 0) zeroCnt++; //*
			
		}
	}

	DFS(0, 0);

	if (minVal == INT_MAX)
		cout << -1 << endl;
	else
		cout << minVal << endl;
}