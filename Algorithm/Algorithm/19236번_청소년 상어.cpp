#include<iostream>
#include<vector>
using namespace std;
struct fishMap {
	int num;
	int dir;
};
struct shark {
	int x;
	int y;
	int dir;
	int eat;
};
struct fishInfo {
	int x;
	int y;
	int dir;
};
shark s;
fishMap map[4][4];
int ans = 0;
fishInfo f[17];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
void move() {
	/*물고기 움직임*/
	for (int i = 1; i <= 16; i++) {
		if (f[i].dir == 0) continue;
		int x = f[i].x;
		int y = f[i].y;
		int d = f[i].dir - 1;
		for (int j = 0; j < 8; j++) {
			int nd = (d + j) % 8;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if (nx == s.x && ny == s.y) continue;

			if (map[nx][ny].num != 0) {

				map[x][y].dir = map[nx][ny].dir;
				map[x][y].num = map[nx][ny].num;
				map[nx][ny].num = i;
				map[nx][ny].dir = nd + 1;

				f[i].dir = nd + 1;
				f[i].x = nx;
				f[i].y = ny;

				f[map[x][y].num].x = x;
				f[map[x][y].num].y = y;
			}
			else {

				map[x][y].num = 0;
				map[x][y].dir = 0;

				map[nx][ny].num = i;
				map[nx][ny].dir = nd + 1;

				f[i].dir = nd + 1;
				f[i].x = nx;
				f[i].y = ny;

			}

			break;
		}
	}


	/*상어 움직임*/

	int x = s.x;
	int y = s.y;
	int d = s.dir;
	int nx = x;
	int ny = y;
	vector<pair<int, int>> ss;
	while (1) {
		nx += dx[d - 1];
		ny += dy[d - 1];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		if (map[nx][ny].num != 0) ss.push_back(make_pair(nx, ny));
	}

	for (int i = 0; i < ss.size(); i++) {
		s.x = ss[i].first;
		s.y = ss[i].second;
		int fd = f[map[s.x][s, y].num].dir; //먹는 물고기 방향
		int fn = map[s.x][s.y].num; //먹는 물고기 번호

		f[map[s.x][s, y].num].dir = 0;
		map[s.x][s.y].num = 0;
		s.dir = map[s.x][s.y].dir;
		s.eat += fn;


		move();

		s.x = x;
		s.y = y;

		f[map[s.x][s.y].num].dir = fd;
		map[s.x][s.y].num = fn;
		s.dir = d;
		s.eat -= fn;


	}

	cout << s.eat << endl;

	if (s.eat > ans) ans = s.eat;


}
void main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int val;
			cin >> val;
			if (j % 2 == 0) {
				map[i][j / 2].num = val;
				f[val].x = i;
				f[val].y = j / 2;
			}
			else {
				map[i][(j - 1) / 2].dir = val; //1~8
				f[map[i][(j - 1) / 2].num].dir = val;
			}
		}
	}
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].num << " " << map[i][j].dir;
		}
		cout << endl;
	}*/

	s.x = 0;
	s.y = 0;
	s.eat = 0;

	f[map[0][0].num].dir = 0;
	map[0][0].num = 0;
	s.dir = map[0][0].dir;

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].num << " " << map[i][j].dir;
		}
		cout << endl;
	}*/

	move();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].num << " " << map[i][j].dir;
		}
		cout << endl;
	}

	cout << ans << endl;
}