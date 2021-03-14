//Union&Find È°¿ë
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E;
int unf[101];
struct info {
	int v1;
	int v2;
	int val;
	info(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
};
vector<info> v;
int res = 0;
bool compare(info i1, info i2) {
	return i1.val < i2.val;
}
int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	cin >> V >> E;
	int a, b, c;
	for (int i = 1; i <= V; i++) {
		unf[i] = i;
	}
	
	for (int i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		v.push_back(info(a, b, c));

	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		int fa = Find(v[i].v1);
		int fb = Find(v[i].v2);
		if (fa != fb) {
			res += v[i].val;
			Union(v[i].v1, v[i].v2);
		}
	}

	cout << res << endl;
	return 0;
}