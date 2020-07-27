#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int cnt =0 ;
int map[25][25];
bool check[25][25];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ch;
vector<int> ans;
void dfs(int a, int b) {
	if (check[a][b] == true) return;
	check[a][b] = true;

	for (int i = 0; i < 4; i++){ 
		int na = a + dx[i];
		int nb = b + dy[i];
		if (check[na][nb] == true || map[na][nb] != 1 || na < 0 || na >= n || nb < 0 || nb >= n) continue;
		ch++;
		dfs(na, nb);
	}
}
int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] != true) {
				ch = 1;
				dfs(i, j);
				//cout << "ch: " << ch << endl;
				ans.push_back(ch);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}