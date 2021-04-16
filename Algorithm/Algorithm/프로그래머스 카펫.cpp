#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int cnt = brown + yellow;
	int a, b;
	for (int i = 1; i <= sqrt(cnt); i++) {
		if (cnt % i == 0 && (i - 2) * (cnt / i - 2) == yellow) {
			a = i;
			b = cnt / i;
		}
	}
	answer.push_back(a);
	answer.push_back(b);
	sort(answer.rbegin(), answer.rend());
	return answer;
}