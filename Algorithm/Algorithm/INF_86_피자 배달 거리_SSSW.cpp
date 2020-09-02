#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;
int n, m;
int map[50][50];
vector< pair<int, int>> pizza;
vector< pair<int, int>> house;
int ch[12];
int min = INT_MAX;
int count() {
	int cnt = 0;
	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		int minHouse = INT_MAX;
		for (int j = 0; j < m; j++) {
			int x2 = pizza[ch[j]].first;
			int y2 = pizza[ch[j]].second;

			int res = abs(x - x2) + abs(y - y2);
			if (res < minHouse) minHouse = res;
		}
		cnt += minHouse;
	}

	return cnt;
}
void DFS(int S,int L) {
	if (L == m) {
		if (min > count()) min = count();
	}
	else {
		for (int i = S; i < pizza.size(); i++) {
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				pizza.push_back(make_pair(i, j));
			}
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}

		}
	}
	
	DFS(0,0);

	cout << min << endl;
}