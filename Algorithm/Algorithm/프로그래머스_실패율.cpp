#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int cnt[502];
struct info {
	int stage;
	double rate;
	info(int a, double b) {
		stage = a;
		rate = b;
	}
};
bool compare(info i1, info i2) {
	if (i1.rate == i2.rate)
		return i1.stage < i2.stage;
	else
		return i1.rate > i2.rate;
}
vector<info> v;
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++) {
		cnt[stages[i]]++;
	}

	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			v.push_back(info(i, 0));
			continue;
		}
		//cout << "* "<<cnt[i] <<", "<<stages.size()- tmp << endl;
		double rate = (double)cnt[i] / (double)(stages.size() - tmp);//***나누기
		//cout << "=> " <<rate << endl;
		tmp += cnt[i];
		v.push_back(info(i, rate));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		//cout << v[i].stage << ", "<<v[i].rate << endl;
		answer.push_back(v[i].stage);
	}

	return answer;
}

int main() {
	vector<int> ans;
	ans = solution(5, { 2,1,2,6,2,4,3,3 });
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}