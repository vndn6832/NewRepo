#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int cnt = 0;
	string st[7] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
	if (a == 1) {
		cnt = b - 1;
	}
	else if (a == 2) {
		cnt = 31 + b - 1;
	}
	else if (a == 3) {
		cnt = 31 + 29 + b - 1;

	}
	else if (a == 4) {
		cnt = 31 + 29 + 31 + b - 1;
	}
	else if (a == 5) {
		cnt = 31 + 29 + 31 + 30 + b - 1;
	}
	else if (a == 6) {
		cnt = 31 + 29 + 31 + 30 + 31 + b - 1;
	}
	else if (a == 7) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + b - 1;
	}
	else if (a == 8) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + 31 + b - 1;
	}
	else if (a == 9) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + b - 1;
	}
	else if (a == 10) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + b - 1;
	}
	else if (a == 11) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + b - 1;
	}
	else if (a == 12) {
		cnt = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + b - 1;
	}
	cnt = cnt % 7;
	answer = st[cnt];
	return answer;


}