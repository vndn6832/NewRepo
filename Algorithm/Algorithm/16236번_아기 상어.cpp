#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N;
int map[20][20];
struct shark {
	int x;
	int y;
	int size;
	int cnt;
};
struct info
{
	int x;
	int y;
	int dis;
	info(int a, int b, int c) {
		x = a;
		y = b;
		dis = c;
	}

};
struct compare {
	bool operator()(info& i1, info& i2) {
		if (i1.dis == i2.dis) {
			if (i1.x == i2.x) {
				return i1.y > i2.y;
			}

			return i1.x > i2.x;

		}
		return i1.dis > i2.dis;
	}
};
shark s;
priority_queue<info, vector<info>, compare> pq;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int ans = 0;
bool check[20][20];

int main(){

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s.x = i;
				s.y = j;
				s.size = 2;
				s.cnt = 0;
				map[i][j] = 0;
			}
		}
	}

	pq.push(info(s.x, s.y, 0));
	check[s.x][s.y] = true;
	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int d = pq.top().dis;
		pq.pop();

		if (map[x][y] != 0 && map[x][y] < s.size) {
			map[x][y] = 0;
			s.x = x;
			s.y = y;
			s.cnt += 1;
			if (s.cnt == s.size) {
				s.size += 1;
				s.cnt = 0;
			}
			ans += d;
			//cout << d << endl;
			memset(check, false, sizeof(check));
			while (!pq.empty())
			{
				pq.pop();
			}
			d = 0; //***

		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] > s.size) continue;
			if (check[nx][ny] != true) {
				check[nx][ny] = true;
				pq.push(info(nx, ny, d + 1));
				//cout << "***" << " x: " << nx << ", " << " y: " << ny << " => " << d+1 << endl;
			}
		}
	}
	cout << ans << endl;
}