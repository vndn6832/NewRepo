#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == ' ') {
			answer += " ";
		}
		else {

			if (s[i] >= 'A' && s[i] <= 'Z') {
				char ch = s[i] + n;
				if (ch > 'Z') {
					answer += ch - 26;
				}
				else {
					answer += ch;
				}
			}
			else {
				int tmp = (int)s[i] + n;
				//out of range
				if (tmp > (int)'z') {
					answer += s[i] + n - 26;
				}
				else {
					answer += s[i] + n;
				}
			}
		}
	}
	return answer;
}

int main() {
	cout << solution("AB", 1) << " : " << "BC" << endl;
	cout << solution("z", 1) << " : " << "a" << endl;
	cout << solution("a B z",4) << " : " << "e F d" << endl;
}