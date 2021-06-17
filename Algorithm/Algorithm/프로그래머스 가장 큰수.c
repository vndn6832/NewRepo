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
	char ab[9] = ""; //�� ���� �ִ밪�� 1000�̹Ƿ� 4����+4����+null���ڷ� 9
	char ba[9] = "";
	char* ap = ab;
	char* bp = ba;

	my_strcpy(ab, a, b);//�� ���� ������ �ٲ� ���ڿ��� �����
	my_strcpy(ba, b, a);//�Ʒ� while������ strcmpó�� �ƽ�Ű�ڵ� ������ �˾Ƴ�
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
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	char* answer;
	size_t i = 0;
	char temp[4] = ""; //�迭 �� ������ �ִ� �ڸ����� 4�ڸ�
	qsort(numbers, numbers_len, sizeof(int), compare);

	if (*numbers == 0) {//���� �� �� ���� ���� ���� 0�̸�? ���� ���� �� 0�̴� 0 ��ȯ
		answer = (char*)malloc(sizeof(char) * 2);
		//answer[0] = '0';
		//answer[1] = '\0';
		answer = "0";
		return answer;

	}

	answer = (char*)malloc(sizeof(char) * (s_size + 1));
	*answer = 0; //�ʱ�ȭ

	for (i = 0; i < numbers_len; i++) {
		sprintf(temp, "%d", numbers[i]);
		strcat(answer, temp);//���ڿ� ���̱�
	}

	return answer;
}