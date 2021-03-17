#include <string>
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;
string s2;

int cal(int length) {
	string ans = "";
	int cnt = 1;
	//cout << "legnth: " <<length << endl;
	string now = "";
	string pre = "";
	for (int i = 0; i < s2.size() - length + 1; i = i + length) {

		pre = now;
		now = "";
		for (int j = i; j < i + length; j++) {
			now += s2[j];
		}
		// cout << pre << ", " << now << endl;
		if (now == pre) {
			cnt++;
		}
		else {

			if (cnt != 1)
				ans += to_string(cnt);
			ans += pre;
			cnt = 1;
		}
		// cout << "===>" << ans << endl;
	}
	if (cnt != 1)
		ans += to_string(cnt);
	ans += now;


	int left = s2.size() % length;
	//cout << "pre ans: " << ans << endl;
	if (left != 0)
		ans += &s2[s2.size() - left];

	//cout << "ans: " << ans << endl;
	return ans.size();

}
int solution(string s) {
	int answer = s.size();
	s2 = s;
	for (int i = 1; i < s.size(); i++) {
		int tmp = cal(i);
		if (answer > tmp)
			answer = tmp;

	}
	return answer;
}

int main() {
	cout << solution("aabbaccc") << endl;
}