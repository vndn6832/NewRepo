#include<iostream>
#include<vector>
using namespace std;
int N;
struct info
{
	int x;
	int y;
	int dir;
	int g;
	info(int a, int b, int c, int d) {
		x = a;
		y = b;
		dir = c;
		g = d;
	}
};
bool check[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };//¿À,À§,¿Þ,¾Æ
vector<info> v;
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back(info(a, b, c, d));
	}

	

	for (int i = 0; i < v.size(); i++) {
		
		int x = v[i].x;
		int y = v[i].y;
		int dir = v[i].dir;
		int ge = v[i].g;

		check[x][y] = true;
		
		//cout << x << ", " << y << endl;
		//cout << dir << endl;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		check[nx][ny] = true;
		//cout << nx <<  ", " << ny << endl;
		vector<int> st;

		st.push_back(dir);

		int step = 1;
		while (step <= ge) {
			for (int i = st.size() - 1; i >= 0; i--) {
				int nextDir = (st[i] + 1) % 4;
				st.push_back(nextDir);

				nx = nx + dx[nextDir];
				ny = ny + dy[nextDir];

				if(check[nx][ny] != true)
					check[nx][ny] = true;
				//cout << nx << ", " << ny << endl;
			}
			step++;
		}
	
	}
	
	/*
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			if (check[j][i] == true)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	*/

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (check[i][j] == true && check[i][j + 1] == true && check[i + 1][j] == true && check[i + 1][j + 1] == true)
				ans++;
		}
		
	}
	
	cout << ans << endl;
	return 0;
}