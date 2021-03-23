//12:00
#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
struct info {
	int num;
	int time;
};
struct shark {
	int x;
	int y;
	int dir;
	shark(int a, int b, int c) {
		x = a;
		y = b;
		dir = c;
	}
};
info map[20][20];
vector<vector<int>> v;
int cnt;
int ans = 0;
int order[4][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void cal(int num) {
	for (int i = (num-1)*4; i < num*4; i++) {
		for (int j = 0; j < 4; j++) {
			order[i%4][j] = v[i][j]; //order 인덱스 설정 주의
		}
	}
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].num << " --- " << map[i][j].time << "  ";

		}
		cout << endl;
	}
	cout << endl;
}
void copyMap(info map[20][20], info map2[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j].num = map2[i][j].num;
			map[i][j].time = map2[i][j].time;
		}
	}
}
void move(vector<shark> s) {

	while (1) {
		info map2[20][20];
		copyMap(map2,map);
		
		for (int i = 1; i < s.size(); i++) {
			//cout << "상어 " << i << " 시작" << endl;
			if (s[i].dir == -1) continue;
			int x = s[i].x;
			int y = s[i].y;
			int dir = s[i].dir;

			cal(i);
			//cout << "상어 " << i << " 움직임 시작" << endl;
			bool check = false;
			for (int j = 0; j < 4; j++) {
				int nextDir = order[dir][j];
				int nx = x + dx[nextDir];
				int ny = y + dy[nextDir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (map[nx][ny].num != 0) continue;
				check = true;
				
				if (map2[nx][ny].num == 0 || map2[nx][ny].num > i) {
					if (map2[nx][ny].num != 0) {
						cnt--;
						//cout << "먹다" << endl;
						s[map2[nx][ny].num].dir = -1;
					}
					map2[nx][ny].num = i;
					map2[nx][ny].time = K+1; //***

					s[i].x = nx;
					s[i].y = ny;
					s[i].dir = nextDir;
				}
				else if (map2[nx][ny].num < i) {
					cnt--;
					//cout << "먹다 " << endl;
					s[i].dir = -1;
				}
				break;
			}
			
			
			if (check == false) {
				for (int j = 0; j < 4; j++) {
					int nextDir = order[dir][j];
					int nx = x + dx[nextDir];
					int ny = y + dy[nextDir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (map[nx][ny].num != 0 && map[nx][ny].num != i) continue;


					map2[nx][ny].num = i;
					map2[nx][ny].time = K+1; //***

					s[i].x = nx;
					s[i].y = ny;
					s[i].dir = nextDir;

					break;
				}
			}
			//cout << "상어 "<<i <<" 움직임" << endl;
			

		}
		//cout << "hey" << endl;
		//cout << "냄새 줄어들기" << endl;
		//냄새 시간 줄어들기
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				//cout << "hey" << endl;
				if (map2[a][b].num != 0) {
					map2[a][b].time--;
					if (map2[a][b].time == 0) {
						map2[a][b].num = 0;
					}
				}
			}
		}
		//cout << "hey" << endl;
		copyMap(map, map2);
		//print();
		//cout << cnt << endl;
		ans++;
		//cout << cnt << endl;
		if (cnt == 1) break;
		if (ans == 1001) {
			ans = -1;
			break;
		}
	}
}

int main() {
	cin >> N >> M >> K;
	shark t = shark(0, 0, 0);
	vector<shark> s(M+1,t);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j].num;
			if (map[i][j].num != 0) {
				map[i][j].time = K;
				s[map[i][j].num].x = i;
				s[map[i][j].num].y = j;
				s[map[i][j].num].dir = 0;

			}

		}
	}
	cnt = M;
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		s[i].dir = a - 1;
	}

	
	for (int i = 0; i < M*4; i++) {
		vector<int> tmp(4, 0);
		for (int j = 0; j < 4; j++) {
			int b;
			cin >> b;

			tmp[j] = b-1;
		
		}
		v.push_back(tmp);
	}
	
	//print();

	move(s);
	cout << ans << endl;
}