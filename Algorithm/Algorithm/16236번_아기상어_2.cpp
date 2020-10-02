#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int map[20][20];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
struct shark {
	int x;
	int y;
	int cnt;
	int val;
};
bool findFish = true;
shark s;
vector<pair<int, int>> fish;
int ans = 0;
void cal(int c) {
	sort(fish.begin(), fish.end());
	s.x = fish[0].first;
	s.y = fish[0].second;
	map[s.x][s.y] = 0;
	s.cnt++;
	if (s.val == s.cnt) {
		s.cnt = 0;
		s.val++;
	}
	ans += c;
}
void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(s.x, s.y));
	bool check[20][20] = { false, };
	check[s.x][s.y] = true;
	int cnt = 1;
	while (!q.empty()) {
		int qSize = q.size();

		for (int k = 0; k < qSize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				if (check[nx][ny] == false && map[nx][ny] <= s.val) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));

					if (map[nx][ny] < s.val && map[nx][ny] >0) {
						fish.push_back(make_pair(nx, ny));
						findFish = true;
					}
				}
			}

		}
		//���
		if (fish.size() > 0) {

			cal(cnt);
			fish.clear();
			return;
		}
		cnt++;
	}


}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0; //*��� ��ġ ����ϰ�, 0���� ������ֱ�
				s.x = i;
				s.y = j;
				s.cnt = 0;
				s.val = 2;
			}
		}
	}

	while (findFish) //����⸦ �� ������ ���� �ݺ�
	{
		findFish = false;
		
		BFS();
		
		
	}
	cout << ans << endl;
}