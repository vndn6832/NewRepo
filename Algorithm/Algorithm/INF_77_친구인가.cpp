#include<iostream>
using namespace std;
int n, m;
int map[1001][1001];
bool check[1001];
int f1, f2;
bool ans = false;
int friends(int v) {
	if (v == f2) {
		ans = true;
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && check[i] != true) {
				check[i] = true;
				friends(i);
				check[i] = false;
			}
		}

	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}


	cin >> f1 >> f2;
	friends(f1);
	if (ans==true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}