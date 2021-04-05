#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
struct fire {
	int x;
	int y;
	int m;
	int speed;
	int dir;
	fire(int a, int b, int c, int d, int e) {
		x = a;
		y = b;
		m = c;
		speed = d;
		dir = e;
	}
};
vector<fire> map[50][50];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
void copyMap(vector<fire> a[50][50], vector<fire> b[50][50]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j].clear(); //***Áö¿öÁà¾ß ÇÔ
			for (int k = 0; k < b[i][j].size(); k++) {
				a[i][j].push_back(b[i][j][k]);
			}
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				cout << map[i][j][k].m << ", ";
			}
			cout << " / ";
		}
		cout << endl;
	}
}
int ans = 0;
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		map[a - 1][b - 1].push_back(fire(a - 1, b - 1, c, d, e));
	}


	while (K != 0) {
		vector<fire> map2[50][50];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].size() == 0) continue; //¼Ò¸ê µÆÀ¸¸é
				for (int k = 0; k < map[i][j].size(); k++) {
					int x = map[i][j][k].x;
					int y = map[i][j][k].y;
					int m = map[i][j][k].m;
					int speed = map[i][j][k].speed;
					int dir = map[i][j][k].dir;


					int speed2 = speed % N;

					int nx = (x + (dx[dir] * speed2) + N) % N;
					int ny = (y + (dy[dir] * speed2) + N) % N;

		

					//cout << nx << ", " << ny << endl;


					map2[nx][ny].push_back(fire(nx, ny, m, speed, dir));
				}
			}

		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map2[i][j].size() > 1) {
					int sumM = 0;
					int sumS = 0;
					bool odd = false; //È¦¼ö
					bool even = false; //Â¦¼ö
					for (int k = 0; k < map2[i][j].size(); k++) {

						sumM += map2[i][j][k].m;
						sumS += map2[i][j][k].speed;
						if (map2[i][j][k].dir % 2 == 0)
							even = true;
						else
							odd = true;
					}


					sumM = sumM / 5;
					sumS = sumS / map2[i][j].size();


					map2[i][j].clear();
					if (sumM == 0)continue;
					if (odd == true && even == true) {
						map2[i][j].push_back(fire(i, j, sumM, sumS, 1));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 3));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 5));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 7));
					}
					else {
						map2[i][j].push_back(fire(i, j, sumM, sumS, 0));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 2));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 4));
						map2[i][j].push_back(fire(i, j, sumM, sumS, 6));
					}



				}


			}
		}

		copyMap(map, map2);

		//print();

		K--;

		//Áú·® °è»ê
		//if (K != 0) continue;
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < map[i][j].size(); k++) {
					if (map[i][j][k].m > 0)
						ans += map[i][j][k].m;
				}
			}
		}

		if (ans == 0) break;

	}

	cout << ans << endl;

}