#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int compare1(const void* one, const void* two) {
	if (*(int*)one > * (int*)two)
		return -1;
	else if (*(int*)one < *(int*)two)
		return 1;
	return 0;
}

int compare2(const void* one, const void* two) {
	if (*(int*)one > * (int*)two)
		return 1;
	else if (*(int*)one < *(int*)two)
		return -1;
	return 0;
}
int solution(int A[], size_t A_len, int B[], size_t B_len) {
	int answer = 0;
	qsort(A, A_len, sizeof(int), compare1);
	qsort(B, B_len, sizeof(int), compare2);

	for (int i = 0; i < A_len; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	for (int i = 0; i < B_len; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");

	for (int i = 0; i < A_len; i++) {
		answer += (A[i] * B[i]);
	}
	return answer;
}