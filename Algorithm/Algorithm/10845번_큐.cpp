#include <iostream>
#include <string>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	int N; //테스트 케이스 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		if (st == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (st == "pop") {
			if (q.empty() == 0) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (st == "size") {
			cout << q.size() << endl;
		}
		else if (st == "empty") {

			cout << q.empty() << endl;

		}
		else if (st == "front") {
			if (q.empty() == 0) {
				cout << q.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (st == "back") {
			if (q.empty() == 0) {
				cout << q.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}

	}


}