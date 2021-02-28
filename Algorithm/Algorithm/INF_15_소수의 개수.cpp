#include<stdio.h>
int main() {
	int num, res=0;
	scanf_s("%d", &num);

	for (int i = 2; i <= num; i++) {
		bool flag = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}

		if (flag == true) res++;

	}

	printf("%d", res);

}