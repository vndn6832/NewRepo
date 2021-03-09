#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int L, W;
int map[50][50];
int dis[50][50];
vector<pair<int, int> > tmp;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool flag[50][50];
int BFS(int x, int y) {
	int maxVal = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	flag[x][y] = true;

	while (!q.empty()) {

		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= W) continue;

			if (map[nx][ny] == -1 && flag[nx][ny] != true) {
				flag[nx][ny] = true;
				dis[nx][ny] = dis[cx][cy] + 1;
				if (dis[nx][ny] > maxVal)
					maxVal = dis[nx][ny];
				q.push(make_pair(nx, ny));
			}

		}

	}
	return maxVal;

}
int main() {

	cin >> L >> W;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			char ch;
			scanf_s(" %c", &ch); //c앞에 왜 뛰어쓰기? 
			//cout<<ch << " " <<endl;
			if (ch == 'L') {
				tmp.push_back(make_pair(i, j));
				map[i][j] = -1;
			}

		}
	}

	int ans = 0;

	for (int i = 0; i < tmp.size(); i++) {

		int x = tmp[i].first;
		int y = tmp[i].second;

		memset(flag, false, sizeof(flag));
		memset(dis, 0, sizeof(dis));

		int dist = BFS(x, y);
		if (ans < dist)
			ans = dist;



	}

	cout << ans << endl;



}
