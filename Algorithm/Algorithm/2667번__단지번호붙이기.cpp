#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, map[25][25];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int num = 0;
void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (map[nx][ny] == -1 ) {
			map[nx][ny] = num;
			DFS(nx, ny);
		}

	}
	
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cin >> map[i][j];
			scanf_s("%1d", &map[i][j]);
			if(map[i][j] == 1)
				map[i][j] = -1;
		}
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -1) {
				num++;
				map[i][j] = num;
				DFS(i, j);
			}
		}
	}
	vector<int> cnt(num);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 1) {
				cnt[map[i][j] - 1]++;
			}
		}
	}

	cout << num << endl;

	sort(cnt.begin(), cnt.end());

	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << endl;
	}

}