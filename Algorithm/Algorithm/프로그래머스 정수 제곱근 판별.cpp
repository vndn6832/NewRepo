#include <string>
#include <vector>
#include<cmath>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long tmp = 0;

	tmp = sqrt(n);
	if (pow(tmp, 2) != n)
		return -1;
	answer = pow(tmp + 1, 2);
	return answer;
}