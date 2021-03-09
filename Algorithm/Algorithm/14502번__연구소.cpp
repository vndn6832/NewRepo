//8:57
//2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
//9:51
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int N, M;
int map[8][8];
vector<pair<int, int>> zero;
int zeroCnt = 0;
vector<pair<int, int>> virus;
bool ch[64];
int ans = 0;
bool ch2[8][8];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int spread = 0;
void cpy(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void cal() {
	
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		
		int x = virus[i].first;
		int y = virus[i].second;
		ch2[x][y] = true;
		q.push(make_pair(x, y));
	}
	while (!q.empty()) {

		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (ch2[nx][ny] == false && map[nx][ny] == 0) {
				ch2[nx][ny] = true;
				map[nx][ny] = 2;
				spread++;
				q.push(make_pair(nx, ny));
			}

		}


	}


}
void DFS(int idx, int cnt) {
	if (cnt == 3) {
		int map2[8][8];
		cpy(map2, map);
		for (int i = 0; i < zero.size(); i++) {
			if (ch[i] == true)
				map[zero[i].first][zero[i].second] = 1;
		}

		spread = 0;
		memset(ch2, false, sizeof(ch2));
		cal();
		if (ans < zeroCnt - spread - 3)
			ans = zeroCnt - spread - 3;

		cpy(map, map2);

	}
	else {
		for (int i = idx; i < zero.size(); i++) {
			if (ch[i] != true) {
				ch[i] = true;
				DFS(i, cnt + 1);
				ch[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero.push_back(make_pair(i, j));
				zeroCnt++;
			}
			else if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	DFS(0, 0);
	cout << ans << endl;

}