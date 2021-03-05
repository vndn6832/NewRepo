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


		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
		if (q.size() == 1) {
			cout << q.front() << endl;
			q.pop();


		}


	}
}
