#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<cstring>
using namespace std;
int N, M;
int map[50][50];
vector<pair<int, int> > virus;
bool check[10];
bool check2[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans = INT_MAX;
int zero = 0;
int spread = 0;
void cpy(int a[50][50], int b[50][50]) {  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}
int cal() {
	int time = 0;
	queue<pair<int, int> > q;
	for (int i = 0; i < virus.size(); i++) {
		if (check[i] == true) {
			q.push(make_pair(virus[i].first, virus[i].second));
			map[virus[i].first][virus[i].second] = 0;
			check2[virus[i].first][virus[i].second] = true;
			//cout <<"* "<< virus[i].first << " " <<virus[i].second << endl;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (check2[nx][ny] == false && map[nx][ny] != 1) {
				check2[nx][ny] = true;
				q.push(make_pair(nx, ny));

				//////////////////////
				if (map[nx][ny] == 0) {
					spread++;

					if (map[x][y] + 1 > time)
						time = map[x][y] + 1;
				}
				///////////////////////
				map[nx][ny] = map[x][y] + 1;
			}
		}
	}
	return time;
}
void DFS(int idx, int cnt) {
	if (cnt == M) {
		int map2[50][50];
		cpy(map2, map);
		spread = 0;

		int tmp = cal();
		memset(check2, false, sizeof(check2));
		//cout << tmp << endl;
		//cout << zero << " "<< spread << " "<<zero-spread << " " << M << endl;
		if (zero == spread && tmp < ans) { 
			//cout << "same" << endl;
			ans = tmp;
		}
		cpy(map, map2);

	}
	else {
		for (int i = idx; i < virus.size(); i++) {
			if (check[i] != true) {
				check[i] = true;
				DFS(i, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
			if (map[i][j] == 0)
				zero++;
		}
	}

	if (zero == 0) {


		cout << 0 << endl;
		return 0;
	}
	DFS(0, 0);

	if (ans == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}
