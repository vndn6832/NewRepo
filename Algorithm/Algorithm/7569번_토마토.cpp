#include<iostream>
#include<queue>
using namespace std;
int M, N, H;
int zero = 0;
int map[100][100][100];
int dis[100][100][100] = { 0, };
int dz[6] = { 1,-1,0,0,0,0 }; //위 아래 앞 뒤 오 왼 
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };
struct tomato {
	int z;
	int y;
	int x;
	tomato(int a, int b, int c) {
		z = a;
		y = b;
		x = c;
	}
};
queue<tomato> q;
int cnt = 0;
void BFS() {

	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;

		q.pop();
		// a) cnt ++; 
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (dis[nz][ny][nx] == 0 && map[nz][ny][nx] == 0) {
				dis[nz][ny][nx] = dis[z][y][x] + 1;
				map[nz][ny][nx] = 1;
				q.push(tomato(nz, ny, nx));
				//b) cnt++;
				zero--;
				if (cnt < dis[nz][ny][nx])
					cnt = dis[nz][ny][nx];
			}
		}
	}
}
int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 0)
					zero++;
				else if (map[i][j][k] == 1)
					q.push(tomato(i, j, k));
			}
		}
	}
	BFS();


	if (zero == 0 && cnt == 0) {
		cout << 0 << endl;
	}
	else if (zero != 0) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;

	}


}

