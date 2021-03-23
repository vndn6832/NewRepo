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
		if (f[i].check != false) {

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
				
				
				f[map[nextX][nextY].num].x = x;
				f[map[nextX][nextY].num].y = y;
				
				f[i].x = nextX;
				f[i].y = nextY;
				f[i].dir = nextDir;
			
				map[x][y].num = map[nextX][nextY].num;
				map[x][y].dir = map[nextX][nextY].dir;

				map[nextX][nextY].num = i;
				map[nextX][nextY].dir = nextDir;
				
				
				break;
				
			}

		}

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

	print();

	//상어가 0,0으로
	s.x = 0;
	s.y = 0;
	s.ate = map[0][0].num;
	f[s.ate].check = false;
	map[0][0].num = 0;
	s.dir = map[0][0].dir;
	
	print();
	//물고기 이동
	fishMove();
	print();

}