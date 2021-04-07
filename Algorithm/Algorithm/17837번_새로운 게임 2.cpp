#include<iostream>
#include<vector>
using namespace std;
int N, K;
int map[12][12];
struct info {
	int x;
	int y;
	int dir;
	info(int a, int b, int c) {
		x = a;
		y = b;
		dir = c;
	}
};
vector<info> v; //말
vector<int> map2[12][12];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans = 1;
int numChk(int x, int y, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (map2[x][y][i] == num)
			return i;
	}
}
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 1; i <= K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(info(a - 1, b - 1, c - 1));
		map2[a - 1][b - 1].push_back(i);

	}

	while (1) {
		//말 이동

		for (int i = 0; i < v.size(); i++) {
			vector<int> tmp; //움직일 말들
			int x = v[i].x;
			int y = v[i].y;
			int dir = v[i].dir;

			//위에 말 있는지 찾기
			int mSize = map2[x][y].size();

			if (mSize > 1) {
				int num = numChk(x,y,mSize,i+1);

				if (num == mSize - 1) {//가장 위에 있는 경우
					tmp.push_back(i + 1);
				}
				else {

					for (int n = num; n < mSize; n++) {
						tmp.push_back(map2[x][y][n]);
					}

				}

			}
			else {
				//1이면 그 칸에, 그 말만 있는 경우
				tmp.push_back(i + 1);
			}

			

		}



		//4개 이상 쌓인게 있는지 확인

		ans++;
		if (ans > 1000) break;
	}

	if (ans > 1000) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	
}