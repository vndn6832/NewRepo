#include<iostream>
#include<vector>
using namespace std;
struct fish {
	int num;
	int dir;
};
struct shark {
	int x;
	int y;
	int dir;
	int eat;
};

fish map[4][4];
bool visited[16];
int ans = 0;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void moveFish(shark s) {
	/*물고기 움직임*/
	for (int idx = 1; idx <= 16; idx++) {
		if (visited[idx - 1] == true) continue;
		bool findIdx = false;
		for (int i = 0; i < 4 && findIdx == false ; i++) {
			for (int j = 0;j<4 && findIdx == false; j++) {
				if (map[i][j].num == idx) {
					fish f = map[i][j];
					for (int k = 0; k < 8; k++) {
						int nd = (k + f.dir) % 8;
						int nx = i + dx[nd];
						int ny = j + dy[nd];
						if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
						if (nx == s.x && ny == s.y) continue;
						fish tmp = map[nx][ny];
						map[nx][ny] = map[i][j];
						map[i][j] = tmp;
						map[nx][ny].dir = nd;
						findIdx = true;
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
void solution(shark s){
	if (s.eat > ans) ans = s.eat;
	fish cpyMap[4][4];
	moveFish(s);
	copyToMap(map, cpyMap);
	int d = s.dir;
	int nx = s.x;
	int ny = s.y;

	while (1) {
		nx += dx[d];
		ny += dy[d];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		if (map[nx][ny].num == 0) continue;

		shark ns;
		ns.x = nx;
		ns.y = ny;
		ns.eat = map[nx][ny].num + s.eat;
		ns.dir = map[nx][ny].dir;

		int num = map[nx][ny].num;
		visited[num - 1] = true;
		map[nx][ny].num = 0;
		solution(ns);
		copyToMap(cpyMap, map);
		map[nx][ny].num = num;
		visited[num - 1] = false;

	}

	
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a,b;
			cin >> a >> b;
			map[i][j].num = a;
			map[i][j].dir = b - 1;
			
		}
	}

	shark s;
	s.x = 0;
	s.y = 0;
	s.eat = map[0][0].num;
	s.dir = map[0][0].dir;



	visited[map[0][0].num - 1] = true;
	map[0][0].num = 0;
	solution(s);

	cout << ans << endl;
}