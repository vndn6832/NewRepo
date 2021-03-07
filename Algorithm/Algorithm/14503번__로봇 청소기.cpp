#include<iostream>
using namespace std;
int N, M;
struct v {
	int r;
	int c;
	int d;

};
v v1;
int map[50][50];
int cnt = 0;
/*πÊ«‚!!!*/
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void DFS(int x, int y, int dir) {
	map[x][y] = -1;
	bool flag = false;
	for (int i = 1; i <= 4; i++) {
		int nDir = (dir - (1 * i) + 4) % 4;
		int nx = x + dx[nDir];
		int ny = y + dy[nDir];

		if (nx <= 0 || nx >= N-1 || ny <= 0 || ny >= M-1) continue;
		if (map[nx][ny] == 0) {
			DFS(nx, ny, nDir);
			flag = true;
			break;
		}

	}
	if (flag == false) {
		int nx = x - dx[dir];
		int ny = y - dy[dir];
		if (map[nx][ny] != 1) {
			DFS(nx, ny, dir);
		}
		else {
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	cin >> v1.r >> v1.c >> v1.d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			
		}
	}

	DFS(v1.r, v1.c, v1.d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				cnt++;
				
			}
			//cout << map[i][j] << " ";
		}
		//cout << endl;
	}
	cout << cnt << endl;

}
