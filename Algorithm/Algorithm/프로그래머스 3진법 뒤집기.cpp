#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	string tmp = "";
	while (n > 0) {
		tmp += to_string(n % 3);
		n /= 3;
	}

	//cout << tmp << endl;

	for (int i = tmp.size() - 1; i >= 0; i--) {
		answer += ((int)tmp[i] - '0') * pow(3, tmp.size() - i - 1);
	}

	return answer;
}