#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

struct pos {
	int idx;
	int value;
	pos(int a, int b) {
	    idx = a;
		value = b;
	}
};
priority_queue<int> pq;
queue<pos> q;


int main() {
	int answer = 0;
	vector<int> priorities;
	priorities.push_back(2);
	priorities.push_back(1);
	priorities.push_back(3);
	priorities.push_back(2);
	int location = 2;
	cout << answer << endl;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(pos(i, priorities[i]));
	}
	int order = 0;
	cout << q.size() << endl;
	while (!q.empty()) {
		//cout << "hi" << endl;
		int i = q.front().idx;
		int v = q.front().value;

		q.pop();

		if (v == pq.top() ){
			pq.pop();
			order++;
				if (i == location) {
					answer = order;

						break;
				}
		}
		else {
			q.push(pos(i, v));
		}
	}
	
	
	cout << answer << endl;
}
