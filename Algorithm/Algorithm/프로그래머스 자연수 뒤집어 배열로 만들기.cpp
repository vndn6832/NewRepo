#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	string st;
	st = to_string(n);
	for (int i = st.size() - 1; i >= 0; i--) {
		answer.push_back(st[i] - '0');
	}
	return answer;
}