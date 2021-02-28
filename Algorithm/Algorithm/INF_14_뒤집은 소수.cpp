#include<stdio.h>
#include<math.h>
int reverse(int x) {
	int res = 0, tmp;
	while (x > 0) {
		tmp = x % 10;
		res = res * 10 + tmp;
		x = x / 10;
	}

	return res;
}

int isPrime(int x) {
	if (x == 1) return false;
	bool flag = true;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			flag = false;
			break;
		}
	}

	return flag;
}
int main() {
	FILE* p_file;
	freopen_s(&p_file,"INF_14.txt", "rt",stdin);
	int n, num, tmp;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		tmp = reverse(num);
		if (isPrime(tmp))
			printf("%d ", tmp);
	}

}