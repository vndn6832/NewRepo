#include<iostream>
#include<vector>
using namespace std;
int R, C, M;
struct shark {
	int x;
	int y;
	int speed;
	int dir;
	int size;
	shark(int a, int b, int c, int d, int e) {
		x = a;
		y = b;
		speed = c;
		dir = d;
		size = e;
	}
};
vector<shark> s;
int map[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void copyMap(int a[100][100], int b[100][100]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			a[i][j] = b[i][j];
		}
	}
}
int ans = 0;
int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		s.push_back(shark(a-1, b-1, c, d-1, e));
		map[a-1][b-1] = e;
		
	}

	//print();
	
	for (int i = 0; i < C; i++) {
		/*cout << "먹기전" << endl;
		print();*/
		for (int j = 0; j < R; j++) {
			if (map[j][i] != 0) {
				ans += map[j][i];
				map[j][i] = 0;
				break;
				
			}

		}
	/*	cout << "먹은후 ==> " << endl;
		print();*/
		int map2[100][100] = { 0, };

		//상어 움직임
		for (int k = 0; k < s.size(); k++) {

			int x = s[k].x;
			int y = s[k].y;
			int dir = s[k].dir;
			int speed = s[k].speed;
			int size = s[k].size;

			if (map[x][y] != size || s[k].dir == -1) continue;

			int nx = x;
			int ny = y;
			if (dir == 0 || dir == 1) {
				speed = speed % (2* R - 2);
			}
			else {
				speed = speed % (2 * C - 2);
			}
			for (int d = 0; d < speed; d++) {
				nx += dx[dir];
				ny += dy[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
					/*방향 바꾸기 중요*/
					if (dir == 0) {
						dir = 1;
					}
					else if (dir == 1) {
						dir = 0;
					}
					else if (dir == 2) {
						dir = 3;
					}
					else if (dir == 3) {
						dir = 2;
					}
					nx = nx + (dx[dir] * 2);
					ny = ny + (dy[dir] * 2);
				}
			}
			/*cout << endl;
			cout << nx << ", " << ny << endl;
			cout << size << endl;
			cout << map2[nx][ny] << endl;
			cout << endl;*/
			if (map2[nx][ny] < size) {
				map2[nx][ny] = size;
				s[k].x = nx;
				s[k].y = ny;
				s[k].dir = dir;
			}
			else {
				s[k].dir = -1;
			}

			
			
		}
		copyMap(map, map2);
		/*cout << "상어 움직인 후" << endl;
		print();*/

	}
	cout << ans << endl;
}