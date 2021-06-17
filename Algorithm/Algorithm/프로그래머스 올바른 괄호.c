#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
	bool answer = true;
	int left = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (*(s + i) == '(') {
			left++;
		}
		else {
			left--;
		}
		if (left < 0) {
			answer = false;
			break;
		}
	}
	if (left != 0)
		answer = false;
	return answer;
}