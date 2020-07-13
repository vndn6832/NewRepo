#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int n;
	int m;
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	int val[32001] = {0,};


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
	
		pq.push({ val[a],a });
		pq.push({val[a]+1,b });

	}
	int preVal = 0;
	while (!pq.empty()) {
		int nowVal = pq.top().second;
		if(nowVal != preVal)
			cout << nowVal << " ";
		pq.pop();
		preVal = nowVal;

	}


}