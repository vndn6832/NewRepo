#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int N, M;
int map[50][50];
vector <pair< int, int >> tmp;
vector <pair<int, int>> house;
bool check[13];
int minVal = INT_MAX;
void dis(vector<pair<int, int>> store) {
	int ret = 0;
	for (int i = 0; i < house.size(); i++) {
		int dis = INT_MAX;
		for (int j = 0; j < store.size(); j++) {
			int temp = abs(house[i].first - store[j].first) + abs(house[i].second - store[j].second);
			if (temp < dis)
				dis = temp;
			//cout << "dis "<<dis << endl;
		}
		ret += dis;
	}


	if (ret < minVal)
		minVal = ret;
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
			}
		}
	}

	DFS(0, 0);

	cout << minVal << endl;
}
