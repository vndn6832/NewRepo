#include<iostream>
#include<queue>
using namespace std;
char map[10][10];
int n, m;
int zeroX, zeroY;
int redX, redY;
int blueX, blueY;
struct ball {
	int rx;
	int ry;
	int bx;
	int by;
	ball(int a, int b, int c, int d) {
		rx = a;
		ry = b;
		bx = c;
		by = d;
	}
};
bool success = false;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[10][10][10][10];
int cnt = 0;
void bfs() {
	queue<ball> q;
	q.push(ball(redX, redY, blueX, blueY));


	while (!q.empty()) {
		int size = q.size();
		if (cnt > 10) return;
		while (size--) {
			int rx = q.front().rx;
			int ry = q.front().ry;
			int bx = q.front().bx;
			int by = q.front().by;

			q.pop();

			if (rx == zeroX && ry == zeroY) {
				success = true;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nextRx = rx + dx[i];
				int nextRy = ry + dy[i];
				int nextBx = bx + dx[i];
				int nextBy = by + dx[i];

				while (1) {


					if (map[nextRx][nextRy] == '#') {
						nextRx -= dx[i];
						nextRy -= dy[i];
						break;
					}

					if (map[nextRx][nextRy] == 'O') {
						break;
					}

					nextRx += dx[i];
					nextRy += dy[i];
				}

				while (1) {


					if (map[nextBx][nextBy] == '#') {
						nextBx -= dx[i];
						nextBy -= dy[i];
						break;
					}
					if (map[nextBx][nextBy] == 'O') {
						break;
					}

					nextBx += dx[i];
					nextBy += dy[i];
				}

				if (nextBx == zeroX && nextBy == zeroY) {
					success = false;
					continue;
				}

				if (nextRx == nextBx && nextRy == nextBy) {
					if (i == 0) {//¿Þ
						if (rx > bx) nextRx++;
						else nextBx++;
					}
					else if (i == 1) {//¿À
						if (rx > bx) nextBx--;
						else nextRx--;
					}
					else if (i == 2) {//¾Æ·¡
						if (ry > by) nextRy++;
						else nextBy++;
					}
					else {//À§
						if (ry > by) nextBy--;
						else nextRy--;
					}
				}
				if (visited[nextRx][nextRy][nextBx][nextBy] != true) {
					visited[nextRx][nextRy][nextBx][nextBy] = true;
					q.push(ball(nextRx, nextRy, nextBx, nextBy));
				}

			}
		}

		cnt++;

	}


}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				redX = i;
				redY = j;
			}
			if (map[i][j] == 'B') {
				blueX = i;
				blueY = j;
			}
			if (map[i][j] == 'O') {
				zeroX = i;
				zeroY = j;
			}
		}
	}
	bfs();

	if (success == true)
		cout << cnt << endl;
	else
		cout << -1 << endl;

}