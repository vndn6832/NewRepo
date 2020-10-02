#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int map[20][20];
int sharkX;
int sharkY;
int sharkVal = 2;
int sharkCnt = 0;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int fishCnt = 0;
bool flag = false;
bool check[20][20];
int ans = 0;
vector<pair<int, int>> fish;
void cal(int t) {
	sort(fish.begin(), fish.end());
	ans += t;
	map[fish[0].first][fish[0].second] = 0;
	sharkX = fish[0].first;
	sharkY = fish[0].second;
	
	sharkCnt++;
	fishCnt--;

	if (sharkCnt == sharkVal) {
		sharkVal++;
		sharkCnt = 0;
	}
	fish.clear();
}
void BFS() {
	queue < pair<int, int> > q;
	q.push(make_pair(sharkX, sharkY));
	
	check[sharkX][sharkY] = true;
	
	int time = 1;

	while (!q.empty()) {
		
		int qSize = q.size();
		
		for (int k = 0; k < qSize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			/*cout << x << endl;
			cout << y << endl;
			cout << fishCnt << endl;
			cout << endl;*/

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (map[nx][ny] <= sharkVal && check[nx][ny] == false) {
					//cout << "지나간다" << endl;
					q.push(make_pair(nx, ny)); //지나갈 수 있다
					check[nx][ny] = true;
					if (map[nx][ny] >= 1 && map[nx][ny] < sharkVal) {
						fish.push_back(make_pair(nx, ny));
						flag = true;
					}
				}
			}

			
		}
		if (fish.size() > 0) {
			cal(time);
			return;
		}
		time++;
	
	}

	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0; //*상어자리 0
				sharkX = i;
				sharkY = j;
			}

			if (map[i][j] >= 1 && map[i][j] <= 6)
				fishCnt++;
		}
	}
	flag = true;
	while (flag) {
		//if (fishCnt == 0) break;
		flag = false;
		memset(check, false, sizeof(check));
		BFS();
	}

	cout << ans << endl;

	
}