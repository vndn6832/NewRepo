#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
	long long answer = 0;
	int num1 = a < b ? a : b;
	int num2 = a < b ? b : a;
	for (int i = num1; i <= num2; i++) {
		answer += i;
	}
	return answer;
}