#include<iostream>
#include<vector>
using namespace std;
struct fish {
	int num;
	int dir;
};
struct fish2 {
	int x;
	int y;
	int dir;
	bool check;
};
struct shark {
	int x;
	int y;
	int dir;
	int ate;
};
fish2 f[17];
shark s;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
fish map[4][4];
int ans = 0;
void print() {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].num << " , " << map[i][j].dir << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void fishMove() {
	for (int i = 1; i <= 16; i++) {
		//cout << i << endl;
		if (f[i].check == true) {

			int x = f[i].x;
			int y = f[i].y;
			int dir = f[i].dir;

			for (int j = 0; j < 8; j++) {
				int nextDir = (dir + j) % 8;
				int nextX = x + dx[nextDir];
				int nextY = y + dy[nextDir];

				if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4) continue;
				if (nextX == s.x && nextY == s.y) continue;
				//cout << nextDir<< "***" << x << ", " << y << " ====> " << nextX << ", " << nextY << endl;
				
				//swap(map[nextX][nextY], map[x][y]);
				//swap(f[i], f[map[nextX][nextY].num]);
				
				if (map[nextX][nextY].num == 0) {
					
					f[i].x = nextX;
					f[i].y = nextY;
					f[i].dir = nextDir;

					map[x][y].num = 0;
					map[x][y].dir = -1;

					map[nextX][nextY].num = i;
					map[nextX][nextY].dir = nextDir;
					
				}else{

					f[map[nextX][nextY].num].x = x;
					f[map[nextX][nextY].num].y = y;

					f[i].x = nextX;
					f[i].y = nextY;
					f[i].dir = nextDir;

					map[x][y].num = map[nextX][nextY].num;
					map[x][y].dir = map[nextX][nextY].dir;

					map[nextX][nextY].num = i;
					map[nextX][nextY].dir = nextDir;
				}
				
				
				break;
				
			}

		}

	}
}
void copyF(fish2 f1[17], fish2 f2[17]) {
	for (int i = 1; i <= 16; i++) {
		f1[i].x = f2[i].x;
		f1[i].y = f2[i].y;
		f1[i].dir = f2[i].dir;
		f1[i].check = f2[i].check;
	}
}
void copyMap(fish map1[4][4], fish map2[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map1[i][j].num = map2[i][j].num;
			map1[i][j].dir = map2[i][j].dir;
		}
	}
}
void sharkMove(int x, int y, int dir, int sum) {
	
	fishMove();

	//cout << endl;
	//cout << "물고기 움직인 후" << endl;
	//print();
	
	fish2 f2[17];
	fish map2[4][4];

	copyF(f2, f); //***
	copyMap(map2, map); //***

	bool flag = false;
	for (int i = 1; i <=3; i++) {
		int nx = x + (dx[dir] * i);
		int ny = y + (dy[dir] * i);
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || map[nx][ny].num < 1) continue;
		flag = true;
		
		int tmp = map[nx][ny].num;
		int tmp2 = map[nx][ny].dir;

		f[tmp].check = false;

		s.x = nx;
		s.y = ny;
		s.dir = tmp2;
		s.ate += tmp;

		map[nx][ny].num = 0;
		map[nx][ny].dir = -1;

		//cout << endl;
		//cout << "상어가 먹은 후" << endl;
		//print();
		//cout << "먹은 총량: " <<s.ate << endl;
		sharkMove(s.x, s.y, s.dir,  s.ate);
		
		//f[tmp].check = true;

		s.x = x;
		s.y = y;
		s.dir = dir;
		s.ate = sum;

		//map[nx][ny].num = tmp;
		//map[nx][ny].dir = tmp2;

		copyF(f, f2); //***
		copyMap(map, map2); //***


	}
	if (flag == false) {
		//cout << "sum: " << sum << endl;
		if (sum > ans)
			ans = sum;
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j].num = a;
			map[i][j].dir = b-1;
			f[a].x = i;
			f[a].y = j;
			f[a].dir = b-1;
			f[a].check = true;

		}
	}

	//print();

	//상어가 0,0으로
	s.x = 0;
	s.y = 0;
	s.ate = map[0][0].num;
	ans = s.ate;
	f[s.ate].check = false;
	map[0][0].num = 0;
	s.dir = map[0][0].dir;
	map[0][0].dir = -1;
	
	//print();
	//물고기 이동
	//fishMove();
	//print();

	sharkMove(s.x, s.y, s.dir, s.ate);

	cout << ans << endl;
}