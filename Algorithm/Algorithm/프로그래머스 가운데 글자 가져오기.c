#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> //���ڿ�
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	char* answer;
	int len = strlen(s); //���ڿ� ����
	if (len % 2 == 1) {
		answer = (char*)malloc(sizeof(char) * 2); //1���� �ε� ������ �� �ʿ�
		answer[0] = s[len / 2];
		answer[1] = '\0'; //���ڿ� �� ��
	}
	else {
		answer = (char*)malloc(sizeof(char) * 3);//2���� �ϱ�
		answer[0] = s[len / 2 - 1];
		answer[1] = s[len / 2];
		answer[2] = '\0'; //���ڿ� �� ��
	}

	return answer;
}