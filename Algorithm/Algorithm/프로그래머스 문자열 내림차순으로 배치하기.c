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
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	char* answer = (char*)malloc(sizeof(char) * strlen(s));
	char temp[strlen(s)];
	strcpy(temp, s);
	qsort(temp, strlen(s), sizeof(char), compare);
	strcpy(answer, temp);
	return answer;
}