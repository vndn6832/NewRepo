#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n;
int x, y;
int m;
vector<int> family[101];
int ans = -1;
bool check[101];
void DFS(int idx, int next, int cnt) {
	if (next == y) {
		if (cnt > ans)
			ans = cnt;
	}
	else {
		for (int i = 0; i < family[next].size(); i++) {
			if (check[family[next][i]] != true) {
				check[family[next][i]] = true;
				//cout << next << endl;
				DFS(next, family[next][i], cnt + 1);
				check[family[next][i]] = false;
			}
		}
	}

}
int main() {
	cin >> n;
	cin >> x >> y;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		family[a].push_back(b);
		family[b].push_back(a);
	}

	for (int i = 0; i < family[x].size(); i++) {
		memset(check, false, sizeof(check));
		check[x] = true; //***
		check[family[x][i]] = true; //***
		DFS(x, family[x][i], 1);
		if (ans != -1) {
			break;
		}
	}


	cout << ans << endl;
}