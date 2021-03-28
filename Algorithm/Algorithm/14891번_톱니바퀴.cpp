#include<iostream>
#include<vector>
using namespace std;
int map[4][8];
int K;
vector<pair<int, int>> v;
void move(int num, int dir) {
	if (dir == 1) { //시계
		int tmp = map[num][7];
		for (int i = 7; i > 0; i--) {
			map[num][i] = map[num][i - 1];
		}
		map[num][0] = tmp;
	}
	else { //반시계
		int tmp = map[num][0];
		for (int i = 0; i < 7; i++) {
			map[num][i] = map[num][i + 1];
		}
		map[num][7] = tmp;
	}
	//cout << "move" << endl;
}
int cal() { //점수 계산
	int ans = 0;
	if (map[0][0] == 1)
		ans += 1;
	if (map[1][0] == 1)
		ans += 2;
	if (map[2][0] == 1)
		ans += 4;
	if (map[3][0] == 1)
		ans += 8;


	return ans;
}
int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for (int i = 0; i < v.size(); i++) {
		int num = v[i].first - 1;
		int dir = v[i].second;
		bool flag[3] = { false, };

		//톱니 바퀴들 사이 조사
		if (map[0][2] != map[1][6]) {
			flag[0] = true;
		}
		if (map[1][2] != map[2][6]) {
			flag[1] = true;
		}
		if (map[2][2] != map[3][6]) {
			flag[2] = true;
		}

		move(num, dir);

		//왼쪽방향으로
		int left = num;
		int ld = dir;
		while (1) {
			left--;
			ld = -ld;
			if (left < 0) break;

			if (flag[left] == true)
				move(left, ld);
			else
				break;

		}

		//오른쪽방향으로
		int right = num;
		int rd = dir;
		while (1) {
			right++;
			rd = -rd;
			if (right > 3) break;

			if (flag[right - 1] == true)
				move(right, rd);
			else
				break;
		}
	}

	cout << cal() << endl;
}