#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int answer = 0;
	int res[100001];
	res[0] = 0;
	res[1] = 1;

	for (int i = 2; i <= n; i++) {
		res[i] = (res[i - 2] + res[i - 1]) % 1234567;
	}

	answer = res[n] % 1234567;

	return answer;
}