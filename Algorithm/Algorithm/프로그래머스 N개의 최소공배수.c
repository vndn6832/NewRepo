#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int* temp;
int minVal;
void cal(int num1, int num2) {
	minVal = num1 * num2;
	for (int i = 1; i <= 100; i++) {
		int res;

		if (num1 % i == 0 && num2 % i == 0) {
			res = i * (num1 / i) * (num2 / i);
			if (res < minVal)
				minVal = res;
		}
	}

}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
	int answer = 0;
	temp = (int*)malloc(sizeof(int) * arr_len);
	temp = arr;

	if (arr_len == 1)
		answer = arr[0];
	else {
		for (int i = 0; i < arr_len - 1; i++) {
			cal(arr[i], arr[i + 1]);
			arr[i + 1] = minVal;
		}
		answer = arr[arr_len - 1];
	}

	return answer;
}