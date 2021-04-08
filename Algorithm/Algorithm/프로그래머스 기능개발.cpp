#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
queue<int> q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++) {
		int p = progresses[i];
		int s = speeds[i];

		int res = (100 - p) / s;
		if ((100 - p) % s != 0) res += 1;

		q.push(res);
	}

	while (!q.empty()) {
		int val = q.front();
		q.pop();
		int cnt = 1;
		while (1) {
			int val2 = q.front();
			if (val < val2 || q.empty()) break; //비는지 확인
			q.pop();
			cnt++;
		}
		answer.push_back(cnt);
	}

	return answer;
}

