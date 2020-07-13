#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {

		int n, m;
		int order = 0;
		cin >> n >> m;

		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			q.push({ x, j });
			pq.push(x);
		}

		
		while (!q.empty())
		{
			int nowIdx = q.front().second;
			int nowVal = q.front().first;


			if (nowVal == pq.top()) {
				//q.pop();
				pq.pop();
				order++;
				if (nowIdx == m) {
					cout << order << endl;
					break;
				}
			}
			else {
				//q.pop();
				q.push(make_pair(nowVal, nowIdx));
			}

			q.pop();
			
		}
		
		
		

	}
}