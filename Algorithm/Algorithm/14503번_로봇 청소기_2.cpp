#include<iostream>
#include<queue>
using namespace std;
int n, m;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int map[50][50];
int a, b, c;
struct robot {
	int r;
	int c;
	int dir;
	robot(int val1, int val2, int val3) {
		r = val1;
		c = val2;
		dir = val3;
	}
};

queue<robot> q;
bool check[50][50];
int cnt = 0;
void BFS() {
	q.push(robot(a, b, c));
	if (map[a][b] == 0) cnt++;
	check[a][b] = true;
	while (!q.empty()) {
		int x = q.front().r;
		int y = q.front().c;
		int dir = q.front().dir;



		bool flag = false;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nd = (dir + 3 -i) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0 && check[nx][ny] != true) {
				//cout << nx << " " << ny << " " << dir << endl;
				flag = true;
				q.push(robot(nx, ny, nd));
				check[nx][ny] = true;
				cnt++;
				break;


			}
		}


		if (flag == false) {
			//방향 유지, 후진
			int nx = x - dx[dir];
			int ny = y - dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0  ) {
				q.push(robot(nx, ny, dir));
			}
		}


	}
}
int main() {
	cin >> n >> m;

	cin >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	BFS();
	cout << cnt << endl;
}