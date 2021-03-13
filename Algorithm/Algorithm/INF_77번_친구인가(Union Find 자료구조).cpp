#include<iostream>
using namespace std;
int unf[1001];
int Find(int v) { //v�� ���չ�ȣ return
	if (v == unf[v]) return v;
	else return Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}
int main() {
	int n, m, a, b, fa, fb;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		unf[i] = i; //�ʱ�ȭ
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	cin >> a >> b;
	fa = Find(a);
	fb = Find(b);
	if (fa == fb) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}