#include<iostream>
#include<queue>
using namespace std;
int n, m;
char map[10][10];
char map2[10][10];
int redX, redY;
int blueX, blueY;
int zeroX, zeroY;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[10][10][10][10];//�湮
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
void bfs() {
	queue<ball> pos;
	pos.push(ball(redX, redY, blueX, blueY));
	int cnt = 0;
	//cout << "zero " << zeroX << "," << zeroY << endl;
	while (!pos.empty()) {
		int size = pos.size();
		
		if (cnt > 10) return; //10�� ���Ϸ� �̵�

		while (size--) { //*�̵�Ƚ�� ���ؾ� �ϴϱ�
			int rx = pos.front().rx;
			int ry = pos.front().ry;
			int bx = pos.front().bx;
			int by = pos.front().by;

			pos.pop();

			/*
			cout << rx << "," << ry << ": " << success << endl;
			cout << bx << "," << by << ": " << success << endl;
			cout << endl;
			*/
			if (rx == zeroX && ry == zeroY) {
				success = true;
				return;
			}

			for (int i = 0; i < 4; i++) {

				int Nrx = rx + dx[i];
				int Nry = ry + dy[i];
				int Nbx = bx + dx[i];
				int Nby = by + dy[i];
				while (1) {

					if (map[Nrx][Nry] == '#') {
						Nrx -= dx[i];
						Nry -= dy[i];
						break;
					}
					if (map[Nrx][Nry] == 'O') {
						break;
					}
					Nrx += dx[i];
					Nry += dy[i];
				}

				while (1) {
					if (map[Nbx][Nby] == '#') {
						Nbx -= dx[i];
						Nby -= dy[i];
						break;
					}
					if (map[Nbx][Nby] == 'O') {
						break;
					}
					Nbx += dx[i];
					Nby += dy[i];
				}
				if (Nbx == zeroX && Nby == zeroY) {
					success = false;
					continue; //*�߰�
				}
				if (Nrx == Nbx && Nry == Nby) {
					if (i == 0) {//��
						if (rx > bx) Nrx++;
						else Nbx++;
					}
					else if (i == 1) {//��
						if (rx > bx) Nbx--;
						else Nrx--;
					}
					else if (i == 2) {//�Ʒ�
						if (ry > by) Nry++;
						else Nby++;
					}
					else {//��
						if (ry > by) Nby--;
						else Nry--;
					}
				}




				if (visited[Nrx][Nry][Nbx][Nby] != true) {
					visited[Nrx][Nry][Nbx][Nby] = true;
					/*
					cout << Nrx << "," << Nry << ": " << success<< endl;
					cout << Nbx << "," << Nby << ": " << success << endl;
					cout << endl;
						*/
					pos.push(ball(Nrx, Nry, Nbx, Nby));
				}

			}

		}
		cnt++;//** cnt ������Ű�� ��ġ �ſ��߿�
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

	if (success != true) { //**
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}
}