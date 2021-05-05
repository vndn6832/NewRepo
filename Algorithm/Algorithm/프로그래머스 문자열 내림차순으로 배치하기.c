#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int compare(const void* one, const void* two) {
	if (*(char*)one > * (char*)two)
		return -1;
	else if (*(char*)one < *(char*)two)
		return 1;
	else return 0;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	char* answer = (char*)malloc(sizeof(char) * strlen(s));
	char temp[strlen(s)];
	strcpy(temp, s);
	qsort(temp, strlen(s), sizeof(char), compare);
	strcpy(answer, temp);
	return answer;
}