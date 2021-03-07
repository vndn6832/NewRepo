#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int N, M;
int map[50][50];
vector <pair< int, int >> tmp;
vector <pair<int, int>> house;
vector <int> dist;
bool check[13];
int minVal = INT_MAX;
void dis( vector<pair<int, int>> store) {

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < store.size(); j++) {
			int dis = abs(house[i].first - store[j].first) + abs(house[i].second - store[j].second);
			if (dis < dist[i])
				dist[i] = dis;
			//cout << "dis "<<dis << endl;
		}
	}

	int sum = 0;
	for (int i = 0; i < dist.size(); i++) {
		sum += dist[i];
	}

	if (sum < minVal)
		minVal = sum;
}
void init() {
	for (int i = 0; i < house.size(); i++) {
		dist[i] = INT_MAX;
	}
}
void DFS(int idx, int cnt) {
	if (cnt == M) {
		vector<pair<int, int>> store;
		for (int i = 0; i < tmp.size(); i++) {
			if (check[i] == true) {
				store.push_back(make_pair(tmp[i].first, tmp[i].second));
			}
		}
		//cout << store.size() << endl;
		//dist º¤ÅÍ ÃÊ±âÈ­
		init();
		dis(store);
	}
	else {
		for (int i = idx; i < tmp.size(); i++) {
			if (check[i] == false) {
				check[i] = true;
				DFS(i + 1, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				tmp.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
				dist.push_back(INT_MAX);
			}
		}
	}

	DFS(0, 0);

	cout << minVal << endl;
}

