#include<iostream>
#include<queue>
using namespace std;

int check[100][100] = { 0, };
int ex[100][100];
int m, n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1, 0, - 1 };
void bfs(int a, int b) {
	queue<pair<int, int>> q;

	q.push(make_pair(a, b));
	check[a][b] = 1;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (x2 >= m || y2 >= n || x2 < 0 || y2 < 0) continue;
			if (check[x2][y2] == 0 && ex[x2][y2] == 1) {
				q.push(make_pair(x2, y2));
				ex[x2][y2] = ex[x][y] + 1;
				check[x2][y2] = 1;
				if (x2 == m-1 && y2 == n-1) {
					cout << ex[x2][y2] << endl;
					break;
				}
			}

		}
	}

	
}
int main() {
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			scanf_s("%1d", &ex[i][j]);
			
		}
	}

	bfs(0, 0);

}