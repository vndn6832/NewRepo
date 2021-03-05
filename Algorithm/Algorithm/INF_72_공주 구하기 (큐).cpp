#include<iostream>
#include<queue>
using namespace std;
int N, K;
queue<int> q;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front() << endl;
			q.pop();


		}
		int x = q.front();
		q.pop();
		cnt++;
		if (cnt == 3) {
			cnt = 0;
		}
		else {
			q.push(x);
		}



	}
}
