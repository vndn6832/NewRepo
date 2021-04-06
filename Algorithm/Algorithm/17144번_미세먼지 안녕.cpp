#include<iostream>
using namespace std;
int R, C, T;
int map[50][50];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int r1, r2;
void copyMap(int a[50][50], int b[50][50]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void move() {
	int map2[50][50] = { 0, };
	map2[r1][0] = -1;
	map2[r2][0] = -1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {

				int cnt = 0;
				int val = map[i][j] / 5;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

					if (map[nx][ny] != -1) {
						cnt++;
						map2[nx][ny] += val;
					}

				}

				map2[i][j] += (map[i][j] - val * cnt);


			}
		}
	}

	copyMap(map, map2);
}
void clean() {
	//반시계 방향

	for (int i = r1 - 1; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}

	for (int i = 0; i < C - 1; i++) {
		map[0][i] = map[0][i + 1];
	}

	for (int i = 0; i < r1; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}

	for (int i = C - 1; i > 1; i--) {
		map[r1][i] = map[r1][i - 1];
	}

	map[r1][1] = 0; //*** 마지막에


	//시계 방향

	for (int i = r2 + 1; i < R - 1; i++) {
		map[i][0] = map[i + 1][0];
	}

	for (int i = 0; i < C - 1; i++) {
		map[R - 1][i] = map[R - 1][i + 1];
	}

	for (int i = R - 1; i > r2; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}

	for (int i = C - 1; i > 1; i--) {
		map[r2][i] = map[r2][i - 1];
	}

	map[r2][1] = 0; //*** 마지막에

}
void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	cin >> R >> C >> T;


	bool check = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && check == false) {
				check = true;
				r1 = i;
			}
			else if (map[i][j] == -1 && check == true) {
				r2 = i;
			}

		}
	}
	while (T != 0) {

		move();

		//print();

		clean();

		//print();

		T--;
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0)
				ans += map[i][j];

		}
	}

	cout << ans << endl;
}