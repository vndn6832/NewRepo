#include<iostream>
#include<queue>
using namespace std;
int n, m;
char map[10][10];
char map2[10][10];
int redX, redY;
int blueX, blueY;
int zeroX, zeroY;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
struct ball{
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
void bfs() {
	queue<ball> pos;
	pos.push(ball(redX,redY,blueX,blueY));

	while (!pos.empty()) {
		int rx = pos.front().rx;
		int ry = pos.front().ry;
		int bx = pos.front().bx;
		int by = pos.front().by;

		pos.pop();
		
		if (rx == zeroX && ry == zeroY && bx != zeroX && by != zeroY) {
			success = true;
			return;
		}
		else if (bx == zeroX && by == zeroY) {
			success = false;
		}

		for (int i = 0; i < 4; i++) {

			int Nrx = rx + dx[i];
			int Nry = ry + dy[i];
			int Nbx = bx + dx[i];
			int Nby = by + dy[i];

			if (Nrx <= 1 || Nrx >= n - 1 || Nbx <= 1 || Nby >= m - 1) continue;
			if (map[Nrx][Nry] == '#') {
				Nrx = rx;
				Nry = ry;
			}

			if (map[Nbx][Nby] == '#') {
				Nbx = bx;
				Nby = by;
			}


			if (Nrx == zeroX && Nry == zeroY && Nbx != zeroX && Nby != zeroY) {
				success = true;
				return;
			}
			else if (Nbx == zeroX && Nby == zeroY) {
				success = false;
			}

			pos.push(ball(Nrx, Nry, Nbx, Nby));


		}
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

	if (success == false) {
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}
}