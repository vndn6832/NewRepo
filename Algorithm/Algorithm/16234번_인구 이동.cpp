#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, L, R;
int map[50][50];
bool check[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
struct info {
	int x;
	int y;
	int val;
	info(int a, int b, int c) {
		x = a;
		y = b;
		val = c;
	}
};
vector<vector<info>> v;
int ans = 0;
bool flag;
void BFS(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	vector<info> list;
	list.push_back(info(x, y,map[x][y]));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			int tmp = abs(map[nx][ny] - map[x][y]);
			if ( tmp >=L && tmp<=R && check[nx][ny] != true) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				list.push_back(info(nx, ny,map[nx][ny]));
				flag = true;
			}
		}
	}
	v.push_back(list);
}
void cal() {
	
	int sum;
	int ret;
	for (int i = 0; i < v.size(); i++) {
		sum = 0;
		for (int j = 0; j < v[i].size(); j++) {
			sum += v[i][j].val;
		}
		ret = sum / v[i].size();
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j].x;
			int y = v[i][j].y;
			map[x][y] = ret;
		}
	}


	v.clear();
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	while (1) {
		int num = 0;
		flag = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] != true) {
					num++;
					check[i][j] = true;
					BFS(i, j, num);
				}
			}
		}

		if (flag == false) break;
		cal();
		//print();
		
		ans++;
	}

	cout << ans << endl;

}