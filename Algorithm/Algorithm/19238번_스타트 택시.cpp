#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct info{
	int x;
	int y;
	int dist;
	info(int a, int b, int c) {
		x = a;
		y = b;
		dist = c;
	}
};

struct compare {
	bool operator()(info& i1, info& i2) {
		if (i1.dist == i2.dist) {
			if (i1.x == i2.x) {
				return i1.y > i2.y;
			}
			return i1.x > i2.x;
		}
		return i1.dist > i2.dist;
	}
};
int N, M, val;
int map[20][20];
int tx, ty;
vector<pair<int, int>> people;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int move(int num) {
	queue<pair<int, int>> q;
	bool check[20][20] = { false, };
	int dist[20][20] = { 0, };

	q.push(make_pair(tx, ty));
	check[tx][ty] = true;
	dist[tx][ty] = 0;


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == people[num].first && y == people[num].second) {
			return dist[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[nx][ny] != -1 && check[nx][ny] != true) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}

	}

	return -1;
}
void bfs() {
	priority_queue<info, vector<info>, compare> pq;
	bool check[20][20] = { false, };
	pq.push(info(tx, ty, 0));
	check[tx][ty] = true;
		 
	while (!pq.empty()) {
		info tmp = pq.top();
		pq.pop();
		int x = tmp.x;
		int y = tmp.y;
		int dist = tmp.dist;

		if (map[x][y] > 0) {

			int num = map[x][y];
			map[x][y] = 0;

			//cout << x << ", " << y << " : " << num << " 번 손님" << endl;
			val -= dist;

			//cout << "픽업 후 연료: " << val << endl;

			if (val <= 0) {
				//cout << "error 1" << endl;
				val = -1;
				break;
			}

			tx = x;
			ty = y;


			int way = move(num);
			val -= way;
			if (way < 0 || val < 0) {
				//cout << "error 2" << endl;
				val = -1;
				break;
			}

			tx = people[num].first;
			ty = people[num].second;

			val += way * 2;

			//cout << "도착지 픽업 후 연료 : " << val << endl;
 
			M--;
			if (M == 0) break;

			dist = 0;

			memset(check, false, sizeof(check));
			
			while (!pq.empty()) pq.pop();

			pq.push(info(tx, ty, 0));
			x = tx;
			y = ty;

		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[nx][ny] != -1 && check[nx][ny] != true) {
				check[nx][ny] = true;
				pq.push(info(nx, ny, dist + 1));

			}
			
		}

	}

}
int main() {
	//while (1) {
		cin >> N >> M >> val;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				cin >> map[i][j];

				if (map[i][j] == 1)
					map[i][j] = -1;
			}
		}

		for (int i = 0; i < M + 1; i++) {
			people.push_back(make_pair(0, 0));
		}


		cin >> tx >> ty;
		tx -= 1;
		ty -= 1;

		for (int i = 1; i <= M; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			map[a - 1][b - 1] = i;
			people[i].first = c - 1;
			people[i].second = d - 1;
		}


		bfs();

		if (M != 0) {
			cout << -1 << endl;
		}
		else
		{
			cout << val << endl;
		}
	//}
}