#include<iostream>
using namespace std;
struct  fish{
	int num;
	int dir;
};
struct shark {
	int x;
	int y;
	int num;
	int dir;
};

fish map[4][4];
int visited[16];
int answer = 0;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
void moveFish(shark sh) {
	for (int idx = 1; idx <= 16; idx++) {
		if (visited[idx - 1] == 1) continue;
		int findIdx = 0;
		for (int i = 0; i < 4 && findIdx == 0; i++) {
			for (int j = 0; j < 4 && findIdx == 0; j++) {
				if (map[i][j].num == idx) {
					fish f = map[i][j];
					for (int k = 0; i < 8; k++) {
						int nd = (k + f.dir) % 8;
						int nx = i + dx[nd];
						int ny = j + dy[nd];
						if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
						if (nx == sh.x && ny == sh.y) continue;
						fish tmp = map[nx][ny];
						map[nx][ny] = map[i][j];
						map[i][j] = tmp;
						map[nx][ny].dir = nd;
						findIdx = 1;
						break;
					}
				}
			}
		}
	}
}
void copyToMap(fish org[4][4], fish dest[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dest[i][j] = org[i][j];
		}
	}
}
void solution(shark sh) {
	if (sh.num > answer) answer = sh.num;
	fish cpyMap[4][4];
	moveFish(sh);
	copyToMap(map, cpyMap);
	int nx = sh.x, ny = sh.y;
	while (1) {
		nx += dx[sh.dir];
		ny += dy[sh.dir];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		if (map[nx][ny].num == 0) continue;
		shark nsh;
		nsh.x = nx;
		nsh.y = ny;
		nsh.num = sh.num + map[nx][ny].num;
		nsh.dir = map[nx][ny].dir;

		int num = map[nx][ny].num;
		visited[num - 1] = 1;
		map[nx][ny].num = 0;
		solution(nsh);
		copyToMap(cpyMap, map);
		map[nx][ny].num = num;
		visited[num - 1] = 0;
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;

			map[i][j].num = a;
			map[i][j].dir = b-1;
		}
	}
	shark s;
	s.x = 0;
	s.y = 0;
	s.num = map[0][0].num;
	s.dir = map[0][0].dir;

	visited[map[0][0].num - 1] = 1;
	map[0][0].num = 0;
	solution(s);
	cout << answer << endl;

}