#include<iostream>
#include<vector>
using namespace std;
int n, m;
bool check[501];
int main() {
	cin >> n >> m;
	vector<int> v[501];
	vector<int> v2;
	check[1] = true;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a != 1 && b != 1) {
			v[a].push_back(b);
			v[b].push_back(a);
		}
		else {
			if (check[a] != true) {
				check[a] = true;
				v2.push_back(a);
			}
			if (check[b] != true) {
				check[b] = true;
				v2.push_back(b);
			}
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v[v2[i]].size(); j++) {
			if (check[v[v2[i]][j]] != true)
				check[v[v2[i]][j]] = true;
		}
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i] == true) {
			//cout << "*** " << i << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}