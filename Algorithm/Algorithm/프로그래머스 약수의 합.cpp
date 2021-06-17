#include <string>
#include <vector>
#include<cmath>
#include<iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		//cout << i;
		if (i == sqrt(n)) {
			answer += i;
			continue;
		}
		if (n % i == 0) {
			answer += i;
			answer += (n / i);
		}
	}
	return answer;
}