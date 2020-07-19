#include<cstdio>

int t;
char s[60];

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%s", s);
		int c = 0;
		for (int j = 0; s[j] && c >= 0; j++) {
			s[j] == '(' ? c++ : c--;
		}
		printf("%s\n", (c != 0 ? "NO" : "YES"));
	}
	return 0;
}