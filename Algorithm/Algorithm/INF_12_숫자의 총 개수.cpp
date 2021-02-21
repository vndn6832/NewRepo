#include<stdio.h>
int main() {
	int num;
	int cnt = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		int a = i;
		while (a > 0) {
			a = a / 10;
			cnt++;
		}
	}
	printf("%d", cnt);
}