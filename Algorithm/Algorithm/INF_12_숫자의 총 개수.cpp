#include<stdio.h>
int main() {
	int num, sum=0, cnt = 1, digit = 9, res = 0;
	scanf_s("%d", &num);
	while (sum + digit < num) {
		sum = sum + digit;
		res = res + (cnt*digit);
		cnt++;
		digit = digit * 10;
	}
	res = res + ((num - sum) * cnt);
	printf("%d", res);
}