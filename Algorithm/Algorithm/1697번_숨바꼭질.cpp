#include<iostream>
#include<queue>
using namespace std;
int check[100001] = { 0, };
int n, k;
void bfs(int x) {
	queue<int> q;

	q.push(x);
	check[x] = 1;
	
	while (!q.empty()) {
		int x1 = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int x2;
			if (i == 0) {
				x2 = x1 + 1;
			}
			else if (i == 1) {
				x2 = x1 - 1;
			}
			else {
				x2 = x1 * 2;
			}

			if (x2 < 0 || x2 >100000) continue;

			if (check[x2] == 0) {
				q.push(x2);
				check[x2] = check[x1] + 1;
				if (x2 == k) {
					cout << check[x2] - 1 << endl;
				}
			}
		}

		

	}
}
int main() {

	cin >> n >> k;

	if (n == k)
		cout << 0 << endl;
	else
		bfs(n);
}