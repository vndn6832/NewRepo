#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N;
struct info {
	int money;
	int when;
	info(int a, int b) {
		money = a;
		when = b;
	}
};
bool compare(info in1, info in2) {
	return in1.when > in2.when;
}
vector<info> v;
priority_queue<int> pq;
int main() {
	int ans = 0;
	cin >> N;
	int time = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(info(a, b));
		if (b > time)
			time = b; //마지막 강연할 날짜
	}
	sort(v.begin(), v.end(), compare);
	int j = 0; //j 한번만 초기화
	for (int i = time; i >= 1; i--) { //강연하는 날짜 - 뒤에서 부터
		for (; j < N; j++) {
			if (v[j].when < i) break; //못하는 강의
			pq.push(v[j].money);
		}
		if (!pq.empty()) {
			cout <<"money: "<< pq.top() << endl;
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
}