#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<cstring>
using namespace std;
int n, m;//n:연구소 크기,m:놓을 수 있는 바이러스 수
int map[50][50];
int map2[50][50];
vector<pair<int, int>> choose; //비활성화 바이러스
vector<pair<int, int>> virus; //활성화 바이러스
bool check;
bool visited[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int minVal = INT_MAX;
int maxVal;
void BFS() {
	check = false;
	memset(visited, false, sizeof(visited)); //방문 배열 초기화
	queue<pair<int, int>> q; //큐

	for (int i = 0; i < virus.size(); i++) {
		map[virus[i].first][virus[i].second] = 0; //빈칸
		visited[virus[i].first][virus[i].second] = true; //방문
		q.push(make_pair(virus[i].first, virus[i].second)); 
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); //***

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (visited[nx][ny] == false && map2[nx][ny] != 1) {//*map2 1은 벽
				visited[nx][ny] = true;
				map[nx][ny] = map[x][y] + 1; //+1 (시간측정)
				q.push(make_pair(nx, ny));

				if (map2[nx][ny] == 0) {//*map2
					maxVal = map[nx][ny];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
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
void DFS(int index, int level) {
	if (level == m) { //m개 선택
		BFS(); //퍼뜨리기
		return;
	}

	for (int i = index; i < (int)choose.size(); i++) {
		virus.push_back(make_pair(choose[i].first, choose[i].second)); //바이러스 선택
		DFS(i + 1, level + 1); //인데스 증가, 갯수증가
		virus.pop_back(); //바이러스 선택 해제
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
			map2[i][j] = map[i][j];
		}
	}

	DFS(0, 0);

	if (minVal == INT_MAX)
		cout << -1 << endl;
	else
		cout << minVal << endl;
}