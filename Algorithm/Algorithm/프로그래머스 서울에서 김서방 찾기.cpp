#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
string solution(vector<string> seoul) {
	string answer = "";
	int pos;

	/*
	//1
	for (int i = 0; i < seoul.size(); i++) {
		if (seoul[i] == "Kim") {
			pos = i;
			break;
		}
	}
	*/

	//2
	pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();

	answer += "김서방은 ";
	answer += to_string(pos);
	answer += "에 있다";
	return answer;
}

int main() {
	cout << solution({ "Jane", "Kim" }) << endl;
}