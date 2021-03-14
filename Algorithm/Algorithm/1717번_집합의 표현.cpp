#include<stdio.h>
using namespace std;
int n, m;
int unf[1000001];
int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}
void Union(int b, int c) {
	b = Find(b);
	c = Find(c);
	if (b != c) unf[b] = c;
}
int main() {
	scanf_s("%d %d", &n, &m);
	int a, b, c, fb, fc;
	for (int i = 1; i <= n; i++) {
		unf[i] = i;
	}

	for (int i = 0; i < m; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		if (a == 0) {
			//fb = Find(b);
			//fc = Find(c);
			//if (fb != fc) {
			//	Union(b, c);
			//}
			Union(b, c);
		}
		else {
			fb = Find(b);
			fc = Find(c);
			if (fb == fc)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}