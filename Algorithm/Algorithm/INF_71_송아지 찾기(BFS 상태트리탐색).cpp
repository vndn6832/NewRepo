#include<iostream>
#include<queue>
using namespace std;
int S, E;
int ch[10001];
int d[3] = { 1,-1,5 };
queue<int> q;
int main() {
	cin >> S >> E;

	q.push(S);
	ch[S] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int nx = x + d[i];
			if (nx <= 0 || nx > 10000) continue;
			if (nx == E) {
				cout << ch[x] << endl;
				return 0;
			}
			if (ch[nx] == 0) {
				ch[nx] = ch[x] + 1;
				q.push(nx);
			}
		}
	}
}
