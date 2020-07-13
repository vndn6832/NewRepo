#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> node[32001];
int inDegree[32001];
int result[32001];
int n;
int m;
void sort() {
	queue<int> q;
	//진입차수가 0인거 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		result[i]=x;
		for (int i = 0; i < node[x].size(); i++) {
			int val = node[x][i];
			if (--inDegree[val] == 0) {
				q.push(val);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}


}
int main() {
	
	cin >> n >> m;
	


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
	    
		node[a].push_back(b);
		inDegree[b]++;
		

	}
	
	sort();


}