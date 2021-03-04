#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int N, M;
int map[8][8];
int ans = 0;
struct camera {
	int x;
	int y;
	int val;
	camera(int a, int b, int c) {
		x = a;
		y = b;
		val = c;
	}
};
vector<camera> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void cpy(int tmp1[8][8], int tmp2[8][8]) { 
	//cout << "ccc" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp1[i][j] = tmp2[i][j];
		}
	}
}
void check(int x, int y, int dir) { //감시되는 공간 체크
	int nx = x;
	int ny = y;
	int d = dir % 4;
	while (1) {
		nx += dx[d];
		ny += dy[d];
		//cout << nx << " " << ny << endl;
		if (map[nx][ny] == 6) break;
		if (map[nx][ny] >= 1 && map[nx][ny] <= 5) continue;
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		//cout << nx << " " << ny << endl;
		map[nx][ny] = -1;
		
	}
}
void DFS(int val) {

	//cout << "val: " << val << endl;;
	if (val == v.size()) {
		//cout << "yo" << endl;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					cnt++;
			}
		}
		if (ans > cnt)
			ans = cnt;
	}
	else {
		int x = v[val].x;
		int y = v[val].y;
		int num = v[val].val;

		int map2[8][8];
		cpy(map2, map);

		//카메라 번호에 따라
		if (num == 1) {
			
			for (int i = 0; i < 4; i++) {
				//cout << 1 << endl;
				check(x, y, i);
				//cout << "checked" << endl;
				DFS(val + 1);
				cpy(map, map2);
				//cout << "copied" << endl;
			}
		}
		else if (num == 2) {

			for (int i = 0; i < 2; i++) {
				check(x, y, i);
				check(x, y, i+2);
				DFS(val + 1);
				cpy(map, map2);
			}
			
		}
		else if (num == 3) {
			for (int i = 0; i < 4; i++) {
				check(x, y, i);
				check(x, y, i + 1);
				DFS(val + 1);
				cpy(map, map2);
			}
		}
		else if (num == 4) {
			for (int i = 0; i < 4; i++) {
				check(x, y, i);
				check(x, y, i + 1);
				check(x, y, i + 2);
				DFS(val + 1);
				cpy(map, map2);
			}
		}
		else if (num == 5) {
			check(x, y, 0);
			check(x, y, 1);
			check(x, y, 2);
			check(x, y, 3);
			DFS(val + 1);
			cpy(map, map2);
			
		}
	}

	
}
int main() {
	cin >> N >> M;
	int zero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				v.push_back(camera(i, j, map[i][j]));
			}
			else if (map[i][j] == 0) {
				ans++;
			}
		}
	}

	if (v.size() > 0) {
		DFS(0);
	}

	cout << ans;

}