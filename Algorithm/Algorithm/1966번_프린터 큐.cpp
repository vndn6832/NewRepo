#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first != b.first) {
			return a.first < b.first;
		}
		else {
			return a.second >= b.second;
		}
	}
};
priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> pq;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {

		int n, m;
		cin >> n >> m;

		for (int j = 0; j < n; j++) {
			int x = 0;
			cin >> x;
			pq.push(make_pair(x, j));
		}

		int print = 0;
		int order = 0;
		while (!pq.empty())
		{
			order++;
			if (pq.top().second == m) {
				print = order;
			}
			pq.pop();
		}
		cout << print << endl;


	}
}