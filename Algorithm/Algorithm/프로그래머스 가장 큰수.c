#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>
size_t s_size = 0;
void my_strcpy(char* arr, const int* n1, const int* n2) {
	char temp[8] = "";
	sprintf(temp, "%d", *n1);
	strcat(arr, temp);

	sprintf(temp, "%d", *n2);
	strcat(arr, temp);
}
int compare(const int* a, const int* b) {
	char ab[9] = ""; //한 원소 최대값이 1000이므로 4글자+4글자+null문자로 9
	char ba[9] = "";
	char* ap = ab;
	char* bp = ba;

	my_strcpy(ab, a, b);//두 원소 순서를 바꿔 문자열로 만들기
	my_strcpy(ba, b, a);//아래 while문에서 strcmp처럼 아스키코드 순서를 알아냄
	s_size += strlen(ab);

	while (*ap == *bp && *ab != 0) {
		ap++;
		bp++;
	}

	if (*ap == *bp) {
		return 0;
	}
	return *ap > * bp ? -1 : 1;
}
char* solution(int numbers[], size_t numbers_len) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	char* answer;
	size_t i = 0;
	char temp[4] = ""; //배열 한 원소의 최대 자릿수는 4자리
	qsort(numbers, numbers_len, sizeof(int), compare);

	if (*numbers == 0) {//정렬 후 맨 앞의 원소 값이 0이면? 원소 전부 다 0이니 0 반환
		answer = (char*)malloc(sizeof(char) * 2);
		//answer[0] = '0';
		//answer[1] = '\0';
		answer = "0";
		return answer;

	}

	answer = (char*)malloc(sizeof(char) * (s_size + 1));
	*answer = 0; //초기화

	for (i = 0; i < numbers_len; i++) {
		sprintf(temp, "%d", numbers[i]);
		strcat(answer, temp);//문자열 붙이기
	}

	return answer;
}