#include<iostream>
#include<cstring>
using namespace std;
int m, n, k;
bool check[50][50];
int map[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;
void dfs(int x, int y) {
	if (check[x][y] == true) return;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n || check[nx][ny] == true || map[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		memset(check, false, sizeof(check));
		memset(map, 0, sizeof(map));
		cnt = 0;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (map[a][b] == 1 && check[a][b] == false) {
					dfs(a, b);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	        
	}
	
	
}